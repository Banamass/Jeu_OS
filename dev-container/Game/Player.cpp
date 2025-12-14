#include "Player.h"

Player::Player(EcranBochs* l_vga) : vga(l_vga), offset(0), percentage(0)
{}
Player::~Player(){}

void Player::Update(double dt){
    if(clavier.is_pressed(kconf.right)){
        offset = (offset+1) % (640);
    }
    if(clavier.is_pressed(kconf.left)){
        offset = (offset - 1 + 640) % 640;
    }
}

void Player::Render(){
    vga->plot_sprite(ListCharacters::GetCharacter(character, action), ListCharacters::GetWidth(character), ListCharacters::GetHeight(character), offset, 100);
}

void Player::SetKeyConfig(KeyConfig& l_kconf){
    kconf = l_kconf;
}

void Player::SetCharacter(int numCharacter) {
    character = numCharacter;
}

void Player::SetAction(int numAction) {
    action = numAction;
}

int Player::GetPercentage(){
    return percentage;
}