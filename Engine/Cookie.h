#pragma once

#include "Entity.h"
#include "Board.h"
#include "Colors.h"
#include <random>

class Cookie : public Entity
{
public:

    Cookie(Board& board);
    void Draw() const;
    void Spawn();

private:
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<int> xDistr;
    std::uniform_int_distribution<int> yDistr;

    Board& board;
    Sprite cookieSprite;
    Color c;


};