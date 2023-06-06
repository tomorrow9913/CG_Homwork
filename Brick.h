#pragma once
#include <memory.h>

#include "Point.h"
#include "Ball.h"

class Brick
{
    float brick_width, brick_height;
    Point pos;
    int brickLife;

public:
    Brick(Point pos, int w = 40, int h = 20, int brickLife = 3) : pos(pos), brick_width(w), brick_height(h), brickLife(brickLife)
    {
        this->pos = pos;
    }

    Brick(int x, int y, int w = 40, int h = 20, int brickLife = 3) :pos(Point(x, y)), brick_width(w), brick_height(h), brickLife(brickLife) {
    }
    void DrawBrick();
    void Collision_Detection(Ball* ball);
};