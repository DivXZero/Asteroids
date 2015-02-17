
#ifndef ASTEROIDS_SHAREDSCENE_H
#define ASTEROIDS_SHAREDSCENE_H

class SharedScene
{
public:
	virtual ~SharedScene() {}
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};

#endif	// ASTEROIDS_SCENE_H