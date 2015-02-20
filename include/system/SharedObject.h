
#ifndef SHAREDOBJECT_H
#define SHAREDOBJECT_H

#include "system/SharedScene.h"
#include "system/RenderableObject.h"
#include "system/PhysicsObject.h"

class SharedObject : public RenderableObject, public PhysicsObject
{
public:
	virtual ~SharedObject() {}

	void init(SharedScene* ownerScene) { m_Scene = ownerScene; }
	virtual void update() = 0;
	virtual void render() = 0;
	SharedScene* scene() { return m_Scene; }

private:
	SharedScene* m_Scene;
};

#endif