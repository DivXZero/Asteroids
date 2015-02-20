
#ifndef ASTEROIDS_GAMEOBJECT_H
#define ASTEROIDS_GAMEOBJECT_H

#include "system/SharedObject.h"

class GameObject : public SharedObject
{
public:
	GameObject() {}
	~GameObject() {}

	void render();
	void setPosition(float x, float y);
	void setAsBox(float w, float h);
	void setPoints(int count, float points[][2]);
};

#endif	// ASTEROIDS_GAMEOBJECT_H