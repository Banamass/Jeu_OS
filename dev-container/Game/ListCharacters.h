#ifndef _LISTCHARACTERS_H_
#define _LISTCHARACTERS_H_

#include "sextant/Sprite/Zelda.h"
#include "sextant/Sprite/Yoshi.h"
#include "sextant/Sprite/DK.h"
#include "sextant/Sprite/Mr.h"
#include "sextant/Sprite/Mario.h"
#include "utils.h"

#define nbCharacters 5


class ListCharacters{
public:
    ListCharacters();
    static unsigned char* GetCharacter(int num, int action);
    static int GetHeight (int num);
    static int GetWidth (int num);
    static int GetFootLeft(int num);
    static int GetFootRight(int num);
    static IntRect GetIntRectAtt1(int num);
    static IntRect GetIntRectAtt2(int num);
    static IntRect GetIntRect (int num);
};

#endif