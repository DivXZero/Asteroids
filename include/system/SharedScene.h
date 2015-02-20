
#ifndef ASTEROIDS_SHAREDSCENE_H
#define ASTEROIDS_SHAREDSCENE_H

#include "system/Window.h"
#include "system/Physics.h"
#include "system/Event.h"
#include <vector>

class SharedScene
{
public:
	virtual ~SharedScene() {}
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	void setWindow(Window* window) { m_Window = window; }
	void setPhysics(Physics* physics) { m_Physics = physics; }
	void setEvent(Event* event) { m_Event = event; }
	//void addObject(GameObject* object) { object->init(this);  m_Objects.push_back(object); }
	//void updateObjects() { for (m_ObjectIter = m_Objects.begin(); m_ObjectIter != m_Objects.end();) { (*m_ObjectIter)->update(); } }
	//void renderObjects() { for (m_ObjectIter = m_Objects.begin(); m_ObjectIter != m_Objects.end();) { (*m_ObjectIter)->render(); } }
	Window* window() { return m_Window; }
	Physics* physics() { return m_Physics; }
	Event* event() { return m_Event; }

private:
	Window* m_Window;
	Physics* m_Physics;
	Event* m_Event;
	//std::vector<GameObject*> m_Objects;
	//std::vector<GameObject*>::iterator m_ObjectIter;
};

#endif	// ASTEROIDS_SCENE_H