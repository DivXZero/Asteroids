
#ifndef ASTEROIDS_SCENE_H
#define ASTEROIDS_SCENE_H

#include "system/Window.h"
#include "system/SharedScene.h"

class Scene : public SharedScene
{
public:
	Scene() {}
	~Scene() {}

	void init();
	void init(Window* window, Event* event);
	void update();
	void render();
};

#endif	// ASTEROIDS_SCENE_H