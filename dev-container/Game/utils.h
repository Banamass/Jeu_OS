#ifndef _UTILS_H_
#define _UTILS_H_

#include "sextant/types.h"

struct vec2{
    vec2() {}
    vec2(int l_x, int l_y) : x(l_x), y(l_y){}

    bool operator==(const vec2& v )const{
        return x == v.x && y == v.y;
    }
    bool operator!=(const vec2& v )const{
        x != v.x || y != v.y;
    }

    int x;
    int y;
};

struct IntRect{
    IntRect(): pos(), size(){}
    IntRect(vec2 p, vec2 s) : pos(p), size(s){}

    vec2 pos;
    vec2 size;
};

bool Intersect(IntRect& r1, IntRect& r2);

void IntDepletion(int& i, int depl);
void Vec2Depletion(vec2& v, vec2 depl);

void CapInt(int& i, int cap);
void CapVec2(vec2& v, vec2 cap);

#endif