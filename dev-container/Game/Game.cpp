#include "Game.h"
#include "MenuMain.h"
#include <sextant/ordonnancements/preemptif/thread.h>
#include <sextant/Synchronisation/Spinlock/Spinlock.h>

struct PlayerThreadArgs {
    Game* game;
    Player* player;
};


Game::Game(int p1, int p2) : vga(640, 480, VBE_MODE::_8), player1(&vga), player2(&vga){
    vga.init();
    vga.clear(0);

    // only usefull in 4 or 8 bits modes
    vga.set_palette(palette_vga);

    KeyConfig kconf;
    kconf.left = AZERTY::K_Q;
    kconf.right = AZERTY::K_D;
    player1.SetKeyConfig(kconf);

    kconf.left = AZERTY::K_K;;
    kconf.right = AZERTY::K_M;
    player2.SetKeyConfig(kconf);

    player1.SetCharacter(p1);
    player1.SetAction(0);
    player2.SetCharacter(p2);
    player2.SetAction(0);
}
Game::~Game(){

}

void Game::run(){
    static PlayerThreadArgs argsP1;
    static PlayerThreadArgs argsP2;

    argsP1.game = this;
    argsP1.player = &player1;

    argsP2.game = this;
    argsP2.player = &player2;

    // Thread Render
    // 1 Thread par player
    create_kernel_thread(ThreadPlayer, &argsP1);
    create_kernel_thread(ThreadPlayer, &argsP2);
    create_kernel_thread(ThreadRender, this);

    while(1){
        //Render();
        spin.Take(&gameLock);
        UpdateLogic();
        spin.Release(&gameLock);
    }
}

void Game::Render(){
    vga.clear(140);
    vga.plot_sprite(sprite_scene, SCENE_WIDTH, SCENE_HEIGHT, (640-SCENE_WIDTH)/2, (480-SCENE_HEIGHT)/2);
    player1.Render();
    player2.Render();

    //hud.Render(&vga, player1, player2);

    vga.swapBuffer(); // call this after you finish drawing your frame to display it, it avoids screen tearing
}


void Game::ThreadPlayer(void* arg) {
    PlayerThreadArgs* args = (PlayerThreadArgs*)arg;
    Player* player = args->player;
    Game* game = args->game;

    double dt = 0.1f;

    while (1) {
        game->spin.Take(&game->gameLock);
        player->Update(dt);
        game->spin.Release(&game->gameLock);
        thread_yield();
    }
}

void Game::ThreadRender(void* arg) {
    Game* game = (Game*)arg;

    while (1) {
        game->spin.Take(&game->gameLock);
        game->Render();
        game->spin.Release(&game->gameLock);
    }
}



void Game::UpdateLogic() {
}