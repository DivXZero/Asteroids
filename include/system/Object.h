
#ifndef OBJECT_H
#define OBJECT_H

#include "system/SharedObject.h"

template <class T>
class Object : public SharedObject
{
public:
	Object() { m_Object = new T(); }
	~Object() {}

	void init() { get()->init(); }
	void update() { get()->updateObject(); get()->update(); }
	void render() { get()->renderObject(); get()->render(); }
	void destroy() { get()->destroyObject(); get()->destroy(); }
	bool isAlive() { return get()->isAlive(); }

	T* get() { return m_Object; }

private:
	T* m_Object;
};

#endif