
#ifndef ASTEROIDS_SHIP_H
#define ASTEROIDS_SHIP_H

#include <SFML/Graphics.hpp>
#include "game/Scene.h"

class Ship : public sf::ConvexShape
{
public:
	Ship();
	~Ship();

	void init(Scene* ownerScene);
	void update();
	void render();
	Scene* scene() { return m_Scene; }

private:
	Scene* m_Scene;
	b2BodyDef m_bodyDef;
	b2Body* m_Body;
	b2PolygonShape m_Shape;
	b2FixtureDef m_fixtureDef;
};

#endif