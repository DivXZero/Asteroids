
#include "game/Ship.h"

Ship::Ship()
{
}

Ship::~Ship()
{
}

void Ship::init(Scene* ownerScene)
{
	m_Scene = ownerScene;
	setFillColor(sf::Color(0, 0, 0, 255));
	setOutlineColor(sf::Color(255, 255, 255, 255));
	setOutlineThickness(1);
	setPointCount(4);
	setPoint(0, sf::Vector2f(-10, 10));
	setPoint(1, sf::Vector2f(0, -20));
	setPoint(2, sf::Vector2f(10, 10));
	setPoint(3, sf::Vector2f(0, 0));
	setPosition(((float)scene()->window()->getWidth() / 2) - 10, ((float)scene()->window()->getHeight() / 2) - 10);
}

void Ship::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		rotate(-0.01f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		rotate(0.01f);
}

void Ship::render()
{
	scene()->window()->getWindow()->draw(*this);
}