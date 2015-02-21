
#include "game/Bullet.h"
#include "game/Rock.h"

Bullet::~Bullet()
{
	scene()->physics()->world()->DestroyBody(body());
}

void Bullet::init()
{
	m_lifeTime = 0;
	m_isAlive = true;
}

void Bullet::set(b2Vec2 pos, float angle)
{
	setAsBox(2, 2);
	setColors(sf::Color(255, 255, 255, 255));

	createBody(scene()->physics()->world(), b2_dynamicBody, 0, 0, 1000.0f);
	pos.x += glm::sin(angle);
	pos.y -= glm::cos(angle);
	body()->SetTransform(pos, angle);
	float velocityX = glm::sin(angle) * BULLET_SPEED * body()->GetMass();
	float velocityY = -glm::cos(angle) * BULLET_SPEED * body()->GetMass();
	body()->ApplyForceToCenter(b2Vec2(velocityX, velocityY), true);
}

void Bullet::update()
{
	m_lifeTime++;
	checkOffscreen();

	if (getLifeTime() > BULLET_LIFETIME)
		m_isAlive = false;
}

void Bullet::render()
{
	RenderableObject::setPosition(body()->GetPosition().x * Physics::Scale, body()->GetPosition().y * Physics::Scale);
	RenderableObject::setRotation(glm::degrees(body()->GetAngle()));
	renderObject();
}

void Bullet::checkOffscreen()
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

void Bullet::destroy()
{
	m_isAlive = false;
}