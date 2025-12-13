#include "Game/utils.h"

/*-------FixFloat-------*/
/*FixFloat::FixFloat() : val(0){
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
*/
/*-------vec2f-------*/



/*-------IntRect-------*/

bool IntRect::Contains(vec2 v){
    return (v.x >= pos.x && v.x < pos.x + size.x
	    && v.y >= pos.y && v.y < pos.y + size.y);
}
bool IntRect::Intersect(IntRect r){
    return !(pos.x >= r.pos.x + r.size.x
        || r.pos.x >= pos.x + size.x
        || pos.y >= r.pos.y + r.size.y
        || r.pos.y >= pos.y + size.y);
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