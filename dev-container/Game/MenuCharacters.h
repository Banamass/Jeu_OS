#ifndef _MENU_CHARACTERS_H_
#define _MENU_CHARACTERS_H_

#include "drivers/EcranBochs.h"
#include "drivers/Clavier.h"

#include "ListCharacters.h"
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
    int choice_player1 = -1;
    int act_player;
    

};

#endif
