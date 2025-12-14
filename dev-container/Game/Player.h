#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "drivers/EcranBochs.h"
#include "sextant/sprite.h"
#include "ListCharacters.h"
#include "drivers/Clavier.h"
#include "Game/utils.h"
#include "Game/Map.h"
#include "drivers/PortSerie.h"

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
    Player(EcranBochs* l_vga) 
        : vga(l_vga), p(), v(), a(), nbJumpLeft(0), isAttacking(false){}
    ~Player(){}

    void Update();
    void Render();

    void SetKeyConfig(KeyConfig& kconf);
    void SetCharacter(int numCharacter);
    void SetAction(int numAction) ;

    IntRect GetIntRect();

    int GetPercentage();
    void TakePercentage(int l_percentage);
    bool GetIsAttacking();
    bool SetIsAttacking();

private:
    EcranBochs* vga;
    Clavier clavier;
    KeyConfig kconf;
    int character;
    int action;
    int percentage;

    vec2 p;
    vec2 v;
    vec2 a;

    int nbJumpLeft;
    
    bool isAttacking;
};

#endif