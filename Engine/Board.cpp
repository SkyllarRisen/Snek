#include "Board.h"
#include "VecInt2D.h"
#include "Sprite.h"

Board::Board(Graphics& gfx)
    :
    Entity({0,0}, {0,0}),
    gfx(gfx),
    boardDim({ 16*2,9*2 }),
    isOccupied(boardDim.x * boardDim.y, false)

{
    VecInt2D screenDim(Graphics::ScreenWidth, Graphics::ScreenHeight);
    Pos((screenDim-boardDim*tileDim)/2);
}

void Board::Draw(const Sprite& sprite, const VecInt2D& gridPos, const Color c, const VecInt2D& velVec) const
{
    gfx.DrawSprite(sprite.getSprite(velVec), Pos() + gridPos*tileDim, c);
}

void Board::Draw() const
{
    gfx.DrawRectDim(Pos().x - borderWidth.x, Pos().y - borderWidth.y, Width()*tileDim + borderWidth.x * 2, Height()*tileDim + borderWidth.y * 2, Colors::White);
    gfx.DrawRectDim(Pos().x, Pos().y, Width()*tileDim, Height()*tileDim, Colors::Black);
    //for (int i = 0; i<isOccupied.size();++i)
    //{
    //    if (isOccupied.at(i))
    //    {
    //        VecInt2D gridPos = { i % boardDim.x,i / boardDim.x };
    //        DrawRect(gridPos, Colors::Red);
    //    }
    //    else
    //    {
    //        VecInt2D gridPos = { i % boardDim.x,i / boardDim.x };
    //        DrawRect(gridPos, Colors::Blue);
    //    }
    //}
}

void Board::DrawRect(const VecInt2D& pos, const Color c) const
{
    VecInt2D tileVec = Pos() + pos * tileDim;
    gfx.DrawRectDim(tileVec.x, tileVec.y, tileDim, tileDim, c);
}

int Board::Width() const
{
    return boardDim.x;
}

int Board::Height() const
{
    return boardDim.y;
}

void Board::ResetTile(const VecInt2D& gridPos)
{
    isOccupied.at(gridPos.y * boardDim.x + gridPos.x) = false;
}

void Board::setTileOccupied(const VecInt2D& gridPos)
{
    isOccupied.at(gridPos.y * boardDim.x + gridPos.x) = true;
}

bool Board::TileIsOccupied(const VecInt2D& gridPos) const
{
    return isOccupied.at(gridPos.y * boardDim.x + gridPos.x);
}

