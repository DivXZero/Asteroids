
#ifndef SCENE_H
#define SCENE_H

#include "SharedScene.h"
#include "SharedObject.h"
#include <vector>

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

	void addObject(SharedObject* object) { object->init(this);  m_Objects.push_back(object); }
	void destroyObject(SharedObject* object) { for (m_ObjectIter = m_Objects.begin(); m_ObjectIter != m_Objects.end();) { if (object == (*m_ObjectIter)) { delete *m_ObjectIter; m_Objects.erase(m_ObjectIter); } } }
	void updateObjects() { for (m_ObjectIter = m_Objects.begin(); m_ObjectIter != m_Objects.end();) { (*m_ObjectIter)->update(); } }
	void renderObjects() { for (m_ObjectIter = m_Objects.begin(); m_ObjectIter != m_Objects.end();) { (*m_ObjectIter)->render(); } }

private:
	std::vector<SharedObject*> m_Objects;
	std::vector<SharedObject*>::iterator m_ObjectIter;
};

#endif