#ifndef _MENU_CHARACTERS_H_
#define _MENU_CHARACTERS_H_

#include "drivers/EcranBochs.h"
#include "drivers/Clavier.h"

#include "sextant/Sprite/Zelda.h"
#include "sextant/Sprite/Yoshi.h"
#include "sextant/Sprite/DK.h"
#include "sextant/sprite.h"

class MenuCharacters {
public:
    MenuCharacters();
    int run(int player);
    void update();

private:
    Clavier clavier;
    Ecran ecran;
    EcranBochs vga;
    int selection;
    int nbCharacters = 3;
    int choice_player1 = -1;
    int act_player;
    

};

#endif
