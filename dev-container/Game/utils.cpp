#include "Game/utils.h"

/*-------vec2f-------*/

/*-------IntRect-------*/

bool Intersect(IntRect& r1, IntRect& r2){
    return !(r1.pos.x >= r2.pos.x + r2.size.x
        || r2.pos.x >= r1.pos.x + r1.size.x
        || r1.pos.y >= r2.pos.y + r2.size.y
        || r2.pos.y >= r1.pos.y + r1.size.y);
}

void IntDepletion(int& i, int depl){
    if(i > 0)
        i = i > depl ? i - depl : 0;
    else
        i = i < -depl ? i + depl : 0;
}
void Vec2Depletion(vec2& v, vec2 depl){
    IntDepletion(v.x, depl.x);
    IntDepletion(v.y, depl.y);
}

void CapInt(int& i, int cap){
     if(i > 0)
        i = i > cap ? cap : i;
    else
        i = i < -cap ? -cap : i;
}
void CapVec2(vec2& v, vec2 cap){
    CapInt(v.x, cap.x);
    CapInt(v.y, cap.y);
}