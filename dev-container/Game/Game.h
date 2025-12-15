#ifndef _GAME_H_
#define _GAME_H_

#include "Game/Player.h"
#include "Game/Map.h"
#include "sextant/Sprite/scene.h"
#include <sextant/ordonnancements/preemptif/thread.h>
#include <sextant/Synchronisation/Spinlock/Spinlock.h>
#include "Game/HUD.h"

//class HUD;

class Game{
public:
    Game(int p1, int p2);
    ~Game();

    int run();

    void Update();
    void Render();

private:

    enum class GameState { 
        Playing, 
        Ended 
    };


    static void ThreadPlayer(void* arg);
    static void ThreadRender(void* arg);

    void UpdateLogic();

    Player player1;
    Player player2;
    EcranBochs vga;
    Clavier clavier;

    Spinlock spin;
    int gameLock = 0;

    bool running = true;
    int winner = 0;
    GameState state = GameState::Playing;

    HUD hud;
};

#endif