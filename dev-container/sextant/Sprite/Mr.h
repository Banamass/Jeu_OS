#ifndef  MR_H
#define  MR_H

#define MR_WIDTH  82
#define MR_HEIGHT 51
#define MR_FOOT_LEFT 36
#define MR_FOOT_RIGHT 36

#define MR_X_ATT1 19
#define MR_ORIGINE_X_ATT1 16 //11+5
#define MR_ORIGINE_X_ATT2 -36//-41+5
#define MR_X_ATT2 82

#define MR_CHAR_HEIGHT 47
#define MR_CHAR_WIDTH 40


unsigned char* getMrAction(int action);

extern unsigned char sprite_mr_idle[ MR_WIDTH* MR_HEIGHT];
extern unsigned char sprite_mr_walk[ MR_WIDTH* MR_HEIGHT];
extern unsigned char sprite_mr_block[ MR_WIDTH* MR_HEIGHT];
extern unsigned char sprite_mr_attack1[ MR_WIDTH* MR_HEIGHT];
extern unsigned char sprite_mr_attack2[ MR_WIDTH* MR_HEIGHT];
extern unsigned char sprite_mr_jump[ MR_WIDTH* MR_HEIGHT];

#endif