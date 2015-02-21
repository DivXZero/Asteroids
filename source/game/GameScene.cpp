
#include "game/GameScene.h"

void GameScene::init()
{
	addObject<Ship>(&m_ship);

	for (int i = 0; i < MAX_ROCKS; i++)
		addObject<Rock>(&m_rockObject[i]);
}

void GameScene::update()
{
	updateCollection<Ship>();
	updateCollection<Bullet>();
	updateCollection<Rock>();
}

void GameScene::render()
{
	renderCollection<Ship>();
	renderCollection<Bullet>();
	renderCollection<Rock>();
}