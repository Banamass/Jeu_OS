#include "Player.h"

void Player::Update(){
    int dt = 1;

    int velocity = 40;
    int gravity = 20;
    int jumpVel = 2 * 1000;

    bool isMoving = false;
    if(clavier.is_pressed(kconf.right)){
        if(nbJumpLeft == 2)
            SetAction(WALK);
        v.x += velocity * dt;
        isMoving = true;
    }
    if(clavier.is_pressed(kconf.left)){
        if(nbJumpLeft == 2)
            SetAction(WALK);
        v.x += -velocity * dt;
        isMoving = true;
    }
    if(!isMoving && nbJumpLeft == 2){
        SetAction(IDLE);
    }
    if(clavier.is_pressed_then_deleted(kconf.jump) && nbJumpLeft > 0){
        v.y -= jumpVel * dt;
        nbJumpLeft--;
        SetAction(JUMP);
        Blink();
    }
    if(clavier.is_pressed(kconf.attack)){
        if(action != ATTACK1){
            actionBeforeAtkBlock = action;
            SetIsAttacking(true);
        }
    }
    else if(clavier.is_pressed(kconf.special)){
        if(action != ATTACK2){
            actionBeforeAtkBlock = action;
            SetIsAttacking(true);
        }
    }
    if(attackAnimationValue <= 100){
        SetAction(ATTACK1);
    }
    else if(clavier.is_pressed(kconf.block)){
        if(action != BLOCK){
            actionBeforeAtkBlock = action;
            SetAction(BLOCK);
            SetIsBlocking(true);
        }
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
            if(action == JUMP)
                SetAction(IDLE);
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

    
    if (v.x>0) {
        SetOrientation(false);
    } else if (v.x<0) {
        SetOrientation(true);
    }

    attackCooldown++;
    attackAnimationValue++;
}

void Player::Blink(){
    blinkValue = 1;
}

void Player::Render(){
    if(blinkValue % 2 == 0){
        int realX;
        if (orientation) { // on inverse en miroir le sprite
            realX = p.x / 1000 - ListCharacters::GetFootRight(character) ;
        } else {
            realX = p.x / 1000 - ListCharacters::GetFootLeft(character) ;
        }
        int realY = p.y / 1000;
        vga->plot_sprite(ListCharacters::GetCharacter(character, action), ListCharacters::GetWidth(character), ListCharacters::GetHeight(character)
            , realX, realY, orientation);
    }
    
    if(blinkValue > 0){
        blinkValue++;
        if(blinkValue > 100)
            blinkValue = 0;
    }

}

void Player::GetIntRectPX(IntRect& res){
    res.pos.x = p.x + (v.x > 0 ? ListCharacters::GetWidth(character) + 20 : -20) * 1000;
}
void Player::GetIntRectPY(IntRect& res){
    res.pos.y = p.y;
}
void Player::GetIntRectSX(IntRect& res){
    res.size.x = ListCharacters::GetWidth(character) * 1000;
}
void Player::GetIntRectSY(IntRect& res){
    res.size.y = ListCharacters::GetWidth(character) * 1000;
}
void Player::GetAttackRectPX(IntRect& res){
    res.pos.x = p.x;
}
void Player::GetAttackRectPY(IntRect& res){
    res.pos.y = p.y;
}
void Player::GetAttackRectSX(IntRect& res){
    res.size.x = 50 * 1000;
}
void Player::GetAttackRectSY(IntRect& res){
    res.size.y = 70 * 1000;
}

/*void Player::GetAttackRect(IntRect& res){
    res.pos.x = p.x;
    res.pos.y = p.y;
    res.pos.x += (v.x > 0 ? ListCharacters::GetWidth(character) + 20 : -20) * 1000;
    res.size.x = 50 * 1000;
    res.size.y = 70 * 1000;
}

void Player::GetIntRect(IntRect& res){
    res.pos.x = p.x;
    res.pos.y = p.y;
    res.size.x = ListCharacters::GetWidth(character);
    res.size.y = ListCharacters::GetHeight(character);
}*/

void Player::SetKeyConfig(KeyConfig& l_kconf){
    kconf = l_kconf;
}

void Player::SetCharacter(int numCharacter) {
    character = numCharacter;
}

void Player::SetAction(int numAction) {
    action = numAction;
}

void Player::SetOrientation(bool flip) {
    orientation = flip;
}

/*
IntRect Player::GetIntRect(){
    return IntRect(p, vec2(10,10));
}*/

int Player::GetPercentage(){
    return percentage;
}

void Player::TakePercentage(int l_percentage){
    percentage = (percentage + l_percentage) % 101;
}

bool Player::GetIsAttacking(){
    return isAttacking;
}
void Player::SetIsAttacking(bool b){
    if(b && attackCooldown >= 400){
        isAttacking = b;
        return;
    }
    isAttacking = false;
    if(!b){
        attackCooldown = 0;
        attackAnimationValue = 0;
    }
}

bool Player::GetIsBlocking(){
    return isBlocking;
}
void Player::SetIsBlocking(bool b){
    isBlocking = b;
}