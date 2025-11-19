#include "Player.h"

Player::Player(EcranBochs* l_vga) : vga(l_vga), offset(0)
{}
Player::~Player(){}

void Player::Update(double dt){
    if(clavier.testChar()){
        char c = clavier.getchar();
        if(c == kconf.right)
            offset = (offset+1) % (640);
        if(c == kconf.left)
            offset = (offset-1) % (640);
        else
            return;
        clavier.consumne();
    }
}
void Player::Render(){
    vga->plot_sprite(sprite_data, SPRITE_WIDTH, SPRITE_HEIGHT, offset, 100);
}

void Player::SetKeyConfig(KeyConfig& l_kconf){
    kconf = l_kconf;
}