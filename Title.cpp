#include "Title.h"

#include "Game.h"
#include  "Novice.h"

Title::Title()
{
	Init();
}

void Title::Init()
{
	
}

void Title::Update(char *keys,char *preKeys, enumScene &enumNextScene)
{
	if(keys[DIK_SPACE] && !preKeys[DIK_SPACE])
	{
		//次のシーンに行く
		enumNextScene = GAME;
	}
}

void Title::Draw()
{
	Novice::DrawBox(
		0,0,
		1280,720,
		0.0f,
		0x696969ff,
		kFillModeSolid
	);

	Novice::ScreenPrintf(100, 100, "Scene : TITLE");
	Novice::ScreenPrintf(550, 500, "[SPACE] : go to GameScene");
}



