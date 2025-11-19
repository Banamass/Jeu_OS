#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "drivers/EcranBochs.h"
#include "sextant/sprite.h"
#include "drivers/Clavier.h"

struct KeyConfig{
    char left;
    char right;
    char jump;
    char attack;
    char special;
    char block;
};

class Player{
public:
    Player(EcranBochs* l_vga);
    ~Player();

    void Update(double dt);
    void Render();

    void SetKeyConfig(KeyConfig& kconf);

private:
    EcranBochs* vga;
    Clavier clavier;
    KeyConfig kconf;

    int offset;
};

#endif