
#include "system/Physics.h"

const float Physics::Scale = 30.0f;

Physics::Physics() :
m_Gravity(0.0f, 9.8f),
m_World(m_Gravity)
{
}

Physics::~Physics()
{
}