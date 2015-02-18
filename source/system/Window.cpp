
#include <stdio.h>
#include "system/Window.h"

Window::Window()
{
}

Window::Window(sf::Uint16 w, sf::Uint16 h, sf::String title, bool fullscreen) :
m_Width(w), m_Height(h),
m_Title(title),
m_isFullscreen(fullscreen)
{
	init();
}

Window::~Window()
{
}

bool Window::init()
{
	m_ContextSettings.antialiasingLevel = 8;
	m_VideoMode = sf::VideoMode(m_Width, m_Height);
	m_Style = (m_isFullscreen) ? sf::Style::Fullscreen : sf::Style::Close;
	m_Window.create(m_VideoMode, m_Title, m_Style, m_ContextSettings);
	m_Window.setVerticalSyncEnabled(true);

	return m_Window.isOpen();
}

bool Window::init(sf::Uint16 w, sf::Uint16 h, sf::String title, bool fullscreen)
{
	m_Width = w;
	m_Height = h;
	m_Title = title;
	m_isFullscreen = fullscreen;

	return init();
}

void Window::close()
{
	m_Window.close();
}

bool Window::pollEvent(Event &event)
{
	return m_Window.pollEvent(event.getEvent());
}