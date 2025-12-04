#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "drivers/EcranBochs.h"
#include "sextant/sprite.h"
#include "sextant/Sprite/Zelda.h"
#include "sextant/Sprite/Yoshi.h"
#include "sextant/Sprite/DK.h"
#include "drivers/Clavier.h"

struct KeyConfig{
    ui8_t left;
    ui8_t right;
    ui8_t jump;
    ui8_t attack;
    ui8_t special;
    ui8_t block;
};

class Player{
public:
    Player(EcranBochs* l_vga);
    ~Player();

    void Update(double dt);
    void Render();

    void SetKeyConfig(KeyConfig& kconf);

    int GetPercentage();

private:
    EcranBochs* vga;
    Clavier clavier;
    KeyConfig kconf;

    int offset;

};

#endif