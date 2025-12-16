#ifndef DK_H
#define DK_H

#define DK_WIDTH  93
#define DK_HEIGHT 47
#define DK_FOOT_LEFT 17 // 14+3
#define DK_FOOT_RIGHT 69

#define DK_ORIGINE_X_ATT1 28 // 23+5
#define DK_ORIGINE_X_ATT2 31 // 26+5
#define DK_X_ATT1 14
#define DK_X_ATT2 45

#define DK_CHAR_HEIGHT 44
#define DK_CHAR_WIDTH 38

unsigned char* getDKAction(int action);

extern unsigned char sprite_dk_idle[DK_WIDTH*DK_HEIGHT];
extern unsigned char sprite_dk_walk[DK_WIDTH*DK_HEIGHT];
extern unsigned char sprite_dk_block[DK_WIDTH*DK_HEIGHT];
extern unsigned char sprite_dk_attack1[DK_WIDTH*DK_HEIGHT];
extern unsigned char sprite_dk_attack2[DK_WIDTH*DK_HEIGHT];
extern unsigned char sprite_dk_jump[DK_WIDTH*DK_HEIGHT];

#endif