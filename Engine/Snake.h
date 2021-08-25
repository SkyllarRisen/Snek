#pragma once

#include "Entity.h"
#include "VecInt2D.h"
#include "Colors.h"
#include "Board.h"
#include "Cookie.h"
#include <vector>

class Snake : public Entity
{
public:
    //Classes

    //Methods
    Snake(Board& board, VecInt2D pos, VecInt2D initVel);

    
    bool MoveHead(const VecInt2D& moveCache);
    void Grow();
    void Draw() const;
    void Eat(Cookie& cookie);

    //Members

private:

    //Classes
    class Segment
    {
    public:

        Segment(VecInt2D pos = { 0,0 }, bool evenNumberSegment=false, bool fHead = false);
        void MoveHead(const VecInt2D dir, Board& board);
        void Follow( const Segment& prevSeg );
        void Draw(Board& board, const VecInt2D& vel) const;
        VecInt2D Pos() const;

    private:

        void Clamp(const Board& board);

        VecInt2D pos;
        Color c;
        bool fHead;
        

    };

    //Methods

    //Members
    Board& board;

    static constexpr Color headColor = Colors::Green;
    static constexpr Color bodyColor1 = Colors::Green;
    static constexpr Color bodyColor0 = Colors::DarkGreen;
    std::vector<Segment> SnakeSegments;

};