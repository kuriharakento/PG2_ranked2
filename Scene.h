#pragma once
class Scene
{
	
public:
	Scene();
	~Scene();
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

