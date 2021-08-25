#include "Snake.h"

#include "VecInt2D.h"
#include "Board.h"
#include "Colors.h"

#include <vector>
#include <math.h>
#include <assert.h>

Snake::Snake(Board& board, VecInt2D pos, VecInt2D initVel)
    :
    Entity(pos, initVel),
    board(board),
    SnakeSegments({ Segment(pos,false,true), Segment(pos-Vectors::eX,true), Segment(pos- Vectors::eX * 2) })
{
    assert(PosX() >= 0);
    assert(PosY() >= 0);
}


bool Snake::MoveHead(const VecInt2D& moveCache)
{
    Vel(moveCache);
    board.ResetTiles();
    for (int i = SnakeSegments.size() - 1;i>0;--i)
    {
        SnakeSegments.at(i).Follow(SnakeSegments.at(i - 1));
        board.setTileOccupied(SnakeSegments.at(i-1).Pos());
    }
    SnakeSegments.at(0).MoveHead(Vel(), board);
    Pos(SnakeSegments.at(0).Pos());
    for (int i = 1; i < SnakeSegments.size(); ++i)
    {
        if (Pos() == SnakeSegments.at(i).Pos())
            return false;
    }
    return true;
}

void Snake::Grow()
{
    bool evenNumberSegment;
    if (SnakeSegments.size() % 2)
        evenNumberSegment = true;
    else
        evenNumberSegment = false;
    SnakeSegments.push_back(Segment(SnakeSegments.at(1).Pos(), evenNumberSegment));
}

void Snake::Draw() const
{
    for (int i = SnakeSegments.size()-1; i >=0 ; --i)
        SnakeSegments.at(i).Draw(board, Vel());
}

void Snake::Eat(Cookie& cookie)
{
    if (cookie.Pos() == Pos())
    {
        cookie.Spawn();
        Grow();
    }
}

Snake::Segment::Segment(VecInt2D pos, bool evenNumberSegment, bool fHead)
    :
    pos(pos),
    fHead(fHead)
{
    if (fHead)
        c = headColor;
    else
    {
        if (evenNumberSegment)
            c = bodyColor0;
        else
            c = bodyColor1;
    }
}

void Snake::Segment::MoveHead(const VecInt2D dir, Board& board)
{
    assert(fHead);
    assert(abs(dir.x) + abs(dir.y) == 1);
    pos += dir;
    Clamp(board);
    board.setTileOccupied(pos);
    
}

void Snake::Segment::Follow(const Segment& prevSeg)
{
    pos = prevSeg.pos;
}

void Snake::Segment::Draw(Board& board, const VecInt2D& vel) const
{
    if (fHead)
    {
        Sprite SHS1(Sprites::SnakeHead1), SHS2(Sprites::SnakeHead2);
        board.Draw(SHS1, pos, c, vel);
        board.Draw(SHS2, pos, Colors::Red, vel);
    }

    else
    {
        Sprite SBS(Sprites::SnakeBody);
        board.Draw(SBS, pos, c);
    }
}

VecInt2D Snake::Segment::Pos() const
{
    return pos;
}

void Snake::Segment::Clamp(const Board& board)
{

    if (pos.x >= board.Width()-1)
        pos.x -= board.Width();
    if (pos.x < 0)
        pos.x += board.Width();
    if (pos.y >= board.Height()-1)
        pos.y -= board.Height();
    if (pos.y < 0)
        pos.y += board.Height();

}
