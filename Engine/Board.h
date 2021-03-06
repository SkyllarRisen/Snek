#pragma once

#include "Entity.h"
#include "Graphics.h"
#include "Colors.h"



class Board : public Entity
{
public:

    Board::Board(Graphics& gfx);
    void Draw(const Sprite& sprite, const VecInt2D& gridPos = { 0,0 }, const Color c = Colors::White, const VecInt2D& velVec = -Vectors::eY) const;
    void Draw();
    int Width() const;
    int Height() const;
    void ResetTile(const VecInt2D& gridPos);
    void setTileOccupied(const VecInt2D& gridPos);
    bool TileIsOccupied(const VecInt2D& gridPos) const;

private:

    const int tileDim = 20;
    const VecInt2D boardDim;
    Graphics& gfx;
    const VecInt2D borderWidth = {2,2};
    std::vector<bool> isOccupied;
    
};