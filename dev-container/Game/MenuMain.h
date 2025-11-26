#ifndef _MENU_MAIN_H_
#define _MENU_MAIN_H_

#include "drivers/EcranBochs.h"
#include "drivers/Clavier.h"

class MenuMain {
public:
    MenuMain();
    int run();
    void update();

private:
    Clavier clavier;
    Ecran ecran;
    int selection;
    
    bool prev_z = false;
    bool prev_s = false;

};

#endif
