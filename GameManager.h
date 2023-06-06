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

	//게임제어
	void Reset();
	void GamePause();
	void GameSpeed(float mul);

	// 그리기
	void DrawBricks();
	void DrawBalls();
	void DrawBar();

	// 움직임
	void MoveBar(float);
	void MoveBalls(void);

	// 충돌체크
	void Collision_Detection_Between_Blocks();
	void Collision_Detection_to_Walls();
	
};