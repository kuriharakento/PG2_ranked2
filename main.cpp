#include <Novice.h>

#include "Enemy.h"
#include "Player.h"
#include "Collision.h"

const char kWindowTitle[] = "LC1A_13_クリハラ_ケント_タイトル";

enum Scene
{
	TITLE,
	GAME,
	RESULT
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	//シーン
	Scene curentScene = TITLE;

	//プレイヤー
	Player *player = new Player();
	player->Init();

	//エネミー
	Enemy* enemy = new Enemy();
	enemy->Init();

	//当たり判定
	Collision *collision = new Collision;
	collision->Init();

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (curentScene)
		{
		case TITLE:
			
			break;
		case GAME:
			player->Update(keys);
			enemy->Update();
			collision->Update(player, enemy);
			break;
		case RESULT:
			break;
		}

		//デバッグ用
		//ステージを数字で切り替える
		if(keys[DIK_1] && !preKeys[DIK_1])
		{
			curentScene = TITLE;
		}
		if (keys[DIK_2] && !preKeys[DIK_2])
		{
			curentScene = GAME;
		}
		if (keys[DIK_3] && !preKeys[DIK_3])
		{
			curentScene = RESULT;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		switch (curentScene)
		{
		case TITLE:

			//現在のシーン
			Novice::ScreenPrintf(100, 100, "curent Scene : TITLE");

			break;

		case GAME:

			//オブジェクトの描画
			player->Draw();
			enemy->Draw();
			

			//現在のシーン
			Novice::ScreenPrintf(100, 100, "curent Scene : GAME");

			break;

		case RESULT:

			//現在のシーン
			Novice::ScreenPrintf(100, 100, "curent Scene : RESULT");

			break;
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	//メモリ開放
	delete player;
	delete enemy;
	delete collision;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
