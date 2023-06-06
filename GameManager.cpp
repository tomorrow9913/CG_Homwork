#pragma once

#include <vector>
#include <time.h>
#include "Common.h"
#include "Ball.h"
#include "GameManager.h"
#include "Bar.h"
using namespace std;

void GameManager::InitGame() {
	for (auto i : balls) Safe_Delete<Ball*>(i);
	for (auto i : Bricks) Safe_Delete<Brick*>(i);


	Ball* ball = new Ball();
	ball->v.x = 1.0;      
	ball->v.y = sqrt(3);
	ball->pos.change(Point(WIDTH / 2, HEIGHT / 4));
	ball->radius = 10;
	
	balls.push_back(ball);
	
	bar.bar_width = 300;   
	bar.bar_height = 25;

	int brickWidth = 40, brickHeight = 20;

	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
			Bricks.push_back(new Brick(i * brickWidth, j*brickHeight, brickWidth, brickHeight));

}

GameManager::GameManager(int left, int bottom, int width, int height): _left(left), _bottom(bottom), _width(width), _height(height) {
	InitGame();
}

void GameManager::Collision_Detection_to_Walls(void) {
	Point p1, p2;
	for (Ball* ball : this->balls) {
		if (ball->pos.y + ball->radius >= HEIGHT) // 위쪽 벽
		{
			ball->v.y = -1 * ball->v.y;
			ball->pos.y = _height - ball->radius;
		}
		else if (ball->pos.x + ball->radius >= WIDTH) // 오른쪽 벽
		{
			ball->v.x = -1 * ball->v.x;
			ball->pos.x = _width - ball->radius;
		}
		else if (ball->pos.x - ball->radius <= _left) // 왼쪽 벽
		{
			ball->v.x = -1 * ball->v.x;
			ball->pos.x = _left + ball->radius;
		}

		p1.change(bar.pos.x, bar.pos.y + bar.bar_height);
		p2.change(bar.pos.x + bar.bar_width, bar.pos.y + bar.bar_height);

		if (ball->pos.point_to_segment(p1, p2) <= ball->radius) // bar랑 충돌할때
		{
			ball->pos = ball->pos.collision_point(p1, p2);
			ball->pos.y += ball->radius;
			ball->v.y = -1 * ball->v.y;
		}
	}
}

void GameManager::DrawBalls()
{
	for (Ball* ball : this->balls) ball->DrawBall();
}

void GameManager::DrawBar()
{
	bar.draw_bar();
}

void GameManager::Collision_Detection_Between_Blocks(void) {
	for (Ball* ball : this->balls) {
		for (Brick* brick : this->Bricks) {
			brick->Collision_Detection(ball);
		}
	}
}

void GameManager::DrawBricks()
{
	for (Brick* brick : Bricks) brick->DrawBrick();
}

void GameManager::Reset() // 초기상태로 돌리기
{
	InitGame();
}

void GameManager::GamePause()
{
	this->Pause = !Pause;
}

void GameManager::MoveBar(float dist)
{
	bar.pos.x += dist;
	if (bar.pos.x < 0) bar.pos.x = 0;
	if (bar.pos.x + bar.bar_width > WIDTH) bar.pos.x = WIDTH-bar.bar_width;
}

void GameManager::MoveBalls(void)
{
	for (Ball* ball : balls) ball->MoveBall();
}

void GameManager::GameSpeed(float mul)
{
	for (Ball* ball : balls) ball->CotrolBallSpeed(mul);
}
