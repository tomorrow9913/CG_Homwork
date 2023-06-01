#pragma once

#include <vector>
#include "Common.h"
#include "Block.h"
#include "Ball.h"

#define	WIDTH 			400
#define	HEIGHT			600

using namespace std;

class GameManager {
private:
	vector<Block*> blocks;
	vector<Ball*> balls;

	void InitGame();

public:
	GameManager();

	void DrawBlocks();
	void Collision_Detection_Between_Blocks();
	void Collision_Detection_to_Walls();
	void MoveBalls();
};