#include "Game.h"
#include "MenuMain.h"
#include <sextant/ordonnancements/preemptif/thread.h>
#include <sextant/Synchronisation/Spinlock/Spinlock.h>
#include "HUD.h"

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
    kconf.jump = AZERTY::K_S;
    kconf.attack = AZERTY::K_Z;
    kconf.special = AZERTY::K_A;
    kconf.block = AZERTY::K_E;
    player1.SetKeyConfig(kconf);

    kconf.left = AZERTY::K_K;;
    kconf.right = AZERTY::K_M;
    kconf.jump = AZERTY::K_L;
    kconf.attack = AZERTY::K_O;
    kconf.special = AZERTY::K_I;
    kconf.block = AZERTY::K_P;
    player2.SetKeyConfig(kconf);

    player1.SetCharacter(p1);
    player1.SetAction(0);
    player2.SetCharacter(p2);
    player2.SetAction(0);

    IntRect object(vec2(200, 0), vec2(50, 500));
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

    hud.Render(&vga, player1, player2);

    vga.swapBuffer(); // call this after you finish drawing your frame to display it, it avoids screen tearing
}


void Game::ThreadPlayer(void* arg) {
    PlayerThreadArgs* args = (PlayerThreadArgs*)arg;
    Player* player = args->player;
    Game* game = args->game;

    while (1) {
        game->spin.Take(&game->gameLock);
        player->Update();
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
        thread_yield();
    }
}



void Game::UpdateLogic() {
    if(player1.GetIsAttacking()){
        IntRect rectAtck;
        player1.GetAttackRectPX(rectAtck);
        player1.GetAttackRectPY(rectAtck);
        player1.GetAttackRectSX(rectAtck);
        player1.GetAttackRectSY(rectAtck);
        IntRect rectBlock;
        player2.GetAttackRectPX(rectBlock);
        player2.GetAttackRectPY(rectBlock);
        player2.GetAttackRectSX(rectBlock);
        player2.GetAttackRectSY(rectBlock);
        if(Intersect(rectAtck, rectBlock)){
            player2.TakePercentage(10);
        }
        player1.SetIsAttacking(false);
    }
    if(player2.GetIsAttacking()){
        IntRect rectAtck;
        player2.GetAttackRectPX(rectAtck);
        player2.GetAttackRectPY(rectAtck);
        player2.GetAttackRectSX(rectAtck);
        player2.GetAttackRectSY(rectAtck);
        IntRect rectBlock;
        player1.GetAttackRectPX(rectBlock);
        player1.GetAttackRectPY(rectBlock);
        player1.GetAttackRectSX(rectBlock);
        player1.GetAttackRectSY(rectBlock);
        if(Intersect(rectAtck, rectBlock)){
            player1.TakePercentage(10);
        }
        player2.SetIsAttacking(false);
    }
}