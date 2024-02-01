#pragma once
#include "Vector2.h"
#include "Novice.h"

const int kBulletRadius = 7;

class Bullet
{
public:
	//弾の座標、向き、速度、弾の種類,
	Vector2 pos_;
	Vector2 vector_;
	Vector2 velocity_;

	//半径、色、発射されているかのフラグ
	float radius_;
	unsigned int color_;
	bool isShot_;

	Bullet();
	void Init();
	void Update();
	void Draw();

	float GetRadius() { return radius_; }
};

