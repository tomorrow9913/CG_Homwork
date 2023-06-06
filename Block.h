#pragma once

#include "Common.h"
#include "Ball.h"

#define	B_width 		20
#define	B_height		20

class Block
{
	Point position;
	float width;
	float height;
	int blockLife;

public:
	Block(float x, float y, int width = B_width, int height = B_height, int hit = -1);
	void DrawBlock();
	bool isHit();
	void Collision_Detection_Between_Blocks(Ball* ball);
};
