
#include "game/Asteroids.h"

typedef Singleton<Asteroids> AsteroidsGame;

int main(int argc, char** argv)
{
	AsteroidsGame::Instance()->init();

	while (AsteroidsGame::Instance()->isRunning())
	{
		AsteroidsGame::Instance()->update();
	}

	return 0;
}