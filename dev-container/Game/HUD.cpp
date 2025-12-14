#include "HUD.h"
#include <drivers/EcranBochs.h>
#include "Game/Player.h"

// Fond HUD
constexpr ui8_t HUD_BG = 8;   // gris

constexpr ui8_t HP_GRADIENT[12] = {
    // VERT
    205,
    206,
    207,
    208,

    224, 
    225, 
    226,


    // ORANGE → ROUGE
    38,
    37,
    36,
    35,
    34
};


ui8_t GetHPColor(int pct, int maxHp){
    int index = (pct * 11) / 100;
    return HP_GRADIENT[index];
}



void HUD::DrawHPBar(
    EcranBochs* vga,
    int x, int y,
    int width, int height,
    int hp, int maxHp,
    ui8_t bgColor,
    ui8_t hpColor
) {
    // Clamp
    if (hp < 0) hp = 0;
    if (hp > maxHp) hp = maxHp;

    // Fond
    for (int iy = 0; iy < height; iy++) {
        for (int ix = 0; ix < width; ix++) {
            vga->paint(x + ix, y + iy, bgColor);
        }
    }

    // Barre HP
    int filled = (hp * width) / maxHp;

    for (int iy = 1; iy < height - 1; iy++) {
        for (int ix = 1; ix < filled - 1; ix++) {
            vga->paint(x + ix, y + iy, hpColor);
        }
    }

}


void HUD::Render(EcranBochs* vga, Player& p1,Player& p2) {
    const int screenW = vga->getWidth();
    const int screenH = vga->getHeight();

    const int margin = 10;
    const int barWidth = 180;
    const int barHeight = 14;

    const int y = screenH - barHeight - margin;

    // === PLAYER 1 (bas gauche) ===
    int p1x = margin;
    ui8_t p1Color = GetHPColor(p1.GetPercentage(), 100);

    DrawHPBar(
        vga,
        p1x,
        y,
        barWidth,
        barHeight,
        p1.GetPercentage(),
        100,
        /*bg*/ HUD_BG,
        /*hp*/ GetHPColor(p1.GetPercentage(), 100)
    );

    // === PLAYER 2 (bas droit) ===
    int p2x = screenW - barWidth - margin;

    DrawHPBar(
        vga,
        p2x,
        y,
        barWidth,
        barHeight,
        p2.GetPercentage(),
        100,
        /*bg*/ HUD_BG,
        /*hp*/ GetHPColor(p2.GetPercentage(), 100)
    );
}



