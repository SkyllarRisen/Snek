#include "Obstacle.h"

Obstacle::Obstacle(const Obstacle& o)
    :
    Entity(o.Pos(),o.Vel()),
    c(o.c),
    board(o.board)
{
}

Obstacle::Obstacle(Board& board, const VecInt2D& snekPos, const VecInt2D& snekVel, const VecInt2D& foodPos)
    :
    Entity(),
    snekPos(snekPos),
    gen(rd()),
    xDistr(0, board.Width() - 1),
    yDistr(0, board.Height() - 1),
    c(Colors::White),
    board(board),
    foodPos(foodPos)
{
    VecInt2D tmpVec = { xDistr(gen), yDistr(gen) };
    VecInt2D inFront = snekPos + snekVel;
    VecInt2D inFront2 = inFront + snekVel;
    while (board.TileIsOccupied(tmpVec) || tmpVec == inFront || tmpVec == inFront2 || tmpVec == foodPos)
    {
        tmpVec = { xDistr(gen), yDistr(gen) };
    }
    Pos(tmpVec);
    board.setTileOccupied(tmpVec);
}

void Obstacle::Draw() const
{
    if(board.TileIsOccupied(Pos()))
        board.DrawRect(Pos(), c);
}
