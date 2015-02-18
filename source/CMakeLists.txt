
set(GAME_SOURCE_FILES
	source/game/Asteroids.cpp
	source/game/Scene.cpp
	source/game/Ship.cpp
)

set(SYSTEM_SOURCE_FILES
	source/system/Event.cpp
	source/system/Physics.cpp
	source/system/Window.cpp
	source/system/PhysicsObject.cpp
	source/system/RenderableObject.cpp
)

set(SOURCE_FILES
	${GAME_SOURCE_FILES}
	${SYSTEM_SOURCE_FILES}
	source/main.cpp
)