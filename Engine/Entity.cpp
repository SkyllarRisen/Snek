#include "Entity.h"
#include "VecInt2D.h"

Entity::Entity(const VecInt2D pos, const VecInt2D vel)
    :
    pos(pos),
    vel(vel)
{
}

int Entity::PosX() const
{
    return pos.x;
}

int Entity::PosY() const
{
    return pos.y;
}

VecInt2D Entity::Pos() const
{
    return pos;
}

int Entity::VelX() const
{
    return vel.x;
}

int Entity::VelY() const
{
    return vel.y;
}

VecInt2D Entity::Vel() const
{
    return vel;
}

void Entity::PosX(const int posX)
{
    pos.x = posX;
}

void Entity::PosY(const int posY)
{
    pos.y = posY;
}

void Entity::Pos(VecInt2D posVec)
{
    pos = posVec;
}

void Entity::VelX(const int velX)
{
    vel.x = velX;
}

void Entity::VelY(const int velY)
{
    vel.y = velY;
}

void Entity::Vel(const VecInt2D velVec)
{
    vel = velVec;
}


