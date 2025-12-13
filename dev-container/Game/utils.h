#ifndef _UTILS_H_
#define _UTILS_H_

#include "drivers/PortSerie.h"
#include "sextant/types.h"

/*class FixFloat{
public:
    FixFloat();
    FixFloat(int vint);

    int GetRealValue() const;
    void SetValue(int vint);

    void Decrease(const FixFloat& f);
    void Cap(const FixFloat& f);

    FixFloat operator+(FixFloat& f) const;
    FixFloat operator+(int vint) const;
    FixFloat& operator+=(FixFloat& f);
    FixFloat& operator+=(int vint);
    friend FixFloat operator-(FixFloat& f1, FixFloat& f2);
    friend FixFloat operator-(FixFloat& f, int vint);
    FixFloat& operator-=(FixFloat& f);
    FixFloat& operator-=(int vint);
    friend FixFloat operator*(FixFloat& f1, FixFloat& f2);
    friend FixFloat operator*(FixFloat& f, int vint);
    FixFloat& operator=(const FixFloat& f);
    FixFloat& operator=(const int& vint);

    friend bool operator<(const FixFloat&, const FixFloat&);

private:
    int val;
};*/

struct vec2{
    vec2() : x(0), y(0) {}
    vec2(int l_x, int l_y) : x(l_x), y(l_y){}

    /*bool operator==(const vec2& v )const{
        return x == v.x && y == v.y;
    }
    bool operator!=(const vec2& v )const{
        x != v.x || y != v.y;
    }*/

    int x;
    int y;
};

struct Test{
    Test() : pos(), size(){}
    Test(vec2 p, vec2 s) : pos(p), size(s){}

    vec2 pos;
    vec2 size;
};

struct IntRect{
    IntRect(): pos(), size(){}
    IntRect(vec2 p, vec2 s) : pos(p), size(s){}

    //Return if this int rect contain the vector
    bool Contains(vec2 v);
    //Return if the other int rect intersects with this one 
    bool Intersect(IntRect r);

    vec2 pos;
    vec2 size;
};

void IntDepletion(int& i, int depl);
void Vec2Depletion(vec2& v, vec2 depl);

void CapInt(int& i, int cap);
void CapVec2(vec2& v, vec2 cap);

#endif