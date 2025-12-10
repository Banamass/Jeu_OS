#include "EcranBochs.h"

#include <hal/fonctionsES.h>
#include <hal/pci.h>
#include <sextant/types.h>
#include <drivers/Ecran.h>

ui8_t* EcranBochs::VRAM;

EcranBochs::EcranBochs(ui16_t width, ui16_t height, VBE_MODE mode): width(width), height(height), mode(mode), topBuffer(false), framebuffer(VRAM) {

}

void EcranBochs::init() {
    Ecran e;
    ui16_t detectScreen = lireRegistre(VBE_INDEX::ID);

    if (detectScreen != 0xB0C5) {
        // error should print to serial port ?
        e.afficherMot("No card found");
    }

    // disable card
    ecrireRegistre(VBE_INDEX::ENABLE, VBE_DISPI_DISABLED);

    // set size & bit depth
    ecrireRegistre(VBE_INDEX::XRES, width);
    ecrireRegistre(VBE_INDEX::YRES, height);
    ecrireRegistre(VBE_INDEX::BPP, mode);

    // set virtual width for double buffering
    ecrireRegistre(VBE_INDEX::VIRT_WIDTH, width);
    ecrireRegistre(VBE_INDEX::X_OFFSET, 0);
    ecrireRegistre(VBE_INDEX::Y_OFFSET, 0);

    // enable screen
    ecrireRegistre(VBE_INDEX::ENABLE, VBE_DISPI_ENABLED | VBE_DISPI_LFB_ENABLED);
}

void EcranBochs::swapBuffer() {
    ecrireRegistre(VBE_INDEX::Y_OFFSET, topBuffer ? 0 : height);

    if (!topBuffer) {
        framebuffer = VRAM;
    }
    else {
        framebuffer = VRAM + width * height * bytesPerPixel();
    }

    topBuffer = !topBuffer;
}

void EcranBochs::clear(ui8_t color) {
    for (ui16_t y = 0; y < height; y++) {
        for (ui16_t x = 0; x < width; x++) {
            paint(x, y, color);
        }
    }
}

void EcranBochs::clear(ui8_t r, ui8_t g, ui8_t b) {
    for (ui16_t y = 0; y < height; y++) {
        for (ui16_t x = 0; x < width; x++) {
            paint(x, y, r, g, b);
        }
    }
}

ui16_t EcranBochs::getWidth() {
    return width;
}

ui16_t EcranBochs::getHeight() {
    return height;
}

void EcranBochs::set_palette(ui8_t palette_vga[256][3]) {
    ecrireOctet(0, 0x3C8);
    for (int i = 0; i < 256; ++i) {
        ecrireOctet(palette_vga[i][0], 0x3C9);
        ecrireOctet(palette_vga[i][1], 0x3C9);
        ecrireOctet(palette_vga[i][2], 0x3C9);
    }
}



void EcranBochs::paint(unsigned int x, unsigned int y, char color) {
    if (mode == VBE_MODE::_8) {
        ui32_t offset = y * width + x; 
        framebuffer[offset] = color;
    }
}

void EcranBochs::paint(unsigned int x, unsigned int y, ui8_t r, ui8_t g, ui8_t b) {

    switch (mode)
    {
    case _8:
        break;

    case _15:
    case _16: {
        ui16_t color =    ((r & 0x1F ) << (9 + (mode == _16))) 
                        | ((g & (mode == _16 ? 0x3F : 0x1F) ) << 4)
                        | (b & 0x1F); 
        ((ui16_t*)framebuffer)[x + width * y] = color;
        break;
    }
    
    case _24:
        framebuffer[    x + 3 * width * y] = b;
        framebuffer[1 + x + 3 * width * y] = g;
        framebuffer[2 + x + 3 * width * y] = r;
        break;

    case _32:
        ((ui32_t*) framebuffer)[x + width * y] = (r << 16) | (g << 8) | b; 
        break;
    }
}

void EcranBochs::plot_square(int x, int y, int size, ui8_t color) {
    for (int row = 0; row < size; row++) {
        ui32_t base = (y + row) * width + x;
        for (int col = 0; col < size; col++) {
            framebuffer[base + col] = color;
        }
    }
}

void EcranBochs::plot_square(int x, int y, int size, ui8_t r, ui8_t g, ui8_t b) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            paint(x + col, y + row, r, g, b);
        }
    }
}

void EcranBochs::plot_palette(int x, int y, int size) {
    int row, col;
    for (row = 0; row < 16; row++) {
        for (col = 0; col < 16; col++) {
            plot_square(x+col*size,y+row*size,size,row*16+col);
        }
    }
}


void EcranBochs::plot_sprite(void* buffer, ui16_t width, ui16_t height, ui16_t x, ui16_t y) {
    switch (mode)
    {
    case _8: {
        ui8_t * buf = (ui8_t*)buffer;
        for (ui16_t row = 0; row < height; row++) {
            ui32_t base = (y + row) * getWidth() + x;
            for (ui16_t col = 0; col < width; col++) {
                ui8_t color = *buf++;
                if (color != 0) {
                    framebuffer[base + col] = color;
                }
            }
        }
    }
        break;

    case _15:
    case _16: {
        ui16_t * buf = (ui16_t*)buffer;
        for (ui16_t row = 0; row < height; row++) {
            ui32_t base = (y + row) * getWidth() + x;
            for (ui16_t col = 0; col < width; col++) {
                ui16_t color = *buf++;
                if (color != 0) {
                    ((ui16_t*)framebuffer)[base + col] = color;
                }
            }
        }
    }
        break;

    case _24: {
        ui8_t * buf = (ui8_t*)buffer;
        for (ui16_t row = 0; row < height; row++) {
            ui32_t base = ((y + row) * getWidth() + x ) * 3;
            for (ui16_t col = 0; col < width; col++) {
                ui8_t b = buf[0];
                ui8_t g = buf[1];
                ui8_t r = buf[2];
                buf += 3;
                if (r != 0 || g != 0 || b != 0) {
                    framebuffer[base + 3 * col    ] = b;
                    framebuffer[base + 3 * col + 1] = g;
                    framebuffer[base + 3 * col + 2] = r;
                }
            }
        }
    }
        break;

    case _32: {
        ui32_t * buf = (ui32_t*)buffer;
        for (ui16_t row = 0; row < height; row++) {
            ui32_t base = (y + row) * getWidth() + x;
            for (ui16_t col = 0; col < width; col++) {
                ui32_t color = *buf++;
                if (color != 0) {
                    ((ui32_t*)framebuffer)[base + col] = color;
                }
            }
        }
    }
        break;
    
    default:
        break;
    }
}


ui16_t EcranBochs::lireRegistre(VBE_INDEX id) {
    ecrireMot(id, VBE_DISPI_IOPORT_INDEX);
    return lireMot(VBE_DISPI_IOPORT_DATA);
}

void EcranBochs::ecrireRegistre(VBE_INDEX id, ui16_t value) {
    ecrireMot(id, VBE_DISPI_IOPORT_INDEX);
    ecrireMot(value, VBE_DISPI_IOPORT_DATA);
}

ui8_t EcranBochs::bytesPerPixel() {
    if (mode == VBE_MODE::_15) return 2;
    return mode / 8;
}



