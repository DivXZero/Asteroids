
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

int main(int argc, char** argv[])
{
	sf::Window window(sf::VideoMode(1024, 768), "Asteroids", sf::Style::Close);

	b2Vec2 gravity(0.0f, 9.8f);
	b2World world(gravity);

	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			default:
				break;
			}
		}
	}

	return 0;
}