
#include "game/Scene.h"
#include "game/Ship.h"
#include "game/Rock.h"

#define ROCK_COUNT 20

Ship playerShip;
Rock rocks[ROCK_COUNT];

void Scene::init()
{
	window()->showCursor(false);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	playerShip.init(this);

	for (int i = 0; i < ROCK_COUNT; i++)
		rocks[i].init(this);
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

	for (int i = 0; i < ROCK_COUNT; i++)
		rocks[i].update();
}

void Scene::render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	playerShip.render();

	for (int i = 0; i < ROCK_COUNT; i++)
		rocks[i].render();
}