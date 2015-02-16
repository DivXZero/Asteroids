
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

int main(int argc, char** argv[])
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Asteroids", sf::Style::Close);

	b2Vec2 gravity(0.0f, 9.8f);
	b2World world(gravity);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

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

		glClear(GL_COLOR_BUFFER_BIT);

		window.display();
	}

	return 0;
}