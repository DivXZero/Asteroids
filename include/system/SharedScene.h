
#ifndef ASTEROIDS_SHAREDSCENE_H
#define ASTEROIDS_SHAREDSCENE_H

#include "Window.h"
#include "Event.h"

class SharedScene
{
public:
	virtual ~SharedScene() {}
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	void setWindow(Window* window) { m_Window = window; }
	void setEvent(Event* event) { m_Event = event; }
	Window* window() { return m_Window; }
	Event* event() { return m_Event; }

private:
	Window* m_Window;
	Event* m_Event;
};

#endif	// ASTEROIDS_SCENE_H