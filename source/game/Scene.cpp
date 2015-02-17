
#include "game/Scene.h"
#include "game/Ship.h"

Ship playerShip;

void Scene::init()
{
	window()->showCursor(false);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	playerShip.init(this);
}

void Scene::init(Window* window, Physics* physics, Event* event)
{
	setWindow(window);
	setPhysics(physics);
	setEvent(event);
	init();
}

void Scene::update()
{
	playerShip.update();
}

void Scene::render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	playerShip.render();
}