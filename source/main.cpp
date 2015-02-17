
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "game/Asteroids.h"

int main(int argc, char** argv[])
{
	Game game;

	if (!game.init())
		return -1;

	while (game.isRunning())
	{
		game.update();
	}

	return 0;
}