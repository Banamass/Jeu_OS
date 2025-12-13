#include "Player.h"

Player::Player(EcranBochs* l_vga) : vga(l_vga)
    , velocity(20), gravity(10)
{
    
}
Player::~Player(){}

void Player::Update(Map* map){
    /*int dt = 1;

    if(clavier.is_pressed(kconf.right))
        v.x += velocity * dt;
    if(clavier.is_pressed(kconf.left))
        v.x += -velocity * dt;
    
    //a.y += gravity;

    v.x += a.x * dt;
    v.y += a.y * dt;

    vec2 maxVelocity(200, 1000);
    CapVec2(v, maxVelocity);

    vec2 lastPos(p.x, p.y);

    p.x += v.x * dt;
    p.y += v.y * dt;

    IntRect collision = GetIntRect();
    //IntRect c = map->GetCollision(collision);
    
        //p.x = lastPos.x;
        //p.y = lastPos.y;
    

    a.x = 0;
    a.y = 0;
    vec2 depletion(5 * dt,5 * dt);
    Vec2Depletion(v, depletion);*/
}

void Player::Render(){
    vga->plot_sprite(sprite_data, SPRITE_WIDTH, SPRITE_HEIGHT, 0 / 1000, 0 / 1000);
}

IntRect Player::GetIntRect(){
    return IntRect(vec2(5,5), vec2(5,5));
}

void Player::SetKeyConfig(KeyConfig& l_kconf){
    kconf = l_kconf;
}

int Player::GetPercentage(){
    return 1;
}