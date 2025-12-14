#ifndef HUD_H_
#define HUD_H_

#include <drivers/EcranBochs.h>
#include "Game/Player.h"

class HUD {
public:
    void Render(EcranBochs* vga, Player& p1, Player& p2);

private:
    void DrawHPBar(
        EcranBochs* vga,
        int x, int y,
        int width, int height,
        int hp, int maxHp,
        ui8_t bgColor,
        ui8_t hpColor
    );

};

#endif
