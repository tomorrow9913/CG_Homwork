#pragma once

#include <stdlib.h>
#include "Block.h"
#include "Common.h"

#include <iostream>

using namespace std;

Block::Block(float x, float y, int width, int height, int hit) : position(x, y), width(width), height(height) {
	if(hit < 0)
		this->blockLife = rand() % 6;
	else
		this->blockLife = hit;
}

void Block::DrawBlock() {
	if (!isHit()) return;

	float BlockColor[][3] = {
		{0.0, 0.0, 0.0},
		{1.0, 0.0, 0.0},
		{1.0, 1.0, 0.0},
		{0.0, 1.0, 1.0},
		{0.0, 0.0, 1.0},
		{1.0, 0.0, 1.0},
		{0.0, 1.0, 0.0}
	};

	glColor3f(BlockColor[isHit()][0], BlockColor[isHit()][1], BlockColor[isHit()][2]);
	glBegin(GL_POLYGON);

	glVertex2f(this->position.x - B_width, this->position.y + B_height);
	glVertex2f(this->position.x - B_width, this->position.y - B_height);
	glVertex2f(this->position.x + B_width, this->position.y - B_height);
	glVertex2f(this->position.x + B_width, this->position.y + B_height);

	glEnd();

}
bool Block::isHit() {
	return this->blockLife;
}
void Block::Collision_Detection_Between_Blocks(Ball* ball) {
	if (!isHit()) return;

	float x = ball->position.x;
	float y = ball->position.y;
	float r = ball->radius;

	if (x + r < position.x);


}