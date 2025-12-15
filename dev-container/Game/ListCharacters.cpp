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