#pragma once
#include "IScene.h"

class Enemy;
class Player;
class Collision;

class Game :
    public IScene
{
public:
    Game();
    ~Game();
    void Init() override;
    void Update(char *keys, char *preKeys, enumScene &enumNextScene) override;
    void Draw() override;

private:
    Enemy *enemy;
    Player* player;
    Collision* collision;
};

