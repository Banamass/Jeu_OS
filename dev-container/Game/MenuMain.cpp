#include "Game/MenuMain.h"

MenuMain::MenuMain()
    : selection(0) {}

int MenuMain::run(){
    update();
    while(1){
        bool z_now = clavier.is_pressed_then_deleted(AZERTY::K_Z);
        bool s_now = clavier.is_pressed_then_deleted(AZERTY::K_S);
        if ((z_now && !prev_z)||(s_now && !prev_s)) {
            selection = 1 - selection;
            update();
        }
        prev_z = z_now;
        prev_s = s_now;

        if(clavier.is_pressed_then_deleted(AZERTY::K_RETURN)){
            return selection;
        }
    }
}

void MenuMain::update(){
    ecran.effacerEcran(NOIR);

    ecran.afficherMot(9,COLONNES/2 - 10,"===== SMASH OS =====");

    ecran.afficherMot(10, COLONNES/2 - 8 , selection == 0 ? "> Start" : "  Start");
    ecran.afficherMot(11, COLONNES/2 - 8, selection == 1 ? "> Quit" : "  Quit");
}
