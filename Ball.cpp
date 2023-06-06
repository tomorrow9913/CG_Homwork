#pragma once

#include <GL/glut.h>
#include "Ball.h"
#include "Common.h"

void Ball::SetBallSpeed(float x, float y)
{
	v.x = x;
	v.y = y;
}

void Ball::CotrolBallSpeed(float mul)
{
	v.x *= mul;
	v.y *= mul;
}

void Ball::DrawBall()
{
	float   delta;

	delta = 2 * PI / polygon_num;
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < polygon_num; i++)
		glVertex2f(pos.x + radius * cos(delta * i), pos.y + radius * sin(delta * i));
	glEnd();
}

void Ball::MoveBall()
{
	pos.x += v.x;
	pos.y += v.y;
}
