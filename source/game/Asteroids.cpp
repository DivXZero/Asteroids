
#include "game/Asteroids.h"

Game::Game() :
m_isRunning(false)
{
}

Game::~Game()
{
}

bool Game::init()
{
	if (!m_Window.init(1024, 768, "Asteroids", false))
		return false;

	m_Scene.init();

	m_isRunning = true;
	return true;
}

void Game::update()
{
	processEvents();

	m_Scene.render();
	m_Window.swapBuffers();
}

void Game::processEvents()
{
	while (m_Window.pollEvent(m_Event))
	{
		if (m_Event.getEvent().type == sf::Event::Closed)
		{
			m_Window.close();
			m_isRunning = false;
		}
	}
}