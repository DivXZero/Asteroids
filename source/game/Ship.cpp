
#include <glm/glm.hpp>
#include "game/Ship.h"

void Ship::init(Scene* ownerScene)
{
	m_Scene = ownerScene;
	float points[4][2] = { { -10, 10 }, { 0, -20 }, { 10, 10 }, {0, 0} };
	setPoints(4, points);
	setColors();
	setPosition(((float)scene()->window()->getCenter().x) - 10, ((float)scene()->window()->getCenter().y) - 10);
	createBody(scene()->physics()->world(), b2_dynamicBody, 0.5f, 5.0f, 5.0f);
}

void Ship::update()
{
	handleInput();
	checkOffscreen();
}

void Ship::render()
{
	RenderableObject::setPosition(body()->GetPosition().x * Physics::Scale, body()->GetPosition().y * Physics::Scale);
	RenderableObject::setRotation(glm::degrees(body()->GetAngle()));

	scene()->draw(*this);
}

void Ship::setPosition(float x, float y)
{
	RenderableObject::setPosition(x, y);
	PhysicsObject::setPosition(x, y);
}

void Ship::setPoints(int count, float points[][2])
{
	RenderableObject::setPoints(count, points);
	PhysicsObject::setPoints(count, points);
}

void Ship::handleInput()
{
	// Forward
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		float velocityX = ACCELERATION * glm::sin(body()->GetAngle());
		float velocityY = ACCELERATION * -glm::cos(body()->GetAngle());
		body()->ApplyForceToCenter(b2Vec2(velocityX, velocityY), true);
	}

	// Rotate CCW (left)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		applyTorque(-ROTATION);

	// Rotate CW (right)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		applyTorque(ROTATION);
}

void Ship::checkOffscreen()
{
	b2Vec2 position(body()->GetPosition().x * Physics::Scale, body()->GetPosition().y * Physics::Scale);

	if (position.x > scene()->window()->getWidth())
		body()->SetTransform(b2Vec2(0, position.y / Physics::Scale), body()->GetAngle());

	if (position.x < 0)
		body()->SetTransform(b2Vec2(scene()->window()->getWidth() / Physics::Scale, position.y / Physics::Scale), body()->GetAngle());

	if (position.y > scene()->window()->getHeight())
		body()->SetTransform(b2Vec2(position.x / Physics::Scale, 0), body()->GetAngle());

	if (position.y < 0)
		body()->SetTransform(b2Vec2(position.x / Physics::Scale, scene()->window()->getHeight() / Physics::Scale), body()->GetAngle());
}