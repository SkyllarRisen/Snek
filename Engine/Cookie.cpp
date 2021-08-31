#include "Cookie.h"
#include "Board.h"


Cookie::Cookie(Board& board)
    :
    Entity(),
    gen(rd()),
    xDistr(0,board.Width()-1),
    yDistr(0,board.Height()-1),
    cookieSprite(Sprites::Cookie),
    c(Colors::Yellow),
    board(board)
{
    Spawn();
}

void Cookie::Draw() const
{
    board.Draw(cookieSprite, Pos(), c);
}

void Cookie::Spawn()
{
    VecInt2D tmpVec = { xDistr(gen), yDistr(gen) };
    while (board.TileIsOccupied(tmpVec))
    {
        tmpVec = { xDistr(gen), yDistr(gen) };            
    }
    Pos(tmpVec);
}
