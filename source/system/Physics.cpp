
#include "system/Physics.h"
#include <iostream>

const float Physics::Scale = 30.0f;

Physics::Physics()
{
	m_Gravity = b2Vec2(0, 0);
	m_World = new b2World(m_Gravity);
}

Physics::~Physics()
{
	delete m_World;
}