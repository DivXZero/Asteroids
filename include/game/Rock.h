
#ifndef ASTEROIDS_ROCK_H
#define ASTEROIDS_ROCK_H

#include "game/Scene.h"
#include "system/PhysicsObject.h"
#include "system/RenderableObject.h"

class Rock : public RenderableObject, PhysicsObject
{
public:
	Rock() {}
	~Rock() {}

	void init(Scene* ownerScene);
	void update();
	void render();
	void setPosition(float x, float y);
	void setPoints(int count, float points[][2]);
	Scene* scene() { return m_Scene; }

private:
	void checkOffscreen();

	Scene* m_Scene;
	b2BodyDef m_bodyDef;
	b2Body* m_Body;
	b2FixtureDef m_fixtureDef;
	b2PolygonShape m_Shape;
};

#endif