#pragma once

#include <vector>
#include "Common.h"
#include "Block.h"
#include "Ball.h"
#include "GameManager.h"

using namespace std;

void GameManager::InitGame() {
	int x = 100;	//��� ������ �ʱ� x ��ǥ
	int y = 500;	//��� ������ �ʱ� y ��ǥ
	int dx = 50;	//��� ������ �����Ǵ� x ��ǥ ������
	int dy = 100;	//��� ������ �����Ǵ� y ��ǥ ������

	for (int i = 0; i < 2; i++)
	{
		x = 100;
		for (int j = 0; j < 5; j++)
		{
			blocks.push_back(new Block(x, y));
			x = x + dx; // ��� �������� ����� x ��ǥ�� dx�� �̵�
		}
		y = y - dy; // ��� �������� ����� y ��ǥ�� dy�� �̵�
	}

	balls.push_back(new Ball(WIDTH / 2, HEIGHT / 4, 20.0, 3.0, -8.0));
}

GameManager::GameManager() {
	InitGame();
}
void GameManager::DrawBlocks() {
	for (Block* block : blocks) {
		block->DrawBlock();
	}
}
void GameManager::Collision_Detection_Between_Blocks() {
	for (Ball* ball : this->balls) {
		for (Block* block : this->blocks) {
			block->Collision_Detection_Between_Blocks(*ball);
		}
	}

}
void GameManager::Collision_Detection_to_Walls(void) {
	for (Ball* ball : this->balls) {
		if (ball->position.x + ball->radius >= WIDTH || ball->position.x - ball->radius <= 0)
		{
			ball->velocity.x *= -1.0;

		}

		if (ball->position.y + ball->radius >= WIDTH || ball->position.y - ball->radius <= 0)
		{
			ball->velocity.y *= -1.0;

		}
	}
}

void GameManager::MoveBalls() {
	for (Ball* ball : this->balls)
	{
		ball->position.x += ball->velocity.x;
		ball->position.y += ball->velocity.y;
		ball->DrawBall();
	}
}
