
#ifndef ASTEROIDS_EVENT_H
#define ASTEROIDS_EVENT_H

#include <SFML/Window.hpp>

class Event
{
public:
	Event();
	~Event();

	sf::Event::EventType getType() { return m_Event.type; }
	sf::Event& getEvent() { return m_Event; }

private:
	sf::Event m_Event;
};

#endif