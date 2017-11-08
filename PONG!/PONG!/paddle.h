#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

//#include "ball.h"

using namespace sf;

class Paddle
{
public:

	RectangleShape paddle;
	Vector2f size;
	Paddle(float xPos, float yPos);
	void paddle_update(float deltaTime);
	Vector2f getPosition();
	
};
