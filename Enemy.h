#pragma once
#include "Vector2.h"
#include "Novice.h"

const int kRespawninterval = 120;

class Enemy
{
public:
	Enemy();
	void Init();
	void Update();
	void Draw();
private:
	//座標、半径、速度、
	Vector2 pos_;
	int radius_;
	Vector2 velocity_;
	unsigned int color_;

	//生きているか
	bool isAlive_;
	int respwaninterval_ = kRespawninterval;
};

