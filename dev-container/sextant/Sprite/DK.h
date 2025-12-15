#ifndef DK_H
#define DK_H

#define DK_WIDTH  93
#define DK_HEIGHT 47
#define DK_FOOT_LEFT 11
#define DK_FOOT_RIGHT 62

unsigned char* getDKAction(int action);

extern unsigned char sprite_dk_idle[DK_WIDTH*DK_HEIGHT];
extern unsigned char sprite_dk_walk[DK_WIDTH*DK_HEIGHT];
extern unsigned char sprite_dk_block[DK_WIDTH*DK_HEIGHT];
extern unsigned char sprite_dk_attack1[DK_WIDTH*DK_HEIGHT];
extern unsigned char sprite_dk_attack2[DK_WIDTH*DK_HEIGHT];
extern unsigned char sprite_dk_jump[DK_WIDTH*DK_HEIGHT];

#endif