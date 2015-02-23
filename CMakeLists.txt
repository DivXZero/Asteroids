cmake_minimum_required(VERSION 2.8.0)

set(PROJECT_NAME "Asteroids")
project(${PROJECT_NAME})

include("include/CMakeLists.txt")
include("source/CMakeLists.txt")

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

if(UNIX)
	list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")
endif()

source_group("Header Files\\Game" FILES ${GAME_HEADER_FILES})
source_group("Source Files\\Game" FILES ${GAME_SOURCE_FILES})
source_group("Header Files\\System" FILES ${SYSTEM_HEADER_FILES})
source_group("Source Files\\System" FILES ${SYSTEM_SOURCE_FILES})

set(SFML_INCLUDE_DIR "dependencies/SFML/include")
set(BOX2D_INCLUDE_DIR "dependencies/Box2D")
set(GLM_INCLUDE_DIR "dependencies/glm")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

find_package(OpenGL REQUIRED)
if(OPENGL_FOUND)
	message(STATUS "OpenGL Found")
	target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})
endif()

if(WIN32)
	set(SFML_STATIC_LIBRARIES TRUE)
endif()
find_package(SFML 2 REQUIRED system window graphics audio)
if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(${PROJECT_NAME} ${SFML_DEPENDENCIES})
	target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

find_package(Box2D REQUIRED)
if(BOX2D_FOUND)
	message(STATUS "Box2D Found")
	include_directories(${BOX2D_INCLUDE_DIR})
	target_link_libraries(${PROJECT_NAME} ${BOX2D_LIBRARIES})
endif()

include_directories(${GLM_INCLUDE_DIR})
include_directories(include)

file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION /)