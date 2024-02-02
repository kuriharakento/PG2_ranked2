#include "Enemy.h"

#include <vector>

#include "Clamp.h"

Enemy::Enemy()
{
	pos_ = { 0.0f,0.0f };
	radius_ = 0;
	velocity_ = { 0.0f,0.0f };
	vector_ = { 0.0f,0.0f };
	color_ = 0;
	isAlive_ = false;
	respwaninterval_ = 0;
}

void Enemy::Init()
{
	pos_ = { 640,100 };
	radius_ = kEnemyRadius;
	velocity_ = { 5.0f,5.0f };
	vector_ = { sinf((rand() % 360) * (float(M_PI) / 180.f)),	cosf((rand() % 360) * (float(M_PI) / 180.f)) };
	color_ = RED;
	isAlive_ = true;
	respwaninterval_ = kEnemyRespawninterval;
}

void Enemy::Update()
{
	if (isAlive_)
	{
		pos_.x += velocity_.x * vector_.x;
		pos_.y += velocity_.y + vector_.y;

		//x軸の動ける範囲
		if (Clamp(float(0 + radius_), float(1280 - radius_), pos_.x) != pos_.x)
		{
			pos_.x = Clamp(float(0 + radius_), float(1280 - radius_), pos_.x);
			velocity_.x *= -1;
		}

		//y軸の動ける範囲
		if (Clamp(float(0 + radius_), float(720 - radius_), pos_.y) != pos_.y)
		{
			pos_.y = Clamp(float(0 + radius_), float(720 - radius_), pos_.y);
			velocity_.y *= -1;
		}
	}
	else
	{
		respwaninterval_--;
		if(respwaninterval_ <= 0)
		{
			isAlive_ = true;
			vector_ = { sinf((rand() % 360) * (float(M_PI) / 180.f)),	cosf((rand() % 360) * (float(M_PI) / 180.f)) };
			respwaninterval_ = kEnemyRespawninterval;
		}
	}
}

void Enemy::Draw()
{
	if (isAlive_) {
		Novice::DrawEllipse(
			(int)pos_.x, (int)pos_.y,
			radius_, radius_,
			0.0f,
			color_,
			kFillModeSolid
		);
	}
}
