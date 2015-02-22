
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

	int getSize() { return m_Objects.size(); }

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

template <class T>
void ObjectCollection<T>::update()
{
	for (auto objIter = m_Objects.begin(); objIter != m_Objects.end();)
	{
		(*objIter)->update();

		if ((*objIter)->isAlive())
		{
			objIter++;
		}
		else
		{
			(*objIter)->destroy();
			delete *objIter;
			objIter = m_Objects.erase(objIter);
		}	
	}
}

template <class T>
void ObjectCollection<T>::render()
{
	for (auto objIter = m_Objects.begin(); objIter != m_Objects.end(); objIter++)
		(*objIter)->render();
}

#endif