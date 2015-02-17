
#include "game/Ship.h"
#include <iostream>

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

	m_bodyDef.position = b2Vec2(getPosition().x, getPosition().y);
	m_bodyDef.type = b2_dynamicBody;
	m_Body = scene()->physics()->world()->CreateBody(&m_bodyDef);
	m_Shape.SetAsBox(1, 1);
	m_bodyDef.angle = 0;
	m_fixtureDef.density = 1.0f;
	m_fixtureDef.friction = 0.7f;
	m_fixtureDef.shape = &m_Shape;
	m_Body->CreateFixture(&m_fixtureDef);
}

void Ship::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		rotate(-0.5f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		rotate(0.5f);

	setPosition(m_Body->GetPosition().x, m_Body->GetPosition().y);
	setRotation(m_Body->GetAngle());
}

void Ship::render()
{
	scene()->window()->getWindow()->draw(*this);
}