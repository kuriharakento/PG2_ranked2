#pragma once
#include "EnumScene.h"

class IScene
{
public:
	virtual ~IScene() = default;
	virtual void Init() = 0;
	virtual void Update(char *keys, char *preKeys,enumScene &enumNextScene) = 0;
	virtual void Draw() = 0;
};

