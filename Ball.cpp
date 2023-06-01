#pragma once

#include "Ball.h"
#include "Common.h"

Ball::Ball(float x, float y, float radius, float v_x, float v_y) : position(x, y), radius(radius), velocity(v_x, v_y) {}

void Ball::DrawBall() {
	float	delta;

	delta = 2 * PI / polygon_num;
	glBegin(GL_POLYGON);
	for (int i = 0; i < polygon_num; i++)
		glVertex2f(this->position.x + radius * cos(delta * i), this->position.y + radius * sin(delta * i));
	glEnd();
}
