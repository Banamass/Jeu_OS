#ifndef YOSHI_H
#define YOSHI_H

#define YOSHI_WIDTH  88
#define YOSHI_HEIGHT 47
#define YOSHI_FOOT_LEFT 15
#define YOSHI_FOOT_RIGHT 63

#define YOSHI_X_ATT1 27
#define YOSHI_ORIGINE_X_ATT 20 // 15+5
#define YOSHI_X_ATT2 53
#define YOSHI_Y_ATT 37

#define YOSHI_CHAR_WIDTH 40


unsigned char* getYoshiAction (int action);

extern unsigned char sprite_yoshi_idle[YOSHI_WIDTH*YOSHI_HEIGHT];
extern unsigned char sprite_yoshi_walk[YOSHI_WIDTH*YOSHI_HEIGHT];
extern unsigned char sprite_yoshi_block[YOSHI_WIDTH*YOSHI_HEIGHT];
extern unsigned char sprite_yoshi_attack1[YOSHI_WIDTH*YOSHI_HEIGHT];
extern unsigned char sprite_yoshi_attack2[YOSHI_WIDTH*YOSHI_HEIGHT];
extern unsigned char sprite_yoshi_jump[YOSHI_WIDTH*YOSHI_HEIGHT];

#endif