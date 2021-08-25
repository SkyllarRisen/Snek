#define _USE_MATH_DEFINES

#include "Sprite.h"
#include <math.h>

Sprite::Sprite(const std::vector<std::vector<bool>> pixelMap)
    :
    pixelMap(pixelMap),
    width(pixelMap.at(0).size()),
    height(pixelMap.size())
{
    for (int i = 0; i < pixelMap.size(); ++i)
        assert(pixelMap.at(i).size() == pixelMap.size());
}

std::vector<std::vector<bool>> Sprite::Rotate(double alpha) const
{
    std::vector<std::vector<bool>> rotatedPixelMap = pixelMap;

    double centerX = ((double)width-1) / 2.0, centerY = ((double)height-1) / 2.0;
    for (int y = 0; y < pixelMap.size(); ++y)
    {
        for (int x = 0; x < pixelMap.at(y).size(); ++x)
        {
            double dx = x - centerX;
            double dy = y - centerY;
            double newX = cos(alpha) * dx - sin(alpha) * dy + centerX;
            double newY = sin(alpha) * dx + cos(alpha) * dy + centerY;

            int iX = (int)round(newX);
            int iY = (int)round(newY);

            rotatedPixelMap.at(iY).at(iX) = pixelMap.at(y).at(x);
        }
    }
    return rotatedPixelMap;
}

std::vector<std::vector<bool>> Sprite::getSprite(VecInt2D velVec) const
{
    assert(velVec ==  Vectors::eX 
        || velVec == -Vectors::eX
        || velVec ==  Vectors::eY
        || velVec == -Vectors::eY
        );
    double alpha;
    if (velVec == -Vectors::eY)
        alpha = 0;
    else if (velVec == Vectors::eX)
        alpha = M_PI/2.0;
    else if (velVec == Vectors::eY)
        alpha = M_PI;
    else
        alpha = 3*M_PI/2.0;
    return Rotate(alpha);
}


