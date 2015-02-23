
#include "game/GameScene.h"

void GameScene::init()
{
	m_explodeBuffer1.loadFromFile("resources/audio/explode1.wav");
	m_explodeSound1.setBuffer(m_explodeBuffer1);
	m_explodeBuffer2.loadFromFile("resources/audio/explode2.wav");
	m_explodeSound2.setBuffer(m_explodeBuffer2);
	m_explodeBuffer3.loadFromFile("resources/audio/explode3.wav");
	m_explodeSound3.setBuffer(m_explodeBuffer3);

	for (int i = 0; i < MAX_ROCKS; i++)
	{
		addObject<Rock>()->get()->set(1);
	}

	addObject<Ship>();
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
			switch ((int)rock->get()->getScale())
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
}

void GameScene::render()
{
	renderCollection<Ship>();
	renderCollection<Rock>();
	renderCollection<Bullet>();
}