#ifndef _GAME_H_
#define _GAME_H_

#include "Game/Player.h"
#include "Game/Map.h"
#include "sextant/Sprite/scene.h"

class Game{
public:
    Game(int p1, int p2);
    ~Game();

    void run();

    void Update();
    void Render();

private:
    Player player1;
    Player player2;
    EcranBochs vga;
};

#endif