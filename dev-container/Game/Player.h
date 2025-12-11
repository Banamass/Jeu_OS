#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "drivers/EcranBochs.h"
#include "sextant/sprite.h"
#include "drivers/Clavier.h"
#include "Game/utils.h"

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

    void Update(FixFloat dt);
    void Render();

    void SetKeyConfig(KeyConfig& kconf);

    bool GetCollisions();

    int GetPercentage();

private:
    EcranBochs* vga;
    Clavier clavier;
    KeyConfig kconf;

    vec2f p;
    vec2f v;
    vec2f a;

    int velocity;

    FixFloat gravity;
};

#endif