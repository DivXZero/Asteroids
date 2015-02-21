
#include "system/Scene.h"

void Scene::init(Window* window, Physics* physics, Event* event)
{
	setWindow(window);
	setPhysics(physics);
	setEvent(event);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	init();
}

void Scene::updateScene()
{
	update();
}

void Scene::renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);

	render();
}