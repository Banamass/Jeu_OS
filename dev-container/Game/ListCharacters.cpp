#include "ListCharacters.h"

ListCharacters::ListCharacters() {}

/*
Personnages : 
    - 0 : Zelda
    - 1 : Yoshi
    - 2 : DK
    - 3 : Mr Game & Watch (aka Mr)
    - 4 : Mario

Actions :
    - 0 : Idle
    - 1 : Walk
    - 2 : Attack1
    - 3 : Attack2
    - 4 : Block
    - 5 : Jump
*/


unsigned char* ListCharacters::GetCharacter(int num, int action) {
    // Renvoie le tableau du sprite selon le personnage et l'action
    switch (num) 
    {
    case 0:
        return getZeldaAction(action);
    case 1:
        return getYoshiAction(action);
    case 2:
        return getDKAction(action);
    case 3:
        return getMrAction(action);
    case 4:
        return getMarioAction(action);
    }
}

int ListCharacters::GetHeight(int num){
    // Renvoie la hauteur du sprite selon le personnage
    switch (num) 
    {
    case 0:
        return ZELDA_HEIGHT;
    case 1:
        return YOSHI_HEIGHT;
    case 2:
        return DK_HEIGHT;
    case 3:
        return MR_HEIGHT;
    case 4:
        return MARIO_HEIGHT;
    }
}

int ListCharacters::GetWidth(int num){
    // Renvoie la largeur du sprite selon le personnage
    switch (num) 
    {
    case 0:
        return ZELDA_WIDTH;
    case 1:
        return YOSHI_WIDTH;
    case 2:
        return DK_WIDTH;
    case 3:
        return MR_WIDTH;
    case 4:
        return MARIO_WIDTH;
    }
}

int ListCharacters::GetFootLeft(int num){
    // renvoie de combien il faut décaler le sprite pour que le personnage soit centré sur p.x (position du player) selon le personnage
    // cas du sprite classique - non inversé
    switch (num) 
    {
    case 0:
        return ZELDA_FOOT_LEFT;
    case 1:
        return YOSHI_FOOT_LEFT;
    case 2:
        return DK_FOOT_LEFT;
    case 3:
        return MR_FOOT_LEFT;
    case 4:
        return MARIO_FOOT_LEFT;
    }
}

int ListCharacters::GetFootRight(int num){
    // renvoie de combien il faut décaler le sprite pour que le personnage soit centré sur p.x (position du player) selon le personnage
    // cas du sprite inversé
    switch (num) 
    {
    case 0:
        return ZELDA_FOOT_RIGHT;
    case 1:
        return YOSHI_FOOT_RIGHT;
    case 2:
        return DK_FOOT_RIGHT;
    case 3:
        return MR_FOOT_RIGHT;
    case 4:
        return MARIO_FOOT_RIGHT;
    }
}

IntRect ListCharacters::GetIntRectAtt1(int num) {
    // Renvoie un IntRec qui correspond à la hitbox de l'attaque 1 selon le personnage
    switch (num) 
    {
    case 0:
        return IntRect(vec2(ZELDA_ORIGINE_X_ATT,0), vec2(ZELDA_X_ATT1, ZELDA_Y_ATT1));
    case 1:
        return IntRect(vec2(YOSHI_ORIGINE_X_ATT,0), vec2(YOSHI_X_ATT1, YOSHI_Y_ATT));
    case 2:
        return IntRect(vec2(DK_ORIGINE_X_ATT1,0), vec2(DK_X_ATT1, DK_HEIGHT));
    case 3:
        return IntRect(vec2(MR_ORIGINE_X_ATT1,0), vec2(MR_X_ATT1, MR_HEIGHT));
    case 4:
        return IntRect(vec2(MARIO_ORIGINE_X_ATT1,0), vec2(MARIO_X_ATT1, MARIO_Y_ATT1));
    }
}

IntRect ListCharacters::GetIntRectAtt2(int num) {
    // Renvoie un IntRec qui correspond à la hitbox de l'attaque 2 selon le personnage
    switch (num) 
    {
    case 0:
        return IntRect(vec2(ZELDA_ORIGINE_X_ATT,0), vec2(ZELDA_X_ATT2, ZELDA_HEIGHT));
    case 1:
        return IntRect(vec2(YOSHI_ORIGINE_X_ATT,0), vec2(YOSHI_X_ATT2, YOSHI_Y_ATT));
    case 2:
        return IntRect(vec2(DK_ORIGINE_X_ATT2,0), vec2(DK_X_ATT2, DK_HEIGHT));
    case 3:
        return IntRect(vec2(MR_ORIGINE_X_ATT2,0), vec2(MR_X_ATT2, MR_HEIGHT));
    case 4:
        return IntRect(vec2(MARIO_ORIGINE_X_ATT2,0), vec2(MARIO_X_ATT2, MARIO_Y_ATT2));
    }
}

IntRect ListCharacters::GetIntRect(int num) {
    // Renvoie un IntRec qui correspond à la hitbox du personnage num pour savoir s'il est touché par une attaque
    switch (num) 
    {
    case 0:
        return IntRect(vec2(-ZELDA_CHAR_WIDTH/2+5,0), vec2(ZELDA_CHAR_WIDTH, ZELDA_CHAR_HEIGHT));
    case 1:
        return IntRect(vec2(-YOSHI_CHAR_WIDTH/2+5,0), vec2(YOSHI_CHAR_WIDTH, YOSHI_HEIGHT));
    case 2:
        return IntRect(vec2(-DK_CHAR_WIDTH/2+5,0), vec2(DK_CHAR_WIDTH, DK_CHAR_HEIGHT));
    case 3:
        return IntRect(vec2(-MR_CHAR_WIDTH/2+5,0), vec2(MR_CHAR_WIDTH, MR_CHAR_HEIGHT));
    case 4:
        return IntRect(vec2(-MARIO_CHAR_WIDTH/2+5,0), vec2(MARIO_CHAR_WIDTH, MARIO_CHAR_HEIGHT));
    }
}
