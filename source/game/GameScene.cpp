
#include "game/GameScene.h"
#include <iostream>

void GameScene::init()
{
	addObject<Ship>(&m_ship);

	for (int i = 0; i < MAX_ROCKS; i++)
	{
		rock[i] = new Object<Rock>();
		rock[i]->get()->set(1);
		addObject<Rock>(rock[i]);
	}
}

void GameScene::update()
{
	updateCollection<Ship>();
	updateCollection<Rock>();
	updateCollection<Bullet>();
}

void GameScene::render()
{
	renderCollection<Ship>();
	renderCollection<Rock>();
	renderCollection<Bullet>();
}