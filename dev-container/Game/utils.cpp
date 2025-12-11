#include "Game/utils.h"

/*-------FixFloat-------*/
FixFloat::FixFloat() : val(0){
}
FixFloat::FixFloat(int vint) : val(vint){
}

int FixFloat::GetRealValue() const{
    return val / 1000;
}

void FixFloat::SetValue(int vint){
    val = vint;
}

void FixFloat::Cap(const FixFloat& f){
    if(val >= 0){
        val = (val > f.val ? f.val : val);
    }
    else{
        val = (-val > f.val ? -f.val : val);
    }
}

void FixFloat::Decrease(const FixFloat& f){
    if(val >= 0){
        val -= f.val;
        val = (val < 0 ? 0 : val);
    }
    else{
        val += f.val;
        val = (val > 0 ? 0 : val);
    }
}

FixFloat FixFloat::operator+(FixFloat& f) const{
    return FixFloat(val + f.val);
}

FixFloat FixFloat::operator+(int vint) const{
    return FixFloat(val + vint * 1000);
}

FixFloat& FixFloat::operator+=(FixFloat& f){
    val += f.val;
    return *this;
}
FixFloat& FixFloat::operator+=(int vint){
    val += vint * 1000;
    return *this;
}

FixFloat operator-(FixFloat& f1, FixFloat& f2){
    return FixFloat(f1.val - f2.val);
}

FixFloat operator-(FixFloat& f, int vint){
    return FixFloat(f.val - vint * 1000);
}

FixFloat& FixFloat::operator-=(FixFloat& f){
    val -= f.val;
    return *this;
}
FixFloat& FixFloat::operator-=(int vint){
    val -= vint * 1000;
    return *this;
}

FixFloat operator*(FixFloat& f1, FixFloat& f2){
    int mul = f1.val * f2.val / 1000;
    return FixFloat(mul == 0 ? FixFloat(f1.val) : FixFloat(mul));
}

FixFloat operator*(FixFloat& f, int vint){
    return FixFloat(f.val * vint);
}

FixFloat& FixFloat::operator=(const FixFloat& f){
    val = f.val;
    return *this;
}

FixFloat& FixFloat::operator=(const int& vint){
    val = vint * 10000;
    return *this;
}

bool operator<(const FixFloat& f1, const FixFloat& f2){
    return f1.val < f2.val;
}

/*-------vec2f-------*/

vec2f::vec2f(int l_x, int l_y)
    : x(l_x), y(l_y){}