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

    bool Contains(vec2 v){
        return (v.x >= pos.x && v.x < pos.x + size.x
            && v.y >= pos.y && v.y < pos.y + size.y);
    }
    bool Intersect(void* rp){
        IntRect* r = (IntRect*) rp;
        return !(pos.x >= r->pos.x + r->size.x
            || r->pos.x >= pos.x + size.x
            || pos.y >= r->pos.y + r->size.y
            || r->pos.y >= pos.y + size.y);
    }

    vec2 pos;
    vec2 size;
};

void IntDepletion(int& i, int depl);
void Vec2Depletion(vec2& v, vec2 depl);

void CapInt(int& i, int cap);
void CapVec2(vec2& v, vec2 cap);

#endif