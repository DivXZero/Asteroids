
#include <glm/glm.hpp>
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
	float points[4][2] = { { -10, 10 }, { 0, -20 }, { 10, 10 }, {0, 0} };

	m_Scene = ownerScene;
	setFillColor(sf::Color(0, 0, 0, 255));
	setOutlineColor(sf::Color(255, 255, 255, 255));
	setOutlineThickness(1);
	setPointCount(4);

	for (int i = 0; i < 4; i++)
		setPoint(i, sf::Vector2f(points[i][0], points[i][1]));

	setPosition(((float)scene()->window()->getWidth() / 2) - 10, ((float)scene()->window()->getHeight() / 2) - 10);
	setBodyType(b2BodyType::b2_dynamicBody);
	setLinearDamping(0.5f);
	setAngularDamping(1.0f);
	createBody(scene()->physics()->world());

	sf::Rect<float> bounds = getLocalBounds();
	float boundx = bounds.width - bounds.left;
	float boundy = bounds.height - bounds.top;
	setBoundingBox(boundx, boundy);
	setDensity(1.0f);
	createFixture();
}

void Ship::update()
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

void Ship::render()
{
	ConvexShape::setPosition(body()->GetPosition().x * Physics::Scale, body()->GetPosition().y * Physics::Scale);
	ConvexShape::setRotation(glm::degrees(body()->GetAngle()));

	scene()->window()->getWindow()->draw(*this);
}

void Ship::setPosition(float x, float y)
{
	ConvexShape::setPosition(x, y);
	PhysicsObject::setPosition(x, y);
}