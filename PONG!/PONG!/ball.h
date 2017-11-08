#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include"paddle.h"

using namespace sf;


class Ball
{
public:

	CircleShape ball;
	float radius;
	Vector2f velocity;

	Ball();

	void update(float deltaTime,Paddle player,Paddle AIplayer);
	void restart();
	Vector2f getPosition();

};