
#ifndef OBJECTCOLLECTION_H
#define OBJECTCOLLECTION_H

#include "system/Object.h"
#include "system/Singleton.h"
#include <vector>

template <class T>
class ObjectCollection
{
public:
	Object<T>* addObject();
	//void destroyObject(Object<T>* object);
	void update();
	void render();

	int getSize() { return m_Objects.size(); }
	std::vector<std::unique_ptr<Object<T>>>* getObjects() { return &m_Objects; }
	//std::vector<std::unique_ptr<Object<T>>>::iterator getIterator() { return m_Objects.begin(); }

private:
	std::vector<std::unique_ptr<Object<T>>> m_Objects;
};

template <class T>
using ObjectCollectionSingleton = Singleton<ObjectCollection<T>>;

template <class T>
Object<T>* ObjectCollection<T>::addObject()
{
	m_Objects.push_back(std::make_unique<Object<T>>());
	return m_Objects.back().get();
}

template <class T>
void ObjectCollection<T>::update()
{
	for (typename std::vector<std::unique_ptr<Object<T>>>::iterator obj = m_Objects.begin(); obj != m_Objects.end();)
	{
		if (!(*obj)->isAlive())
		{
			(*obj)->get()->destroyObject();
			obj->reset();
			obj = m_Objects.erase(obj);
		}
		else
		{
			(*obj)->update();
			obj++;
		}
	}
}

template <class T>
void ObjectCollection<T>::render()
{
	for (auto& obj : m_Objects)
	{
		if (obj->isAlive() && obj->isVisible())
			obj->render();
	}
}

#endif