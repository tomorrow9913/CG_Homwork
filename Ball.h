#pragma once
#include "Vector.h"
#include "Point.h"
#include "Common.h"

class Ball
{
public:
    Point pos;
    Vector v;
    float radius;

    //积己磊
    Ball(float x = WIDTH / 2, float y = HEIGHT / 4, float vx = 1.0, float vy = 1.0, float r = 10)
        : pos(x, y), v(vx, vy), radius(r) {}
    
    // 加档力绢 
    void SetBallSpeed(float x, float y);
    void CotrolBallSpeed(float mul);

    // 弊府扁
    void DrawBall();
    void MoveBall();
};