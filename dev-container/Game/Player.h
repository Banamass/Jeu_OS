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
        : vga(l_vga), p(), v(), a(), nbJumpLeft(0), isAttacking(false), attackAnimationValue(10000){}
    ~Player(){}

    void Update();
    void Render();

    void SetKeyConfig(KeyConfig& kconf);
    void SetCharacter(int numCharacter);
    void SetAction(int numAction) ;

    void GetIntRectPX(IntRect& res);
    void GetIntRectPY(IntRect& res);
    void GetIntRectSX(IntRect& res);
    void GetIntRectSY(IntRect& res);
    void GetAttackRectPX(IntRect& res);
    void GetAttackRectPY(IntRect& res);
    void GetAttackRectSX(IntRect& res);
    void GetAttackRectSY(IntRect& res);

    int GetPercentage();
    void TakePercentage(int l_percentage);
    bool GetIsAttacking();
    void SetIsAttacking(bool b);
    bool GetIsBlocking();
    void SetIsBlocking(bool b);

    void Blink();

private:
    EcranBochs* vga;
    int blinkValue;

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
    int attackCooldown;
    int attackAnimationValue;
    bool isBlocking;
    int actionBeforeAtkBlock;
};

#endif