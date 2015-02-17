
#include "Asteroids.h"

using namespace Asteroids;

Game::Game()
{
}

Game::~Game()
{
}

bool Game::init()
{
	if (!window.init(1024, 768, "Asteroids", false))
		return false;

	return true;
}