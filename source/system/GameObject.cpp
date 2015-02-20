
#include "system/GameObject.h"

void GameObject::render()
{
	RenderableObject::setPosition(body()->GetPosition().x * Physics::Scale, body()->GetPosition().y * Physics::Scale);
	RenderableObject::setRotation(glm::degrees(body()->GetAngle()));

	scene()->window()->getWindow()->draw(*this);
}

void GameObject::setPosition(float x, float y)
{
	RenderableObject::setPosition(x, y);
	PhysicsObject::setPosition(x, y);
}

void GameObject::setAsBox(float w, float h)
{
	RenderableObject::setAsBox(w, h);
	PhysicsObject::setAsBox(w, h);
}

void GameObject::setPoints(int count, float points[][2])
{
	RenderableObject::setPoints(count, points);
	PhysicsObject::setPoints(count, points);
}