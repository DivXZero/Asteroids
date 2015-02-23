
#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include <Box2D/Box2D.h>
#include <glm/glm.hpp>
#include "system/SharedObject.h"

class PhysicsObject : public SharedObject
{
public:
	PhysicsObject() : m_isContacting(false) {}
	~PhysicsObject() {}

	b2Body* body() { return m_Body; }
	void setBody(b2Body* body);
	void createBody(b2World* world);
	void createBody(b2World* world, b2BodyType type, float linearDamping, float angularDamping, float density);
	void destroyBody(b2World* world) { world->DestroyBody(m_Body); }
	void setPosition(float x, float y);
	void setBodyType(b2BodyType type);
	void setLinearDamping(float amt);
	void setAngularDamping(float amt);
	void setBoundingBox(float w, float h);
	void setAsBox(float w, float h);
	void setPoints(int count, float points[][2]);
	void setDensity(float density) { m_fixtureDef.density = density; }
	void createFixture();
	void applyTorque(float amt) { body()->ApplyTorque(amt, true); }
	void startContact(PhysicsObject* object);
	void endContact();
	bool isColliding();
	template <class T> bool isType();
	template <class T> T* getType();
	template <class T> bool isColliding();
	template <class T> T* getCollider();
	PhysicsObject* getCollider() { return getCollider<PhysicsObject>(); }
	// const char* getTypeName() { return typeid(*this).name(); }
	virtual void update() = 0;

private:
	b2BodyDef m_bodyDef;
	b2Body* m_Body;
	b2FixtureDef m_fixtureDef;
	b2PolygonShape m_Shape;
	bool m_isContacting;
	PhysicsObject* m_collideObject;
};

template <class T>
bool PhysicsObject::isType()
{
	if (nullptr != getType<T>())
		return true;
	
	return false; 
}

template <class T>
T* PhysicsObject::getType()
{
	return dynamic_cast<T*>(this);
}

template <class T>
T* PhysicsObject::getCollider()
{
	return m_collideObject->getType<T>();
}

template <class T>
bool PhysicsObject::isColliding()
{
	if (isColliding())
		if (m_collideObject->isType<T>())
			return true;
	
	return false;
}

#endif	// PYSICSOBJECT_H