#include "ListCharacters.h"

ListCharacters::ListCharacters() {}

/*
Personnages : 
    - 0 : Zelda
    - 1 : Yoshi
    - 2 : DK

Actions :
    - 0 : Idle
    - 1 : Walk
    - 2 : Attack1
    - 3 : Attack2
    - 4 : Block
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
    }
}