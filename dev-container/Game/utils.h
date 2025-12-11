#ifndef _UTILS_H_
#define _UTILS_H_

#include "drivers/PortSerie.h"
#include "sextant/types.h"

class FixFloat{
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
};

struct vec2f{
    vec2f(int l_x, int l_y);

    FixFloat x;
    FixFloat y;
};

#endif