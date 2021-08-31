#include "Obstacle.h"

Obstacle::Obstacle(const Obstacle& o)
    :
    Entity(o.Pos(),o.Vel()),
    gen(rd()),
    xDistr(o.xDistr),
    yDistr(o.yDistr),
    c(o.c),
    board(o.board),
    snekPos(o.snekPos)
{
    VecInt2D tmpVec = { xDistr(gen), yDistr(gen) };
    VecInt2D inFront = snekPos + VecInt2D(1, 0);
    VecInt2D inFront2 = snekPos + VecInt2D(2, 0);
    while (board.TileIsOccupied(tmpVec) || tmpVec == inFront || tmpVec == inFront2)
    {
        tmpVec = { xDistr(gen), yDistr(gen) };
    }
    Pos(tmpVec);
    board.setTileOccupied(tmpVec);
}

Obstacle::Obstacle(Board& board, const VecInt2D& snekPos)
    :
    Entity(),
    snekPos(snekPos),
    gen(rd()),
    xDistr(0, board.Width() - 1),
    yDistr(0, board.Height() - 1),
    c(Colors::White),
    board(board)
{
    //VecInt2D tmpVec = { xDistr(gen), yDistr(gen) };
    //while (board.TileIsOccupied(tmpVec))
    //{
    //    tmpVec = { xDistr(gen), yDistr(gen) };
    //}
    //Pos(tmpVec);
    //board.setTileOccupied(tmpVec);
}

void Obstacle::Draw() const
{
    if(board.TileIsOccupied(Pos()))
        board.DrawRect(Pos(), c);
}
