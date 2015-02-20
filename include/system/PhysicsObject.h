
#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include <Box2D/Box2D.h>
#include <glm/glm.hpp>

class PhysicsObject
{
public:
	PhysicsObject() {}
	~PhysicsObject() {}

	b2Body* body() { return m_Body; }
	void setBody(b2Body* body);
	void createBody(b2World* world);
	void createBody(b2World* world, b2BodyType type, float linearDamping, float angularDamping, float density);
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
	void startContact() { m_isContacting = true; }
	void endContact() { m_isContacting = false; }
	bool isContacting() { return m_isContacting; }

private:
	b2BodyDef m_bodyDef;
	b2Body* m_Body;
	b2FixtureDef m_fixtureDef;
	b2PolygonShape m_Shape;
	bool m_isContacting;
};

#endif	// PYSICSOBJECT_H