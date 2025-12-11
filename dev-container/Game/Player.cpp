#include "Player.h"

Player::Player(EcranBochs* l_vga) : vga(l_vga), a(0,0), v(0,0), p(0,0)
    , velocity(500), gravity(0)
{
    p.y += 50;
}
Player::~Player(){}

void Player::Update(FixFloat dt){
    /*vec2f nv(0,0);
    if(clavier.is_pressed(kconf.right))
        nv.x.SetValue(velocity);
    if(clavier.is_pressed(kconf.left))
        nv.x.SetValue(-velocity);
    v = nv;*/

    vec2f na(0,0);
    //na.y += gravity;
    a = na;

    FixFloat ax = dt * a.x;
    FixFloat ay = dt * a.y;
    v.x += ax;
    v.y += ay;

    FixFloat vx = dt * v.x;
    FixFloat vy = dt * v.y;
    p.x += vx;
    p.y += vy;
}

void Player::Render(){
    vga->plot_sprite(sprite_data, SPRITE_WIDTH, SPRITE_HEIGHT, p.x.GetRealValue(), p.y.GetRealValue());
}

bool GetCollisions(){
    return false;
}

void Player::SetKeyConfig(KeyConfig& l_kconf){
    kconf = l_kconf;
}

int Player::GetPercentage(){
    return 1;
}