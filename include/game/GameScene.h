
#ifndef ASTEROIDS_SCENE_H
#define ASTEROIDS_SCENE_H

#include "SFML/Audio.hpp"
#include "system/Scene.h"
#include "game/Ship.h"
#include "game/Rock.h"

#define SPLASH_TIME 300
#define MAX_ROCKS 4

class GameScene : public Scene
{
public:
	GameScene() {}
	~GameScene() {}

	void init();
	void update();
	void render();

	void reset(int stage);
	void DrawShadowText(const sf::Text* pNText);

private:
	sf::SoundBuffer m_explodeBuffer1;
	sf::SoundBuffer m_explodeBuffer2;
	sf::SoundBuffer m_explodeBuffer3;
	sf::Sound m_explodeSound1;
	sf::Sound m_explodeSound2;
	sf::Sound m_explodeSound3;

	sf::Font testFont;
	sf::Text testText;
	sf::Text stageText;
	int m_splashTime;
	bool m_showSplash;
	int m_Score;
	int m_Stage;
};

#endif	// ASTEROIDS_SCENE_H