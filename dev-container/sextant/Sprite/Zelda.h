#ifndef ZELDA_H
#define ZELDA_H

#define ZELDA_WIDTH  56
#define ZELDA_HEIGHT 67
#define ZELDA_FOOT_LEFT 7
#define ZELDA_FOOT_RIGHT 39

#define ZELDA_X_ATT1 26
#define ZELDA_ORIGINE_X_ATT 20 // 15+5
#define ZELDA_X_ATT2 29
#define ZELDA_Y_ATT1 50

#define ZELDA_CHAR_HEIGHT 47
#define ZELDA_CHAR_WIDTH 24

unsigned char* getZeldaAction (int action);

extern unsigned char sprite_zelda_idle[ZELDA_WIDTH*ZELDA_HEIGHT];
extern unsigned char sprite_zelda_walk[ZELDA_WIDTH*ZELDA_HEIGHT];
extern unsigned char sprite_zelda_attack1[ZELDA_WIDTH*ZELDA_HEIGHT];
extern unsigned char sprite_zelda_attack2[ZELDA_WIDTH*ZELDA_HEIGHT];
extern unsigned char sprite_zelda_block[ZELDA_WIDTH*ZELDA_HEIGHT];
extern unsigned char sprite_zelda_jump[ZELDA_WIDTH*ZELDA_HEIGHT];

#endif