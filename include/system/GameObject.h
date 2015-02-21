
#ifndef ASTEROIDS_GAMEOBJECT_H
#define ASTEROIDS_GAMEOBJECT_H

#include "system/PhysicsObject.h"
#include "system/RenderableObject.h"
#include "system/Scene.h"

class GameObject : public RenderableObject, public PhysicsObject
{
public:
	GameObject() {}
	~GameObject() {}

	virtual void update() = 0;
	virtual void render() = 0;
	void updateObject();
	void renderObject();
	void setPosition(float x, float y);
	void setAsBox(float w, float h);
	void setPoints(int count, float points[][2]);

	void setScene(Scene* ownerScene) { m_Scene = ownerScene; }
	Scene* scene() { return m_Scene; }

private:
	Scene* m_Scene;
};

#endif	// ASTEROIDS_GAMEOBJECT_H