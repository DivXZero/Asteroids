
#ifndef ASTEROIDS_GAMEOBJECT_H
#define ASTEROIDS_GAMEOBJECT_H

#include "system/PhysicsObject.h"
#include "system/RenderableObject.h"
#include "system/Scene.h"

class GameObject : public RenderableObject, public PhysicsObject
{
public:
	GameObject() : m_isAlive(true) {}
	~GameObject() {}

	virtual void update() = 0;
	virtual void render() = 0;
	virtual void cleanup() = 0;
	void destroy() { m_isAlive = false; }
	void updateObject();
	void renderObject();
	void destroyObject();
	void setPosition(float x, float y);
	void setAsBox(float w, float h);
	void setPoints(int count, float points[][2]);
	bool isAlive() { return m_isAlive; }

	void setScene(Scene* ownerScene) { m_Scene = ownerScene; }
	Scene* scene() { return m_Scene; }

private:
	Scene* m_Scene;
	bool m_isAlive;
};

#endif	// ASTEROIDS_GAMEOBJECT_H