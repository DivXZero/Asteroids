
#include "game/GameScene.h"
#include <sstream>

void GameScene::init()
{
	window()->showCursor(false);

	m_explodeBuffer1.loadFromFile("resources/audio/explode1.wav");
	m_explodeSound1.setBuffer(m_explodeBuffer1);
	m_explodeBuffer2.loadFromFile("resources/audio/explode2.wav");
	m_explodeSound2.setBuffer(m_explodeBuffer2);
	m_explodeBuffer3.loadFromFile("resources/audio/explode3.wav");
	m_explodeSound3.setBuffer(m_explodeBuffer3);

	m_Stage = 1;
	reset(1);

	testFont.loadFromFile("resources/fonts/arcadeclassic.ttf");
	testText = sf::Text("Score", testFont, 30);
	testText.setPosition(20, 5);
	m_Score = 0;
}

void GameScene::update()
{
	updateCollection<Ship>();
	updateCollection<Rock>();
	updateCollection<Bullet>();

	for (auto& rock : *getObjectCollection<Rock>()->getObjects())
	{
		if (!rock->isAlive())
		{
			int scale = (int)rock->get()->getScale();
			m_Score += (int)(3 * glm::pow(2, (int)(scale - 1)));

			switch (scale)
			{
			case 1:
				m_explodeSound1.play();
				break;

			case 2:
				m_explodeSound2.play();
				break;

			case 3:
				m_explodeSound3.play();
				break;

			default:
				break;
			}
		}
	}

	std::ostringstream ss;
	ss << m_Score;

	testText.setString(ss.str());

	if (getObjectCollection<Rock>()->getSize() == 0)
	{
		reset(m_Stage+1);
	}
	else
	{
		if (getObjectCollection<Ship>()->getSize() < 1 && !m_showSplash)
		{
			reset(0);
		}
	}

	if (m_showSplash)
	{
		m_splashTime++;

		if (m_splashTime >= SPLASH_TIME && m_Stage > 0)
		{
			addObject<Ship>();
			m_showSplash = false;
		}
	}
}

void GameScene::render()
{
	renderCollection<Rock>();
	renderCollection<Bullet>();
	renderCollection<Ship>();

	//window()->getWindow()->draw(testText);
	DrawShadowText(&testText);

	if (m_showSplash || m_Stage == 0)
	{
		sf::FloatRect textRect = stageText.getLocalBounds();
		stageText.setPosition(window()->getCenter().x - (stageText.getLocalBounds().width / 2), (window()->getCenter().y / 2) - (stageText.getLocalBounds().height / 2));
		DrawShadowText(&stageText);
	}
}

void GameScene::reset(int stage)
{
	stageText = sf::Text("", testFont, 80);
	std::ostringstream ss;

	if (stage > 0)
	{
		if (stage > 1)
		{
			for (auto& rock : *getObjectCollection<Rock>()->getObjects())
			{
				rock->destroy();
			}

			for (auto& bullet : *getObjectCollection<Bullet>()->getObjects())
			{
				bullet->destroy();
			}

			for (auto& ship : *getObjectCollection<Ship>()->getObjects())
			{
				ship->destroy();
			}
		}

		for (int i = 0; i < MAX_ROCKS * stage; i++)
		{
			addObject<Rock>()->get()->set(1);
		}

		ss << "Stage  " << m_Stage;
		m_Stage++;
	}
	else
	{
		m_Stage = 0;
		ss << "Game Over";
	}
	
	stageText.setString(ss.str());
	m_splashTime = 0;
	m_showSplash = true;
}

void GameScene::DrawShadowText(const sf::Text* pNText)
{
	//[CREATE OULINE COLOUR: BLACK + ORIGINAL TEXT ALPHA]
	static sf::Color outlineColour;
	outlineColour = sf::Color(sf::Color::Black.r, sf::Color::Black.g, sf::Color::Black.b, pNText->getColor().a);
	sf::Text m_tempTextOutline;

	//[DRAW OUTLINES(BLACK)]
	{
		m_tempTextOutline = sf::Text(*pNText);
		m_tempTextOutline.setColor(outlineColour);
		m_tempTextOutline.setPosition(sf::Vector2f(m_tempTextOutline.getPosition().x + 2, m_tempTextOutline.getPosition().y));
		window()->getWindow()->draw(m_tempTextOutline);

		m_tempTextOutline = sf::Text(*pNText);
		m_tempTextOutline.setColor(outlineColour);
		m_tempTextOutline.setPosition(sf::Vector2f(m_tempTextOutline.getPosition().x - 2, m_tempTextOutline.getPosition().y));
		window()->getWindow()->draw(m_tempTextOutline);

		m_tempTextOutline = sf::Text(*pNText);
		m_tempTextOutline.setColor(outlineColour);
		m_tempTextOutline.setPosition(sf::Vector2f(m_tempTextOutline.getPosition().x, m_tempTextOutline.getPosition().y + 2));
		window()->getWindow()->draw(m_tempTextOutline);

		m_tempTextOutline = sf::Text(*pNText);
		m_tempTextOutline.setColor(outlineColour);
		m_tempTextOutline.setPosition(sf::Vector2f(m_tempTextOutline.getPosition().x, m_tempTextOutline.getPosition().y - 2));
		window()->getWindow()->draw(m_tempTextOutline);

		m_tempTextOutline = sf::Text();
	}

	//[DRAW ORIGINAL TEXT]
	window()->getWindow()->draw(*pNText);
}