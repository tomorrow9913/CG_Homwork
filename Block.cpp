#pragma once

#include "Ball.h"
#include "Block.h"
#include "Common.h"

Block::Block(float x, float y, int width, int height) : position(x, y), width(width), height(height) {
	hit = false;
}

void Block::DrawBlock() {
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);

	glVertex2f(this->position.x - B_width, this->position.y + B_height);
	glVertex2f(this->position.x - B_width, this->position.y - B_height);
	glVertex2f(this->position.x + B_width, this->position.y - B_height);
	glVertex2f(this->position.x + B_width, this->position.y + B_height);

	glEnd();

}
bool Block::isHit() {
	return this->hit;
}
void Block::Collision_Detection_Between_Blocks(Ball ball) {
	if (ball.position.x + ball.radius >= this->position.x - B_width - ball.radius
		&& ball.position.x - ball.radius <= this->position.x + B_width + ball.radius)
	{
		if (ball.position.y + ball.radius >= this->position.y - B_height - ball.radius
			&& ball.position.y - ball.radius <= this->position.y + B_height + ball.radius)
		{
			ball.velocity.y *= -1.0;
			ball.velocity.x *= -1.0;
			this->hit = true;

		}
	}
}