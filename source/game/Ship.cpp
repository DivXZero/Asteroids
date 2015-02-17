
#include <glm/glm.hpp>
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

	m_bodyDef.position.Set(getPosition().x / Physics::Scale, getPosition().y / Physics::Scale);
	m_bodyDef.type = b2_dynamicBody;
	m_Body = scene()->physics()->world()->CreateBody(&m_bodyDef);
	m_Shape.SetAsBox(1, 1);
	m_Body->CreateFixture(&m_Shape, 1.0f);
}

void Ship::update()
{
	// Forward
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		float velocityX = m_Body->GetMass() * ACCELERATION * glm::sin(m_Body->GetAngle());
		float velocityY = m_Body->GetMass() * ACCELERATION * -glm::cos(m_Body->GetAngle());
		m_Body->ApplyForceToCenter(b2Vec2(velocityX, velocityY), true);
	}

	// Rotate CCW (left)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		m_Body->ApplyTorque(-10, true);

	// Rotate CW (right)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		m_Body->ApplyTorque(10, true);

	setPosition(m_Body->GetPosition().x * Physics::Scale, m_Body->GetPosition().y * Physics::Scale);
	setRotation(glm::degrees(m_Body->GetAngle()));
}

void Ship::render()
{
	scene()->window()->getWindow()->draw(*this);
}