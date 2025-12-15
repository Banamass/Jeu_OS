#ifndef MARIO_H
#define MARIO_H

#define MARIO_WIDTH  44
#define MARIO_HEIGHT 40
#define MARIO_FOOT_LEFT 1
#define MARIO_FOOT_RIGHT 23

unsigned char* getMarioAction(int action);

extern unsigned char sprite_mario_idle[MARIO_WIDTH*MARIO_HEIGHT];
extern unsigned char sprite_mario_walk[MARIO_WIDTH*MARIO_HEIGHT];
extern unsigned char sprite_mario_block[MARIO_WIDTH*MARIO_HEIGHT];
extern unsigned char sprite_mario_attack1[MARIO_WIDTH*MARIO_HEIGHT];
extern unsigned char sprite_mario_attack2[MARIO_WIDTH*MARIO_HEIGHT];
extern unsigned char sprite_mario_jump[MARIO_WIDTH*MARIO_HEIGHT];

#endif