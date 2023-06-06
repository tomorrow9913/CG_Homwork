#include <GL/glut.h>

#include "Brick.h"
#include "Common.h"

void Brick::DrawBrick()
{
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(pos.x, HEIGHT - pos.y);
	glVertex2f(pos.x + brick_width, HEIGHT - pos.y);
	glVertex2f(pos.x + brick_width, HEIGHT - (pos.y + brick_height));
	glVertex2f(pos.x, HEIGHT - (pos.y + brick_height));
	glEnd();
}

void Brick::Collision_Detection(Ball* ball)
{
	Point p1, p2;
	p1.change(pos.x, pos.y);
	p2.change(pos.x + brick_width, pos.y);
	if (ball->pos.point_to_segment(p1, p2) <= ball->radius) // 위쪽 벽
	{
		ball->v.y = -1 * ball->v.y;
		ball->pos.y = pos.y + brick_height + ball->radius;
		brickLife--;
	}
	p1.change(pos.x + brick_width, pos.y);
	p2.change(pos.x + brick_width, pos.y + brick_height);
	if (ball->pos.point_to_segment(p1, p2) <= ball->radius) // 오른쪽 벽
	{
		ball->v.x = -1 * ball->v.x;
		ball->pos.x = pos.x + brick_width + ball->radius;
		brickLife--;
	}
	p1.change(pos.x, pos.y + brick_height);
	p2.change(pos.x + brick_width, pos.y + brick_height);
	if (ball->pos.point_to_segment(p1, p2) <= ball->radius) // 아래쪽 벽
	{
		ball->v.y = -1 * ball->v.y;
		ball->pos.y = pos.y - ball->radius;
		brickLife--;
	}
	p1.change(pos.x, pos.y);
	p2.change(pos.x, pos.y + brick_height);
	if (ball->pos.point_to_segment(p1, p2) <= ball->radius) // 왼쪽 벽
	{
		ball->v.x = -1 * ball->v.x;
		ball->pos.x = pos.x - ball->radius;
		brickLife--;
	}
	if (brickLife == 0) {
		pos.change(-100, -100);
	}
}
