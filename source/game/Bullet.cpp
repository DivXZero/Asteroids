
#include <glm/glm.hpp>
#include "game/Bullet.h"

#define BULLET_SPEED 2000

void Bullet::init(SharedScene* ownerScene, b2Vec2 pos, float angle)
{
	GameObject::init(ownerScene);
	setAsBox(2, 2);
	setColors(sf::Color(255, 255, 255, 255));

	createBody(scene()->physics()->world(), b2_dynamicBody, 0, 0, 100.0f);
	pos.x += glm::sin(angle);
	pos.y -= glm::cos(angle);
	body()->SetTransform(pos, angle);
	float velocityX = glm::sin(angle) * BULLET_SPEED * body()->GetMass();
	float velocityY = -glm::cos(angle) * BULLET_SPEED * body()->GetMass();
	body()->ApplyForceToCenter(b2Vec2(velocityX, velocityY), true);
}

void Bullet::update()
{
	checkOffscreen();
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