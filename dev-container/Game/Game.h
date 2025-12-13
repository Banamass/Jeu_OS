#ifndef _GAME_H_
#define _GAME_H_

#include "Game/Player.h"

class Game{
public:
    Game();
    ~Game();

    void run();

    void Update();
    void Render();

private:
    Map map;
    Player player1;
    Player player2;
    EcranBochs vga;
};

#endif