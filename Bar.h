#pragma once
#include "Common.h"
#include "Point.h"

class Bar
{
public:
    Bar(float x = WIDTH / 2, float y = HEIGHT / 5, float w = 300, float h = 25)
        : pos(x, y), bar_width(w), bar_height(h) {}
    void draw_bar();
    float bar_width, bar_height;
    Point pos;
};
