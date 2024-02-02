#include "Collision.h"

#include "Bullet.h"

Collision::Collision()
{
	playerToEnemyCollision = { 0.0f,0.0f,0.0f };
	bulletToEnemyCollision = { 0.0f,0.0f,0.0f };
}

void Collision::Init()
{
	playerToEnemyCollision = { 0.0f,0.0f,0.0f };
	bulletToEnemyCollision = { 0.0f,0.0f,0.0f };
}

void Collision::Update(Player* player, Enemy* enemy)
{
	//プレイヤーと敵の衝突判定
	if (player->GetIsAlive() && enemy->GetIsAlive())
	{
		playerToEnemyCollision.a = powf(player->GetPos().x - enemy->GetPos().x, 2);
		playerToEnemyCollision.b = powf(player->GetPos().y - enemy->GetPos().y, 2);
		playerToEnemyCollision.c = powf(float(player->GetRadius() + enemy->GetRadius()), 2);

		if (playerToEnemyCollision.c >= playerToEnemyCollision.a + playerToEnemyCollision.b)
		{
			player->SetIsAlive(false);
		}
	}

	if (player->GetBullet().empty()){return;}

	//敵と弾の当たり判定
	auto iterator = player->GetBullet().begin();
	while (iterator != player->GetBullet().end())
	{
		//表示されているなら実行する
		if ((*iterator)->GetIsShot() && enemy->GetIsAlive())
		{
			bulletToEnemyCollision.a = powf((*iterator)->GetPos().x - enemy->GetPos().x, 2);
			bulletToEnemyCollision.b = powf((*iterator)->GetPos().y - enemy->GetPos().y, 2);
			bulletToEnemyCollision.c = powf((*iterator)->GetRadius() + float(enemy->GetRadius()), 2);

			//判定
			if (bulletToEnemyCollision.c >= bulletToEnemyCollision.a + bulletToEnemyCollision.b)
			{
				//当たっていたので弾と敵を消す
				enemy->SetIsAlive(false);
				(*iterator)->SetIsShot(false);
				iterator = player->GetBullet().erase(iterator);
				continue;
			}
		}
		++iterator;
	}
}

