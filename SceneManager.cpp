#include "SceneManager.h"
#include "Title.h"
#include "Game.h"

SceneManager::SceneManager()
{
	Init();
}

SceneManager::~SceneManager()
{
	delete currentScene;
}

void SceneManager::Init()
{
	delete currentScene;
	currentScene = new Title();
	enumCurrentScene = TITLE;
	enumNextScene = TITLE;

}

void SceneManager::SwitchScene()
{
	if(enumCurrentScene != enumNextScene)
	{
		enumCurrentScene = enumNextScene;
		switch (enumNextScene)
		{
		case TITLE:
			delete currentScene;
			currentScene = new Title();
			break;
		case GAME:
			delete currentScene;
			currentScene = new Game();
			break;
		}
	}
}

void SceneManager::Update(char *keys, char *preKeys)
{
	currentScene->Update(keys,preKeys,enumNextScene);
}

void SceneManager::Draw()
{
	currentScene->Draw();
}



