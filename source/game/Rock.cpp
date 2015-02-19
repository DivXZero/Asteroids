
#include <glm/glm.hpp>
#include "game/Rock.h"

void Rock::init(Scene* ownerScene)
{
	m_Scene = ownerScene;
	float points[8][2] = { { -40, 0 }, { -35, -20 }, { -20, -25 }, { -20, -40 }, { 0, -45 }, { 10, -30 }, { 20, -25 }, { 20, -10 } };
	setPoints(8, points);
	setColors();
	setPosition(((float)scene()->window()->getCenter().x) - 100, ((float)scene()->window()->getCenter().y) - 100);
	createBody(scene()->physics()->world(), b2_dynamicBody, 0, 0, 5.0f);
}

void Rock::update()
{
	checkOffscreen();
}

void Rock::render()
{
	RenderableObject::setPosition(body()->GetPosition().x * Physics::Scale, body()->GetPosition().y * Physics::Scale);
	RenderableObject::setRotation(glm::degrees(body()->GetAngle()));

	scene()->draw(*this);
}

void Rock::setPosition(float x, float y)
{
	RenderableObject::setPosition(x, y);
	PhysicsObject::setPosition(x, y);
}

void Rock::setPoints(int count, float points[][2])
{
	RenderableObject::setPoints(count, points);
	PhysicsObject::setPoints(count, points);
}

void Rock::checkOffscreen()
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