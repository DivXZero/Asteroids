
#ifndef SCENE_H
#define SCENE_H

#include "system/Window.h"
#include "system/Physics.h"
#include "system/ObjectCollection.h"

class Scene
{
public:
	Scene() {}
	~Scene() {}

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	void init(Window* window, Physics* physics, Event* event);
	void updateScene();
	void renderScene();
	void draw(sf::Shape& shape) { window()->getWindow()->draw(shape); }

	void setWindow(Window* window) { m_Window = window; }
	void setPhysics(Physics* physics) { m_Physics = physics; }
	void setEvent(Event* event) { m_Event = event; }
	Window* window() { return m_Window; }
	Physics* physics() { return m_Physics; }
	Event* event() { return m_Event; }

	template <class T> Object<T>* addObject();
	template <class T> void updateCollection();
	template <class T> void renderCollection();

	template <class T> ObjectCollection<T>* getObjectCollection();

private:
	Window* m_Window;
	Physics* m_Physics;
	Event* m_Event;
};

template <class T>
Object<T>* Scene::addObject()
{
	Object<T>* object = getObjectCollection<T>()->addObject();
	object->get()->setScene(this);
	object->init();
	return object;
}

template <class T>
void Scene::updateCollection()
{
	getObjectCollection<T>()->update();
}

template <class T>
void Scene::renderCollection()
{
	getObjectCollection<T>()->render();
}

template <class T>
ObjectCollection<T>* Scene::getObjectCollection()
{
	return ObjectCollectionSingleton<T>::Instance();
}

#endif