
#include "game/GameScene.h"

#define MAX_ROCKS 50

void GameScene::init()
{
	addObject<Ship>(&m_ship);

	for (int i = 0; i < MAX_ROCKS; i++)
		addObject<Rock>(new Object<Rock>);
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