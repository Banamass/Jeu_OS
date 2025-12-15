#ifndef MENUENDING_H
#define MENUENDING_H

#include <drivers/EcranBochs.h>
#include <drivers/Clavier.h>

class MenuEnding {
public:
    MenuEnding(int winner);
    void run();

private:
    int winner;
    EcranBochs vga;
    Clavier clavier;
};

#endif