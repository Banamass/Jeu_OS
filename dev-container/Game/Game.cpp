#include "Game.h"

Game::Game() : vga(640, 480, VBE_MODE::_8), player1(&vga), player2(&vga), map(){
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
}
Game::~Game(){

}

void Game::run(){
    while(1){
        Update();
        Render();
    }
}

void Game::Update(){
    //IntRect test;
    //test.Intersect(test);
    player1.Update(&map);
    player2.Update(&map);
}
void Game::Render(){
    vga.clear(1);
    map.Render();
    player1.Render();
    player2.Render();
    vga.swapBuffer(); // call this after you finish drawing your frame to display it, it avoids screen tearing
}