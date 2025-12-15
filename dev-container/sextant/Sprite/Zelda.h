#ifndef ZELDA_H
#define ZELDA_H

#define ZELDA_WIDTH  56
#define ZELDA_HEIGHT 67
#define ZELDA_FOOT_LEFT 8
#define ZELDA_FOOT_RIGHT 33

unsigned char* getZeldaAction (int action);

extern unsigned char sprite_zelda_idle[ZELDA_WIDTH*ZELDA_HEIGHT];
extern unsigned char sprite_zelda_walk[ZELDA_WIDTH*ZELDA_HEIGHT];
extern unsigned char sprite_zelda_attack1[ZELDA_WIDTH*ZELDA_HEIGHT];
extern unsigned char sprite_zelda_attack2[ZELDA_WIDTH*ZELDA_HEIGHT];
extern unsigned char sprite_zelda_block[ZELDA_WIDTH*ZELDA_HEIGHT];
extern unsigned char sprite_zelda_jump[ZELDA_WIDTH*ZELDA_HEIGHT];

#endif