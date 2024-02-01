#include "Enemy.h"

Enemy::Enemy()
{
	pos_ = { 0.0f,0.0f };
	radius_ = 0;
	velocity_ = { 0.0f,0.0f };
}

void Enemy::Init()
{
	pos_ = { 640,100 };
	radius_ = 30;
	velocity_ = { 0.0f,0.0f };
	color_ = RED;
}

void Enemy::Update()
{
	
}

void Enemy::Draw()
{
	
}
