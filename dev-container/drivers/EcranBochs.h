#pragma once

#include <sextant/types.h>

enum VBE_INDEX {
    ID = 0,
    XRES,
    YRES,
    BPP,
    ENABLE,
    BANK,
    VIRT_WIDTH,
    VIRT_HEIGHT,
    X_OFFSET,
    Y_OFFSET
};

enum VBE_MODE {
    // _4 =     0x04,
    _8 =     0x08,
    _15 =    0x0F,
    _16 =    0x10,
    _24 =    0x18,
    _32 =    0x20
};

#define VBE_DISPI_IOPORT_INDEX  0x01CE
#define VBE_DISPI_IOPORT_DATA   0x01CF



#define VBE_DISPI_DISABLED  0x00
#define VBE_DISPI_ENABLED   0x01

#define VBE_DISPI_LFB_ENABLED   0x40
#define VBE_DISPI_NOCLEARMEM    0x80


class EcranBochs {
    public:
        static const ui16_t PCI_VENDOR = 0x1234;
        static const ui16_t PCI_DEVICE = 0x1111;
        static ui8_t* VRAM;
    
    private:
        const ui16_t width;
        const ui16_t height;
        const VBE_MODE mode;
        bool topBuffer;

        ui8_t* framebuffer;

        ui16_t lireRegistre(VBE_INDEX id);
        void ecrireRegistre(VBE_INDEX id, ui16_t value);

        ui8_t bytesPerPixel();

    public:
        EcranBochs(ui16_t width, ui16_t height, VBE_MODE mode);

        void init();
        void swapBuffer();

        ui16_t getWidth();
        ui16_t getHeight();

        void set_palette(ui8_t palette_vga[256][3]);

        void clear(ui8_t color);
        void clear(ui8_t r, ui8_t g, ui8_t b);

        void paint(unsigned int x, unsigned int y, char color);
        void paint(unsigned int x, unsigned int y, ui8_t r, ui8_t g, ui8_t b);

        void plot_square(int x, int y, int size, ui8_t color);
        void plot_square(int x, int y, int size, ui8_t r, ui8_t g, ui8_t b);

        void plot_palette(int x, int y, int size);

        void plot_sprite(void* buffer, ui16_t width, ui16_t height, ui16_t x, ui16_t y);

};
