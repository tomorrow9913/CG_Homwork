#pragma once

#include <GL/glut.h>

#include "Common.h"

class Ball
{
public:
	Point position;
	Velocity velocity;
	float radius;

	Ball(float x, float y, float radius, float v_x, float v_y);
	void DrawBall();
};