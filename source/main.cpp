
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Asteroids.h"

int main(int argc, char** argv[])
{
	Asteroids::Game game;

	if (!game.init())
		return -1;

	return 0;
}