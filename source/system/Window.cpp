
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

	//resize();

	return m_Window.isOpen();
}

void Window::resize()
{
	glViewport(0, 0, m_Window.getSize().x, m_Window.getSize().y);
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
	bool e = m_Window.pollEvent(event.getEvent());

	/*
	if (event.getType() == sf::Event::Resized)
		resize();
		*/

	return e;
}