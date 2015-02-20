
set(GAME_SOURCE_FILES
	source/game/Asteroids.cpp
	source/game/Scene.cpp
	source/game/Ship.cpp
	source/game/Rock.cpp
	source/game/Bullet.cpp
)

set(SYSTEM_SOURCE_FILES
	source/system/Game.cpp
	source/system/GameObject.cpp
	source/system/Event.cpp
	source/system/Physics.cpp
	source/system/Window.cpp
	source/system/PhysicsObject.cpp
	source/system/RenderableObject.cpp
	source/system/PhysicsCollision.cpp
)

set(SOURCE_FILES
	${GAME_SOURCE_FILES}
	${SYSTEM_SOURCE_FILES}
	source/main.cpp
)