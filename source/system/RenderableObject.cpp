
#include "system/RenderableObject.h"

void RenderableObject::setAsBox(float w, float h)
{
	float points[4][2] = { { -(w / 2), -(h / 2) },	// Btm left
						   { -(w / 2), (h / 2) },	// Top Left
						   { (w / 2), (h / 2)},		// Top Right
						   { (w / 2), -(h / 2) }	// Bottom Right
	};
	setPoints(4, points);
}

void RenderableObject::setPoints(int count, float points[][2])
{
	setPointCount(count);
	for (int i = 0; i < count; i++)
		setPoint(i, sf::Vector2f(points[i][0], points[i][1]));
}

void RenderableObject::setColors(sf::Color fillColor, sf::Color outlineColor, float outlineThickness)
{
	setFillColor(fillColor);
	setOutlineColor(outlineColor);
	setOutlineThickness(outlineThickness);
}