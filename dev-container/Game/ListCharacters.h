#ifndef _LISTCHARACTERS_H_
#define _LISTCHARACTERS_H_

#include "sextant/Sprite/Zelda.h"
#include "sextant/Sprite/Yoshi.h"
#include "sextant/Sprite/DK.h"
#include "sextant/Sprite/Mr.h"
#include "sextant/Sprite/Mario.h"

#define nbCharacters 5

class ListCharacters{
public:
    ListCharacters();
    static unsigned char* GetCharacter(int num, int action);
    static int GetHeight (int num);
    static int GetWidth (int num);
};

#endif