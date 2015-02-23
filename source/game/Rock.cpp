
#include <glm/gtc/random.hpp>
#include "game/Ship.h"
#include "game/Rock.h"
#include "game/Bullet.h"

sf::Vector2f getRandomPosition(int w, int h)
{
	int x = glm::linearRand(0, w);
	int y = glm::linearRand(0, h);

	int gapX = w / 6;
	int gapY = h / 4;
	if (x < ((w / 2) + gapX) && x >((w / 2) - gapX) && (y < (h / 2) + gapY) && (y > (h / 2) - gapY))
		return getRandomPosition(w, h);

	return sf::Vector2f((float)x, (float)y);
}

void Rock::set(float scale)
{
	set(scale, getRandomPosition((int)scene()->window()->getWidth(), (int)scene()->window()->getHeight()), glm::linearRand(0, 360));
}

void Rock::set(float scale, sf::Vector2f pos, float angle)
{
	setScale(scale);

	setAsBox(60 / m_Scale, 60 / m_Scale);
	setColors();

	setPosition(pos.x, pos.y);

	createBody(scene()->physics()->world(), b2_dynamicBody, 0, 0, 5.0f);

	applyTorque((float)glm::linearRand(-2000, 2000));

	//float velocityX = (float)glm::linearRand(-5000, 5000);
	//float velocityY = (float)glm::linearRand(-5000, 5000);

	float velocityX = sin(glm::degrees(angle)) * m_Scale;
	float velocityY = cos(glm::degrees(angle)) * m_Scale;

	body()->ApplyForceToCenter(b2Vec2(velocityX, velocityY), true);
}

void Rock::init()
{
	
}

void Rock::update()
{
	checkOffscreen();

	if (isColliding<Bullet>())
	{
		destroy();
	}
}

void Rock::render()
{
	float currentX = getPosition().x;
	float currentY = getPosition().y;
	float mirrorX = (currentX < scene()->window()->getCenter().x) ? currentX + scene()->window()->getWidth() : currentX - scene()->window()->getWidth();
	float mirrorY = (currentY < scene()->window()->getCenter().y) ? currentY + scene()->window()->getHeight() : currentY - scene()->window()->getHeight();

	RenderableObject::setPosition(mirrorX, currentY);
	renderObject();
	RenderableObject::setPosition(currentX, mirrorY);
	renderObject();
}

void Rock::checkOffscreen()
{
	b2Vec2 position(body()->GetPosition().x * Physics::Scale, body()->GetPosition().y * Physics::Scale);

	if (position.x > scene()->window()->getWidth())
		body()->SetTransform(b2Vec2(0, position.y / Physics::Scale), body()->GetAngle());

	if (position.x < 0)
		body()->SetTransform(b2Vec2(scene()->window()->getWidth() / Physics::Scale, position.y / Physics::Scale), body()->GetAngle());

	if (position.y > scene()->window()->getHeight())
		body()->SetTransform(b2Vec2(position.x / Physics::Scale, 0), body()->GetAngle());

	if (position.y < 0)
		body()->SetTransform(b2Vec2(position.x / Physics::Scale, scene()->window()->getHeight() / Physics::Scale), body()->GetAngle());
}

void Rock::cleanup()
{
	
}