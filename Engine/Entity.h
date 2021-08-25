#pragma once

#include "VecInt2D.h"

class Entity
{
public:

    Entity(const VecInt2D pos = { 0,0 }, const VecInt2D vel = { 0,0 });

    int PosX() const;
    int PosY() const;
    VecInt2D Pos() const;

    int VelX() const;
    int VelY() const;
    VecInt2D Vel() const;

protected:

    void PosX(const int posX);
    void PosY(const int posY);
    void Pos(VecInt2D posVec);

    void VelX(const int velX);
    void VelY(const int velY);
    void Vel(const VecInt2D velVec);

private:

    VecInt2D pos;
    VecInt2D vel;

};