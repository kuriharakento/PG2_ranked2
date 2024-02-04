#pragma once
#include "IScene.h"

class Title :
	public IScene
{
public:
	Title();
	void Init() override;
	void Update(char* keys, char* preKeys, enumScene &enumNextScene) override;
	void Draw() override;
};

