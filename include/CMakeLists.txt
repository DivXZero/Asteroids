
set(GAME_HEADER_FILES
	include/game/Asteroids.h
	include/game/Scene.h
	include/game/Ship.h
	include/game/Rock.h
	include/game/Bullet.h
)

set(SYSTEM_HEADER_FILES
	include/system/Game.h
	include/system/GameObject.h
	include/system/Event.h
	include/system/Physics.h
	include/system/SharedScene.h
	include/system/Window.h
	include/system/PhysicsObject.h
	include/system/RenderableObject.h
)

set(HEADER_FILES
	${GAME_HEADER_FILES}
	${SYSTEM_HEADER_FILES}
)