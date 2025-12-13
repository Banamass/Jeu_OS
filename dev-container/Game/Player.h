#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "drivers/EcranBochs.h"
#include "sextant/sprite.h"
#include "drivers/Clavier.h"
#include "Game/utils.h"
#include "Game/Map.h"

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

    void Update(Map* map);
    void Render();

    void SetKeyConfig(KeyConfig& kconf);

    IntRect GetIntRect();

    int GetPercentage();

private:
    EcranBochs* vga;
    Clavier clavier;
    KeyConfig kconf;

    /*vec2 p;
    vec2 v;
    vec2 a;*/

    int velocity;

    int gravity;
};

#endif