#pragma once
#define _USE_MATH_DEFINES

#include <math.h>
#define	PI				M_PI
#define	polygon_num		50

class Point
{
public:
	float x, y;

	Point(float x, float y) : x(x), y(y) {}
};

typedef Point Velocity;