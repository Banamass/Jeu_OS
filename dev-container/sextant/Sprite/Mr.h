#ifndef  MR_H
#define  MR_H

#define  MR_WIDTH  82
#define  MR_HEIGHT 51

unsigned char* getMrAction(int action);

extern unsigned char sprite_mr_idle[ MR_WIDTH* MR_HEIGHT];
extern unsigned char sprite_mr_walk[ MR_WIDTH* MR_HEIGHT];
extern unsigned char sprite_mr_block[ MR_WIDTH* MR_HEIGHT];
extern unsigned char sprite_mr_attack1[ MR_WIDTH* MR_HEIGHT];
extern unsigned char sprite_mr_attack2[ MR_WIDTH* MR_HEIGHT];
extern unsigned char sprite_mr_jump[ MR_WIDTH* MR_HEIGHT];

#endif