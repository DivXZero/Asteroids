
#include "system/Scene.h"

void Scene::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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
	updateObjects();
}

void Scene::render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	renderObjects();
}