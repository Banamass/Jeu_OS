#ifndef _GAME_H_
#define _GAME_H_

#include "Game/Player.h"
#include "sextant/Sprite/scene.h"
#include <sextant/ordonnancements/preemptif/thread.h>
#include <sextant/Synchronisation/Spinlock/Spinlock.h>
#include "Game/HUD.h"

//class HUD;

class Game{
public:
    Game(int p1, int p2);
    ~Game();

    void run();

    void Update(double dt);
    void Render();

private:

    static void ThreadPlayer(void* arg);
    static void ThreadRender(void* arg);

    void UpdateLogic();

    Player player1;
    Player player2;
    EcranBochs vga;

    Spinlock spin;
    int gameLock = 0;

    HUD hud;
};

#endif