#pragma once
#include <vector>
#include "IntVector2.h"
#include "Vector2.h"

const int kPlayerMoveSpeed = 7;
const int kInterval = 12;
const int kRespawninterval = 120;

class Bullet;
class Player
{
public:
	Player();
	~Player();
	void Init();
	void Update(char* keys);
	void Draw();

	//アクセッサ
	

private:
	//プレイヤーの情報
	Vector2 pos_;
	int radius_;
	Vector2 velocity_;
	unsigned int color_;

	bool isAlive_;
	int respwaninterval_;

	//マウスの座標
	IntVector2 mousePos_;

	//弾の情報
	std::vector<Bullet*> bullet;
	int shootInterval_;
	bool canShoot_;

};

