
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
	void init(Window* window, Physics* physics, Event* event);
	void update();
	void render();
	void draw(sf::Shape& shape) { window()->getWindow()->draw(shape); }
};

#endif	// ASTEROIDS_SCENE_H