
#ifndef ASTEROIDS_GAMEOBJECT_H
#define ASTEROIDS_GAMEOBJECT_H

#include "system/SharedScene.h"
#include "system/RenderableObject.h"
#include "system/PhysicsObject.h"

class GameObject : public RenderableObject, public PhysicsObject
{
public:
	GameObject() {}
	~GameObject() {}

	void init(SharedScene* ownerScene);
	void update();
	void render();
	void setPosition(float x, float y);
	void setAsBox(float w, float h);
	void setPoints(int count, float points[][2]);
	SharedScene* scene() { return m_Scene; }

private:
	SharedScene* m_Scene;
};

#endif	// ASTEROIDS_GAMEOBJECT_H