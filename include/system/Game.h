
#ifndef GAMECLASS_H
#define GAMECLASS_H

#include "system/Window.h"
#include "system/Physics.h"
#include "system/Scene.h"
#include "system/Singleton.h"

class Game
{
public:
	Game() :
		m_time(0.0),
		m_deltaTime(0.01),
		m_accumulator(0.0)
	{}
	~Game() {}

	bool init(Scene* scene);
	void update();
	void processEvents();
	bool isRunning() { return m_isRunning; }
	Scene* scene() { return m_Scene; }

private:
	Window m_Window;
	Physics m_Physics;
	Event m_Event;
	Scene* m_Scene;
	bool m_isRunning;
	sf::Clock m_Clock;
	double m_currentTime;

	double m_time;
	double m_fixedDeltaTime;
	double m_deltaTime;
	double m_accumulator;
};

#endif