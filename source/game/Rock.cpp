
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

void Rock::init()
{
	//float points[8][2] = { { -40, 0 }, { -35, -20 }, { -20, -25 }, { -20, -40 }, { 0, -45 }, { 10, -30 }, { 20, -25 }, { 20, -10 } };
	float points[8][2];
	points[0][0] = (float)glm::linearRand(-40, -20); points[0][1] = 0;
	points[1][0] = (float)glm::linearRand(-20, 0); points[1][1] = (float)glm::linearRand(-30, -10);
	points[2][0] = 0; points[2][1] = (float)glm::linearRand(-40, -20);
	points[3][0] = (float)glm::linearRand(20, 40); points[3][1] = (float)glm::linearRand(-30, -10);
	points[4][0] = (float)glm::linearRand(20, 40); points[4][1] = 0;
	points[5][0] = (float)glm::linearRand(0, 20); points[5][1] = (float)glm::linearRand(0, 20);
	points[6][0] = 0; points[6][1] = (float)glm::linearRand(20, 40);
	points[7][0] = (float)glm::linearRand(-40, -20); points[7][1] = (float)glm::linearRand(10, 30);
	//setPoints(8, points);
	setAsBox(20, 20);
	setColors();
	
	sf::Vector2f pos = getRandomPosition((int)scene()->window()->getWidth(), (int)scene()->window()->getHeight());
	setPosition(pos.x, pos.y);

	createBody(scene()->physics()->world(), b2_dynamicBody, 0, 0, 5.0f);

	applyTorque((float)glm::linearRand(-2000, 2000));

	float velocityX = (float)glm::linearRand(-5000, 5000);
	float velocityY = (float)glm::linearRand(-5000, 5000);
	body()->ApplyForceToCenter(b2Vec2(velocityX, velocityY), true);

	//m_explodeBuffer.loadFromFile("resources/audio/explode1.wav");
	//m_explodeSound.setBuffer(m_explodeBuffer);
	//m_explodeSound.setVolume(10.0f);

	m_colorFade = 0;
}

void Rock::update()
{
	//if (isColliding<Bullet>())
	if (isColliding())
	{
		//m_explodeSound.play();
		//getCollider<Bullet>()->kill();
		m_colorFade = 100;
	}
	else
	{
		if (m_colorFade > 0)
			m_colorFade -= 5;
	}
	
	setColors(sf::Color(m_colorFade, m_colorFade, m_colorFade, 255));

	checkOffscreen();
}

void Rock::render()
{
	RenderableObject::setPosition(body()->GetPosition().x * Physics::Scale, body()->GetPosition().y * Physics::Scale);
	RenderableObject::setRotation(glm::degrees(body()->GetAngle()));
	renderObject();
	
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