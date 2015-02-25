
#include "game/GameScene.h"
#include "game/Ship.h"

void Ship::init()
{
	float points[4][2] = { { -10, 10 }, { 0, -20 }, { 10, 10 }, {0, 0} };
	setPoints(4, points);
	setColors();
	setPosition(((float)scene()->window()->getCenter().x) - 10, ((float)scene()->window()->getCenter().y) - 10);
	createBody(scene()->physics()->world(), b2_dynamicBody, 0.5f, 10.0f, 5.0f);

	m_bulletBuffer.loadFromFile("resources/audio/fire.wav");
	m_bulletSound.setBuffer(m_bulletBuffer);
	m_thrustBuffer.loadFromFile("resources/audio/thrust.wav");
	m_thrustSound.setBuffer(m_thrustBuffer);
	m_thrustSound.setLoop(true);
	m_thumpLoBuffer.loadFromFile("resources/audio/thumplo.wav");
	m_thumpLoSound.setBuffer(m_thumpLoBuffer);
	m_thumpHiBuffer.loadFromFile("resources/audio/thumphi.wav");
	m_thumpHiSound.setBuffer(m_thumpHiBuffer);

	m_fireDelay = 0;
	m_blinkDelay = 0;
	m_blinkTime = 0;
	setVisible(false);
	m_isBlinking = true;
	m_lives = 3;
	m_thumpTime = 0;
	m_thumpSwitch = true;
}

void Ship::update()
{
	if (m_thumpTime >= (THUMP_DELAY + (m_lives * 15)))
	{
		if (m_thumpSwitch)
		{
			m_thumpLoSound.play();
		}
		else
		{
			m_thumpHiSound.play();
		}

		m_thumpSwitch = !m_thumpSwitch;
		m_thumpTime = 0;
	}

	m_thumpTime++;

	handleInput();
	checkOffscreen();

	if (m_fireDelay > 0)
		m_fireDelay--;

	if (m_blinkDelay > 0)
		m_blinkDelay--;

	if (m_blinkDelay == 0 && m_blinkTime < START_DELAY)
	{
		m_blinkTime += BLINK_DELAY;
		m_blinkDelay = BLINK_DELAY;
		setVisible(!isVisible());

		if (m_blinkTime >= START_DELAY)
		{
			setVisible(true);
			m_isBlinking = false;
		}
	}

	if (!m_isBlinking && isColliding())
	{
		reset();
	}
}

void Ship::render()
{
	float currentX = getPosition().x;
	float currentY = getPosition().y;
	float mirrorX = (currentX < scene()->window()->getCenter().x) ? currentX + scene()->window()->getWidth() : currentX - scene()->window()->getWidth();
	float mirrorY = (currentY < scene()->window()->getCenter().y) ? currentY + scene()->window()->getHeight() : currentY - scene()->window()->getHeight();

	RenderableObject::setPosition(mirrorX, currentY);
	renderObject();
	RenderableObject::setPosition(currentX, mirrorY);
	renderObject();

	RenderableObject::setRotation(0);
	RenderableObject::setScale(0.75, 0.75);
	for (int i = 0; i < m_lives; i++)
	{
		RenderableObject::setPosition((float)130 + (i * 22), (float)30);
		renderObject();
	}
	RenderableObject::setScale(1, 1);
}

void Ship::handleInput()
{
	// Forward
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (m_thrustSound.getStatus() == sf::Sound::Status::Stopped)
		{
			m_thrustSound.play();
		}

		float velocityX = body()->GetMass() * ACCELERATION * glm::sin(body()->GetAngle());
		float velocityY = body()->GetMass() * ACCELERATION * -glm::cos(body()->GetAngle());
		body()->ApplyForceToCenter(b2Vec2(velocityX, velocityY), true);
	}
	else
	{
		if (m_thrustSound.getStatus() == sf::Sound::Status::Playing)
		{
			m_thrustSound.stop();
		}
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

			scene()->addObject<Bullet>()->get()->set(body()->GetPosition(), body()->GetAngle());;
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

void Ship::cleanup()
{

}

void Ship::reset()
{
	if (m_lives <= 1)
	{
		destroy();
	}
	else
	{
		m_lives--;
		m_blinkDelay = 0;
		m_blinkTime = 0;
		setVisible(false);
		m_isBlinking = true;
		body()->SetTransform(b2Vec2(((scene()->window()->getCenter().x - 10) / Physics::Scale), ((scene()->window()->getCenter().y - 10) / Physics::Scale)), 0);
		body()->SetLinearVelocity(b2Vec2_zero);
		body()->SetAngularVelocity(0);
	}
}