
#ifndef ASTEROIDS_GAME_H
#define ASTEROIDS_GAME_H

#include "system/Window.h"
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
	Event m_Event;
	Scene m_Scene;
	bool m_isRunning;
};

#endif	// ASTEROIDS_GAME_H