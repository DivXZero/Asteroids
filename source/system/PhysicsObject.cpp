
#include "system/Physics.h"
#include "system/PhysicsObject.h"

PhysicsObject::PhysicsObject()
{
}

PhysicsObject::~PhysicsObject()
{
}

void PhysicsObject::setPosition(float x, float y)
{
	m_bodyDef.position.Set((x / Physics::Scale), (y / Physics::Scale));
}

void PhysicsObject::setBodyType(BodyType type)
{
	m_bodyDef.type = (b2BodyType)type;
}

void PhysicsObject::setLinearDamping(float amt)
{
	m_bodyDef.linearDamping = amt;
}

void PhysicsObject::setAngularDamping(float amt)
{
	m_bodyDef.angularDamping = amt;
}

void PhysicsObject::setBoundingBox(float w, float h)
{
	float boxW = 1 / (w / Physics::Scale);
	float boxH = 1 / (h / Physics::Scale);
	m_Shape.SetAsBox(boxW, boxH);
}

void PhysicsObject::createFixture()
{
	m_fixtureDef.shape = &m_Shape;
	body()->CreateFixture(&m_fixtureDef);
}