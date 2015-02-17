
#ifndef ASTEROIDS_WINDOW_H
#define ASTEROIDS_WINDOW_H

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "Event.h"

class Window
{
public:
	Window();
	Window(sf::Uint16 w, sf::Uint16 h, sf::String title, bool fullscreen = false);
	~Window();

	bool init();
	bool init(sf::Uint16 w, sf::Uint16 h, sf::String title, bool fullscreen = false);
	void close();
	bool pollEvent(Event &event);
	void swapBuffers() { m_Window.display(); }

private:
	sf::RenderWindow m_Window;
	sf::VideoMode m_VideoMode;
	sf::String m_Title;
	sf::Uint32 m_Style;
	sf::ContextSettings m_ContextSettings;
	sf::Uint16 m_Width, m_Height;
	bool m_isFullscreen;
};

#endif	// ASTEROIDS_WINDOW_H