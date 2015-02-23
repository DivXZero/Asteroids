
#include "game/GameScene.h"
#include <iostream>

void GameScene::init()
{
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
}

void GameScene::render()
{
	renderCollection<Ship>();
	renderCollection<Rock>();
	renderCollection<Bullet>();
}