
#include "system/Physics.h"
#include "system/PhysicsObject.h"

void PhysicsObject::setBody(b2Body* body)
{
	m_Body = body;
	body->SetUserData(this);
}

void PhysicsObject::setPosition(float x, float y)
{
	m_bodyDef.position.Set((x / Physics::Scale), (y / Physics::Scale));
}

void PhysicsObject::setBodyType(b2BodyType type)
{
	m_bodyDef.type = type;
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
	float points[4][2] = { { -(w / 2), -(h / 2) },	// Btm left
							{ -(w / 2), (h / 2) },	// Top Left
							{ (w / 2), (h / 2) },		// Top Right
							{ (w / 2), -(h / 2) }	// Bottom Right
	};
	setPoints(4, points);
}

void PhysicsObject::createFixture()
{
	m_fixtureDef.shape = &m_Shape;
	body()->CreateFixture(&m_fixtureDef);
}

void PhysicsObject::setAsBox(float w, float h)
{
	setBoundingBox(w, h);
}

void PhysicsObject::setPoints(int count, float points[][2])
{
	b2Vec2* vecPoints = new b2Vec2[count];
	for (int i = 0; i < count; i++)
		vecPoints[i] = b2Vec2(points[i][0] / Physics::Scale, points[i][1] / Physics::Scale);

	m_Shape.Set(vecPoints, count);
	delete vecPoints;
}

void PhysicsObject::createBody(b2World* world)
{
	setBody(world->CreateBody(&m_bodyDef));
}

void PhysicsObject::createBody(b2World* world, b2BodyType type, float linearDamping, float angularDamping, float density)
{
	setBodyType(type);
	setLinearDamping(linearDamping);
	setAngularDamping(angularDamping);
	createBody(world);
	setDensity(density);
	createFixture();
}

void PhysicsObject::startContact(PhysicsObject* object)
{
	m_isContacting = true;
	m_collideObject = object;
}

void PhysicsObject::endContact()
{
	m_collideObject = nullptr;
	m_isContacting = false;
}