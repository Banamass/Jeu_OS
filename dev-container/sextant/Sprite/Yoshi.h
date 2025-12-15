#ifndef YOSHI_H
#define YOSHI_H

#define YOSHI_WIDTH  88
#define YOSHI_HEIGHT 47
#define YOSHI_FOOT_LEFT 3
#define YOSHI_FOOT_RIGHT 62

unsigned char* getYoshiAction (int action);

extern unsigned char sprite_yoshi_idle[YOSHI_WIDTH*YOSHI_HEIGHT];
extern unsigned char sprite_yoshi_walk[YOSHI_WIDTH*YOSHI_HEIGHT];
extern unsigned char sprite_yoshi_block[YOSHI_WIDTH*YOSHI_HEIGHT];
extern unsigned char sprite_yoshi_attack1[YOSHI_WIDTH*YOSHI_HEIGHT];
extern unsigned char sprite_yoshi_attack2[YOSHI_WIDTH*YOSHI_HEIGHT];
extern unsigned char sprite_yoshi_jump[YOSHI_WIDTH*YOSHI_HEIGHT];

#endif