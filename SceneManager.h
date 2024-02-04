#pragma once
#include "EnumScene.h"

class IScene;
class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	void Init();
	void Update(char *keys, char *preKeys);
	void SwitchScene();
	void Draw();

private:
	IScene* currentScene;
	enumScene enumCurrentScene;
	enumScene enumNextScene;
};

