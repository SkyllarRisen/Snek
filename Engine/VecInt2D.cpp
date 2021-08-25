#include "VecInt2D.h"

VecInt2D::VecInt2D(int x, int y)
    :
    x(x), 
    y(y)
{
}

VecInt2D VecInt2D::operator+(const VecInt2D& v) const
{
    return { x + v.x, y + v.y };
}

VecInt2D VecInt2D::operator-(const VecInt2D& v) const
{
    return { x - v.x, y - v.y };
}

VecInt2D VecInt2D::operator*(const VecInt2D& v) const
{
    return { x * v.x, y * v.y };
}

VecInt2D& VecInt2D::operator+=(const VecInt2D & v)
{
    x += v.x;
    y += v.y;
    return *this;
}

VecInt2D& VecInt2D::operator-=(const VecInt2D & v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

VecInt2D& VecInt2D::operator*=(const VecInt2D& v)
{
    x *= v.x;
    y *= v.y;
    return *this;
}

VecInt2D VecInt2D::operator*(const int& n) const
{
    return { x * n, y * n };
}

VecInt2D VecInt2D::operator/(const int& n) const
{
    return { x / n, y / n };
}

VecInt2D& VecInt2D::operator*=(const int& n)
{
    x *= n;
    y *= n;
    return *this;
}

VecInt2D& VecInt2D::operator/=(const int& n)
{
    x /= n;
    y /= n;
    return *this;
}

VecInt2D VecInt2D::operator -() const
{
    return { -x,-y };
}

bool VecInt2D::operator==(const VecInt2D& v)
{
    return x == v.x && y == v.y;
}
