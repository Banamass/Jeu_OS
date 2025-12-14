#include "Player.h"

void Player::Update(){
    int dt = 1;

    int velocity = 40;
    int gravity = 20;
    int jumpVel = 2 * 1000;

    if(clavier.is_pressed(kconf.right))
        v.x += velocity * dt;
    if(clavier.is_pressed(kconf.left))
        v.x += -velocity * dt;
    if(clavier.is_pressed_then_deleted(kconf.jump) && nbJumpLeft > 0){
        v.y -= jumpVel * dt;
        nbJumpLeft--;
    }

    a.y += gravity;

    v.x += a.x * dt;
    v.y += a.y * dt;

    vec2 maxVelocity(1000, 10000);
    CapVec2(v, maxVelocity);

    vec2 lastPos(p.x, p.y);

    p.x += v.x * dt;
    p.y += v.y * dt;
    
    int bbw = 10;
    int bbh = 2;
    int bbx = (bbw / 2) * 1000;
    int bby = (ListCharacters::GetHeight(character) - bbh) * 1000;
    int bbsx = bbw * 1000;
    int bbsy = bbh * 1000;
    if(GetSceneCollisions(p.x + bbx, p.y + bby, bbsx, bbsy)){
        if(!GetSceneCollisions(p.x + bbx, lastPos.y + bby, bbsx, bbsy)
            && v.y > 0){
            p.y = lastPos.y;
            v.y = 0;
            nbJumpLeft = 2;
        }
        else if(!GetSceneCollisions(lastPos.x + bbx, p.y + bby, bbsx, bbsy)){
            p.x = lastPos.x;
            v.x = 0;
        }
    }

    if(p.y >= 480 * 1000){
        p.y = 0;
        v.y = 0;
    } 
    if(p.x > (640 - ListCharacters::GetWidth(character)) * 1000){
        p.x = lastPos.x;
    }
    if(p.x < -10){
        p.x = 0;
    }

    a.x = 0;
    a.y = 0;
    vec2 depletion(30 * dt, 10 * dt);
    Vec2Depletion(v, depletion);
}

void Player::Render(){
    vga->plot_sprite(ListCharacters::GetCharacter(character, action), ListCharacters::GetWidth(character), ListCharacters::GetHeight(character)
        , p.x / 1000, p.y / 1000);
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

IntRect Player::GetIntRect(){
    return IntRect(p, vec2(10,10));
}

int Player::GetPercentage(){
    return percentage;
}