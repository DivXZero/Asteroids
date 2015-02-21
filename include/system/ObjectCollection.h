
#ifndef OBJECTCOLLECTION_H
#define OBJECTCOLLECTION_H

#include "system/Object.h"
#include "system/Singleton.h"
#include <vector>

template <class T>
class ObjectCollection
{
public:
	void addObject(Object<T>* object);
	//void destroyObject(Object<T>* object);
	void update();
	void render();

private:
	std::vector<Object<T>*> m_Objects;
};

template <class T>
using ObjectCollectionSingleton = Singleton<ObjectCollection<T>>;

template <class T>
void ObjectCollection<T>::addObject(Object<T>* object)
{
	m_Objects.push_back(object);
}
/*

template <class T>
void ObjectCollection::destroyObject(Object<T>* object)
{
	for (m_ObjectIter = m_Objects.begin(); m_ObjectIter != m_Objects.end();)
	if (object == (*m_ObjectIter))
	{
		delete *m_ObjectIter;
		m_Objects.erase(m_ObjectIter);
	}
}
*/

template <class T>
void ObjectCollection<T>::update()
{
	typename std::vector<Object<T>*>::iterator objIter;
	for (objIter = m_Objects.begin(); objIter != m_Objects.end(); objIter++)
		(*objIter)->update();
}

template <class T>
void ObjectCollection<T>::render()
{
	typename std::vector<Object<T>*>::iterator objIter;
	for (objIter = m_Objects.begin(); objIter != m_Objects.end(); objIter++)
		(*objIter)->render();
}

#endif