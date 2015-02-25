
#ifndef OBJECT_H
#define OBJECT_H

#include "system/SharedObject.h"
#include <memory>

template <class T>
class Object : public SharedObject
{
public:
	Object() { m_pObject.reset(new T()); }
	~Object() { m_pObject.reset(); }

	void init() { get()->init(); }
	void update() { get()->updateObject(); get()->update(); }
	void render() { get()->renderObject(); get()->render(); }
	void destroy() { get()->destroy(); }
	bool isAlive() { return get()->isAlive(); }
	bool isVisible() { return get()->isVisible(); }

	T* get() { return m_pObject.get(); }

private:
	std::unique_ptr<T> m_pObject;
};

#endif