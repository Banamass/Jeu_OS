#include "Game/MenuCharacters.h"

// sélection par le joueur 1 puis par le joueur 2 dans 2 run différents

MenuCharacters::MenuCharacters()
    : vga(640, 480, VBE_MODE::_8), selection(0) {
    vga.init();
    vga.clear(0);

    vga.set_palette(palette_vga);
    }

int MenuCharacters::run(int player){ // player = 1 ou 2
    act_player=player;
    update();
    while(1){
        if (act_player==1) { // premier joueur
            bool q_now = clavier.is_pressed_then_deleted(AZERTY::K_Q);
            bool d_now = clavier.is_pressed_then_deleted(AZERTY::K_D);
            if (q_now) {
                selection = (selection -1 + nbCharacters) % nbCharacters;
            } else if (d_now) {
                selection = (selection +1) % nbCharacters;
            }
        } else { // 2e joueur
            bool k_now = clavier.is_pressed_then_deleted(AZERTY::K_K);
            bool m_now = clavier.is_pressed_then_deleted(AZERTY::K_M);
            if (k_now) {
                selection = (selection -1 + nbCharacters) % nbCharacters;
                if (selection == choice_player1) { // ne peut pas choisir celui du premier
                    selection = (selection -1 + nbCharacters) % nbCharacters;
                }
            } else if (m_now) {
                selection = (selection +1) % nbCharacters;
                if (selection == choice_player1) { // ne peut pas choisir celui du premier
                    selection = (selection +1) % nbCharacters;
                }
            }
        }
        update();

        if(clavier.is_pressed_then_deleted(AZERTY::K_RETURN)){
            if (act_player == 1) {
                choice_player1 = selection; // on stocke le choix du premier
                if (choice_player1 == 0) {
                    selection = 1;
                } else {
                    selection = 0;
                }
                return choice_player1;
            }
            return selection;
        }
    }
}

void MenuCharacters::update(){
    vga.clear(0);
    ui8_t color;
    if (act_player == 1) {
        color = 70;
        //affiche "PLAYER 1 - CHOOSE YOUR CHARACTER"
    } else {
        color = 150;
        //affiche "PLAYER 2 - CHOOSE YOUR CHARACTER"
    }

    if (choice_player1!=-1) {
        vga.plot_square(80+choice_player1*100, 120, 80, 70);
    }
    vga.plot_square(80+selection*100, 120, 80, color);
    for (int s=0; s< nbCharacters; s++) {
        vga.plot_sprite(ListCharacters::GetCharacter(s, selection == s ? 2 : 0), ListCharacters::GetWidth(s), ListCharacters::GetHeight(s), 80+100*s, 200-ListCharacters::GetHeight(s));
    }
    vga.swapBuffer();

    
}
