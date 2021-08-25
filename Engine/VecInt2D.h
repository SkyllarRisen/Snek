#pragma once

struct VecInt2D
{
public:
    int x;
    int y;

    VecInt2D(int x = 0, int y = 0);

    VecInt2D operator + (const VecInt2D& v) const;
    VecInt2D operator - (const VecInt2D& v) const;
    VecInt2D operator * (const VecInt2D& v) const;
    VecInt2D& operator += (const VecInt2D& v);
    VecInt2D& operator -= (const VecInt2D& v);
    VecInt2D& operator *= (const VecInt2D& v);

    VecInt2D operator * (const int& n) const;
    VecInt2D operator / (const int& n) const;
    VecInt2D& operator *= (const int& n);
    VecInt2D& operator /= (const int& n);
    VecInt2D operator-() const;

    bool operator == (const VecInt2D& v);

};

namespace Vectors
{
    static const VecInt2D eX(1,0);
    static const VecInt2D eY(0,1);
}