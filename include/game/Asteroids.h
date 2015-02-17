
#ifndef ASTEROIDS_GAME_H
#define ASTEROIDS_GAME_H

#include "system/Window.h"
#include "system/Physics.h"
#include "Scene.h"

class Game
{
public:
	Game();
	~Game();

	bool init();
	void update();
	void processEvents();
	bool isRunning() { return m_isRunning; }

private:
	Window m_Window;
	Physics m_Physics;
	Event m_Event;
	Scene m_Scene;
	bool m_isRunning;

	sf::Clock m_Clock;
	double m_time;
	double m_fixedDeltaTime;
	double m_deltaTime;
	double m_currentTime;
	double m_accumulator;
};

#endif	// ASTEROIDS_GAME_H