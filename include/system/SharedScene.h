
#ifndef ASTEROIDS_SHAREDSCENE_H
#define ASTEROIDS_SHAREDSCENE_H

#include "Window.h"
#include "Physics.h"
#include "Event.h"

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
	Window* window() { return m_Window; }
	Physics* physics() { return m_Physics; }
	Event* event() { return m_Event; }

private:
	Window* m_Window;
	Physics* m_Physics;
	Event* m_Event;
};

#endif	// ASTEROIDS_SCENE_H