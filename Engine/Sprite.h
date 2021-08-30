#pragma once
#include "VecInt2D.h"
#include "Colors.h"
#include <vector>
#include <assert.h>

class Sprite
{
public:

    Sprite(const std::vector<std::vector<bool>> pixelMap);
    
    std::vector<std::vector<bool>> getSprite(VecInt2D velVec = {-1,0}) const;

private:

    std::vector<std::vector<bool>> Rotate(double alpha) const;

    std::vector<std::vector<bool>> pixelMap;
    int width, height;
};

namespace Sprites
{
    const std::vector<std::vector<bool>> SnakeHead1 = {
                                                { 0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0},
                                                { 0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0},
                                                { 0, 0, 0, 0, 0,    0, 1, 1, 1, 1,    1, 1, 1, 1, 0,    0, 0, 0, 0, 0},
                                                { 0, 0, 0, 0, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 0, 0, 0, 0},
                                                { 0, 0, 0, 0, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 0, 0, 0, 0},
                                                                    
                                                { 0, 0, 0, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 0, 0, 0},
                                                { 0, 0, 0, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 0, 0, 0},
                                                { 0, 0, 0, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 0, 0, 0},
                                                { 0, 0, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 0, 0},
                                                { 0, 0, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 0, 0},
                                                                                                                    
                                                { 0, 0, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 0, 0},
                                                { 0, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 0},
                                                { 0, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 0},
                                                { 0, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 0},
                                                { 1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1},

                                                { 1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1},
                                                { 1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1},
                                                { 0, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 0},
                                                { 0, 0, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 0, 0},
                                                { 0, 0, 0, 0, 0,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    0, 0, 0, 0, 0}
                                               };

    const std::vector<std::vector<bool>> SnakeHead2 = {
                                                { 0, 0, 0, 0, 0,    0, 0, 0, 1, 0,    0, 1, 0, 0, 0,    0, 0, 0, 0, 0},
                                                { 0, 0, 0, 0, 0,    0, 0, 0, 1, 1,    1, 1, 0, 0, 0,    0, 0, 0, 0, 0},
                                                { 0, 0, 0, 0, 0,    0, 0, 0, 0, 1,    1, 0, 0, 0, 0,    0, 0, 0, 0, 0},
                                                { 0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0},
                                                { 0, 0, 0, 0, 0,    1, 1, 0, 0, 0,    0, 0, 0, 1, 1,    0, 0, 0, 0, 0},

                                                { 0, 0, 0, 0, 0,    1, 1, 0, 0, 0,    0, 0, 0, 1, 1,    0, 0, 0, 0, 0},
                                                { 0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0},
                                                { 0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0},
                                                { 0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0},
                                                { 0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0},

                                                { 0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0},
                                                { 0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0},
                                                { 0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0},
                                                { 0, 0, 0, 0, 1,    1, 1, 0, 0, 0,    0, 0, 0, 1, 1,    1, 0, 0, 0, 0},
                                                { 0, 0, 0, 1, 1,    1, 1, 1, 0, 0,    0, 0, 1, 1, 1,    1, 1, 0, 0, 0},
                                                                                                        
                                                { 0, 0, 0, 0, 1,    1, 1, 0, 0, 0,    0, 0, 0, 1, 1,    1, 0, 0, 0, 0},
                                                { 0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0},
                                                { 0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0},
                                                { 0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0},
                                                { 0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0,    0, 0, 0, 0, 0}
                                                };

    const std::vector<std::vector<bool>> SnakeBody = {
                                                { 0, 0, 0, 0, 0,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    0, 0, 0, 0, 0},
                                                { 0, 0, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 0, 0},
                                                { 0, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 0},
                                                { 0, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 0},
                                                { 0, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 0},

                                                { 1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1},
                                                { 1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1},
                                                { 1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1},
                                                { 1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1},
                                                { 1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1},

                                                { 1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1},
                                                { 1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1},
                                                { 1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1},
                                                { 1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1},
                                                { 1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1},

                                                { 0, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 0},
                                                { 0, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 0},
                                                { 0, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 0},
                                                { 0, 0, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 0, 0},
                                                { 0, 0, 0, 0, 0,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    0, 0, 0, 0, 0}
                                               };

    const std::vector<std::vector<bool>> Cookie = {
                                                { 0, 0, 0, 0, 0,    0, 1, 1, 1, 1,    1, 1, 1, 1, 0,    0, 0, 0, 0, 0},
                                                { 0, 0, 0, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 0, 0, 0},
                                                { 0, 0, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 0, 0},
                                                { 0, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 0},
                                                { 0, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 0,    1, 1, 1, 1, 0},

                                                { 0, 1, 1, 1, 1,    1, 0, 0, 1, 1,    1, 1, 1, 0, 0,    0, 1, 1, 1, 0},
                                                { 1, 1, 1, 1, 1,    0, 0, 0, 0, 1,    1, 1, 1, 1, 0,    1, 1, 1, 1, 1},
                                                { 1, 1, 1, 1, 1,    0, 0, 0, 0, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1},
                                                { 1, 1, 1, 1, 1,    1, 0, 0, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1},
                                                { 1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1},

                                                { 1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1},
                                                { 1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 0, 0, 0, 1,    1, 1, 1, 1, 1},
                                                { 1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    0, 0, 0, 0, 0,    1, 1, 1, 1, 1},
                                                { 1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    0, 0, 0, 0, 0,    1, 1, 1, 1, 1},
                                                { 0, 1, 1, 1, 1,    1, 1, 1, 1, 1,    0, 0, 0, 0, 0,    1, 1, 1, 1, 0},

                                                { 0, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 0, 0, 0, 1,    1, 1, 1, 1, 0},
                                                { 0, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 0},
                                                { 0, 0, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 0, 0},
                                                { 0, 0, 0, 1, 1,    1, 1, 1, 1, 1,    1, 1, 1, 1, 1,    1, 1, 0, 0, 0},
                                                { 0, 0, 0, 0, 0,    0, 1, 1, 1, 1,    1, 1, 1, 1, 0,    0, 0, 0, 0, 0}
                                                };

    }
