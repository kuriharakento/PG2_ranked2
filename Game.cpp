#include "Novice.h"
#include "Title.h"
#include "Game.h"

#include "Player.h"
#include "Enemy.h"
#include  "Collision.h"

Game::Game()
{
	player = new Player();
	enemy = new Enemy();
	collision = new Collision();
	Init();
}

Game::~Game()
{
	delete player;
	delete enemy;
	delete collision;
}


void Game::Init()
{
	player->Init();
	enemy->Init();
	collision->Init();
}


void Game::Update(char *keys, char *preKeys, enumScene &enumNextScene)
{
	if(keys[DIK_R] && !preKeys[DIK_R])
	{
		enumNextScene = TITLE;
	}
	player->Update(keys);
	enemy->Update();
	collision->Update(*player, *enemy);
}

void Game::Draw()
{
	Novice::DrawBox(
		0,0,
		1280,720,
		0.0f,
		0xa9a9a9ff,
		kFillModeSolid
	);
	player->Draw();
	enemy->Draw();

	Novice::ScreenPrintf(100, 100, "Scene : GAME");
	Novice::ScreenPrintf(100, 200, "[W][A][S][D] : move");
	Novice::ScreenPrintf(100, 220, "[Left Click] : shoot bullet");
}

