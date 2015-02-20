
#ifndef ASTEROIDS_SCENE_H
#define ASTEROIDS_SCENE_H

#include "system/GameObject.h"
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

	void addObject(GameObject* object) { object->init(this);  m_Objects.push_back(object); }
	void destroyObject(GameObject* object) { for (m_ObjectIter = m_Objects.begin(); m_ObjectIter != m_Objects.end();) { if (object == (*m_ObjectIter)) { delete *m_ObjectIter; m_Objects.erase(m_ObjectIter); } } }
	void updateObjects() { for (m_ObjectIter = m_Objects.begin(); m_ObjectIter != m_Objects.end();) { (*m_ObjectIter)->update(); } }
	void renderObjects() { for (m_ObjectIter = m_Objects.begin(); m_ObjectIter != m_Objects.end();) { (*m_ObjectIter)->render(); } }

private:
	std::vector<GameObject*> m_Objects;
	std::vector<GameObject*>::iterator m_ObjectIter;
};

#endif	// ASTEROIDS_SCENE_H