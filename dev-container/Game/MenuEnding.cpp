#include "MenuEnding.h"

// Sprites
#include <sextant/Sprite/player1_wins.h>
#include <sextant/Sprite/player2_wins.h>
#include <sextant/Sprite/press_enter.h>

MenuEnding::MenuEnding(int winner)
    : winner(winner),
      vga(640, 480, VBE_MODE::_8)
{
    vga.init();
    vga.clear(0);
}

void MenuEnding::run() {
    bool blink = true;
    int counter = 0;

    while (true) {
        vga.clear(0);

        if (winner == 1) {
            vga.plot_sprite(
                sprite_player1_wins,
                SPRITE_P1_WIDTH,
                SPRITE_P1_HEIGHT,
                (640 - SPRITE_P1_WIDTH) / 2,
                200
            );
        }else if (winner == 2) {
            vga.plot_sprite(
                sprite_player2_wins,
                SPRITE_P2_WIDTH,
                SPRITE_P2_HEIGHT,
                (640 - SPRITE_P2_WIDTH) / 2,
                200
            );
        }   


        // --- Clignotement PRESS ENTER ---
        if (blink) {
            vga.plot_sprite(
                sprite_press_enter,
                SPRITE_PE_WIDTH,
                SPRITE_PE_HEIGHT,
                (640 - SPRITE_PE_WIDTH) / 2,
                280
            );
        }

        vga.swapBuffer();

        counter++;
        if (counter > 60) {
            blink = !blink;
            counter = 0;
        }

        if (clavier.is_pressed_then_deleted(AZERTY::K_RETURN)) {
            return;
        }
    }
}
