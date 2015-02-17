
#ifndef ASTEROIDS_GAME_H
#define ASTEROIDS_GAME_H

#include "system/Window.h"

namespace Asteroids
{
	class Game
	{
	public:
		Game();
		~Game();

		bool init();

	private:
		Window window;
	};
}

#endif	// ASTEROIDS_GAME_H