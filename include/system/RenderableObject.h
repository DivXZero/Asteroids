
#ifndef RENDERABLEOBJECT_H
#define RENDERABLEOBJECT_H

#include <SFML/Graphics.hpp>
#include "system/SharedObject.h"

class RenderableObject : public sf::ConvexShape, public SharedObject
{
public:
	RenderableObject() {}
	~RenderableObject() {}

	void setPoints(int count, float points[][2]);
	void setAsBox(float w, float h);
	void setColors(sf::Color fillColor = sf::Color(0, 0, 0, 255), sf::Color outlineColor = sf::Color(255, 255, 255, 255), float outlineThickness = 1);
};

#endif	// RENDERABLEOBJECT_H