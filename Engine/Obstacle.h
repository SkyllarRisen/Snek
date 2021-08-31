#pragma once
#include "Entity.h"
#include "Board.h"
#include "Colors.h"
#include <random>


class Obstacle : public Entity

{
public:
    Obstacle(const Obstacle& o);
    Obstacle(Board& board, const VecInt2D& snekPos, const VecInt2D& snekVel, const VecInt2D& foodPos);
    void Draw() const;

private:
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<int> xDistr;
    std::uniform_int_distribution<int> yDistr;

    Board& board;
    Color c;
    VecInt2D snekPos;
    VecInt2D snekVel;
    VecInt2D foodPos;
};

