#ifndef MARIO_H
#define MARIO_H

#define MARIO_WIDTH  44
#define MARIO_HEIGHT 40
#define MARIO_FOOT_LEFT 7
#define MARIO_FOOT_RIGHT 27

#define MARIO_ORIGINE_X_ATT1 15 //10+5
#define MARIO_X_ATT1 22
#define MARIO_ORIGINE_X_ATT2 19 //14+5
#define MARIO_X_ATT2 19
#define MARIO_Y_ATT1 33
#define MARIO_Y_ATT2 37

#define MARIO_CHAR_HEIGHT 35
#define MARIO_CHAR_WIDTH 24


unsigned char* getMarioAction(int action);

extern unsigned char sprite_mario_idle[MARIO_WIDTH*MARIO_HEIGHT];
extern unsigned char sprite_mario_walk[MARIO_WIDTH*MARIO_HEIGHT];
extern unsigned char sprite_mario_block[MARIO_WIDTH*MARIO_HEIGHT];
extern unsigned char sprite_mario_attack1[MARIO_WIDTH*MARIO_HEIGHT];
extern unsigned char sprite_mario_attack2[MARIO_WIDTH*MARIO_HEIGHT];
extern unsigned char sprite_mario_jump[MARIO_WIDTH*MARIO_HEIGHT];

#endif