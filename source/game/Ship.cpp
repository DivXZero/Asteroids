
#include "game/Ship.h"

void Ship::init(SharedScene* ownerScene)
{
	GameObject::init(ownerScene);
	float points[4][2] = { { -10, 10 }, { 0, -20 }, { 10, 10 }, {0, 0} };
	setPoints(4, points);
	setColors();
	setPosition(((float)scene()->window()->getCenter().x) - 10, ((float)scene()->window()->getCenter().y) - 10);
	createBody(scene()->physics()->world(), b2_dynamicBody, 0.5f, 5.0f, 5.0f);

	m_bulletBuffer.loadFromFile("resources/audio/shoot.wav");
	m_bulletSound.setBuffer(m_bulletBuffer);

	m_fireDelay = 0;
}

void Ship::update()
{
	std::vector<Bullet*>::iterator bullet;
	for (bullet = m_Bullets.begin(); bullet != m_Bullets.end();)
	{
		(*bullet)->update();

		if (!(*bullet)->isAlive())
		{
			delete *bullet;
			bullet = m_Bullets.erase(bullet);
		}
		else {
			bullet++;
		}
	}

	handleInput();
	checkOffscreen();

	if (m_fireDelay > 0)
		m_fireDelay--;
}

void Ship::render()
{
	GameObject::render();

	float currentX = getPosition().x;
	float currentY = getPosition().y;
	float mirrorX = (currentX < scene()->window()->getCenter().x) ? currentX + scene()->window()->getWidth() : currentX - scene()->window()->getWidth();
	float mirrorY = (currentY < scene()->window()->getCenter().y) ? currentY + scene()->window()->getHeight() : currentY - scene()->window()->getHeight();
	RenderableObject::setPosition(mirrorX, currentY);
	scene()->window()->getWindow()->draw(*this);
	RenderableObject::setPosition(currentX, mirrorY);
	scene()->window()->getWindow()->draw(*this);

	std::vector<Bullet*>::iterator bullet;
	for (bullet = m_Bullets.begin(); bullet < m_Bullets.end(); bullet++)
	{
		(*bullet)->render();
	}
}

void Ship::handleInput()
{
	// Forward
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		float velocityX = body()->GetMass() * ACCELERATION * glm::sin(body()->GetAngle());
		float velocityY = body()->GetMass() * ACCELERATION * -glm::cos(body()->GetAngle());
		body()->ApplyForceToCenter(b2Vec2(velocityX, velocityY), true);
	}

	// Rotate CCW (left)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		applyTorque(-ROTATION);

	// Rotate CW (right)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		applyTorque(ROTATION);

	// Fire Bullet
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (m_fireDelay == 0)
		{
			m_fireDelay = FIRE_DELAY;
			m_bulletSound.play();
			m_Bullets.push_back(new Bullet(scene(), body()->GetPosition(), body()->GetAngle()));
		}
	}
}

void Ship::checkOffscreen()
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