#pragma once
#include "Scene.h"
class Title :
    public Scene
{
public:
    Title();
    
    void Update() override;
    void Draw() override;
};

