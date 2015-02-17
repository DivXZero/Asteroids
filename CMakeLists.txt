cmake_minimum_required(VERSION 3.1.0)

set(PROJECT_NAME "Asteroids")
project(${PROJECT_NAME})

set(HEADER_FILES
	include/Asteroids.h
	include/system/Window.h)

set(SOURCE_FILES
	source/main.cpp
	source/Asteroids.cpp
	source/system/Window.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

set(SFML_INCLUDE_DIR "dependencies/SFML/include")
set(BOX2D_INCLUDE_DIR "dependencies/Box2D")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

find_package(OpenGL)
if(OPENGL_FOUND)
	message("OpenGL Found")
	target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})
endif()

find_package(SFML 2 REQUIRED system window graphics audio)
if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

find_package(Box2D REQUIRED)
if(BOX2D_FOUND)
	message("Box2D Found")
	include_directories(${BOX2D_INCLUDE_DIR})
	target_link_libraries(${PROJECT_NAME} ${BOX2D_LIBRARIES})
endif()

include_directories(include)