#pragma once

#include <vector>
#include "Common.h"
#include "Brick.h"
#include "Ball.h"
#include "Bar.h"

using namespace std;

class GameManager {
private:
	int		_left;
	int		_bottom;
	int		_width;
	int    _height;

	bool Pause = false;
	vector<Brick*> Bricks;
	vector<Ball*> balls;
	Bar bar;
	
	void InitGame();

public:
	GameManager(int, int, int, int);

	//��������
	void Reset();
	void GamePause();
	void GameSpeed(float mul);

	// �׸���
	void DrawBricks();
	void DrawBalls();
	void DrawBar();

	// ������
	void MoveBar(float);
	void MoveBalls(void);

	// �浹üũ
	void Collision_Detection_Between_Blocks();
	void Collision_Detection_to_Walls();
	
};