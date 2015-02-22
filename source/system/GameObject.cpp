
#include "system/GameObject.h"

void GameObject::updateObject()
{
	RenderableObject::setPosition(body()->GetPosition().x * Physics::Scale, body()->GetPosition().y * Physics::Scale);
	RenderableObject::setRotation(glm::degrees(body()->GetAngle()));
}

void GameObject::renderObject()
{
	// Move this to renderableobject?
	scene()->window()->getWindow()->draw(*this);
}

void GameObject::destroyObject()
{
	m_isAlive = false;

	cleanup();
	// need to move this somewhere
	//scene()->physics()->world()->DestroyBody(body());
	destroyBody(scene()->physics()->world());
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