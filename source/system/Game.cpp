
#include "system/Game.h"

bool Game::init(Scene* scene)
{
	if (!m_Window.init(1920, 1080, "Asteroids", false))
		return false;

	m_Scene = scene;
	scene->init(&m_Window, &m_Physics, &m_Event);

	m_currentTime = m_Clock.getElapsedTime().asSeconds();

	m_isRunning = true;
	return true;
}

void Game::update()
{
	double newTime = m_Clock.getElapsedTime().asSeconds();
	double frameTime = newTime - m_currentTime;

	if (frameTime > 0.25)
		frameTime = 0.25;

	m_currentTime = newTime;
	m_accumulator += frameTime;

	processEvents();

	while (m_accumulator >= m_deltaTime)
	{
		m_Physics.world()->Step((float)m_deltaTime, 8, 3);
		m_Physics.world()->ClearForces();

		scene()->update();

		m_time += m_deltaTime;
		m_accumulator -= m_deltaTime;
	}

	//double alpha = m_accumulator / m_deltaTime;

	scene()->render();
	m_Window.swapBuffers();
}

void Game::processEvents()
{
	while (m_Window.pollEvent(m_Event))
	{
		if (m_Event.getEvent().type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			m_Window.close();
			m_isRunning = false;
		}
	}
}