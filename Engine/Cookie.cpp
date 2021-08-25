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
    bool isOccupied = true;
    VecInt2D tmpVec;
    while (isOccupied)
    {
        isOccupied = false;
        tmpVec = { xDistr(gen), yDistr(gen) };
        for (int i = 0; i < board.GetOccupiedTiles().size(); ++i)
        {
            if (board.GetOccupiedTiles().at(i) == tmpVec)
            {
                isOccupied = true;
                break;
            }
                
        }
    }
    Pos(tmpVec);
}
