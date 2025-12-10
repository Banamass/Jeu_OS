#ifndef _LISTCHARACTERS_H_
#define _LISTCHARACTERS_H_

#include "sextant/Sprite/Zelda.h"
#include "sextant/Sprite/Yoshi.h"
#include "sextant/Sprite/DK.h"

class ListCharacters{
public:
    ListCharacters();
    unsigned char* GetCharacter(int num, int action);
    int GetHeight (int num);
    int GetWidth (int num);

};

#endif