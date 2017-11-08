#include "ball.h"
#include "paddle.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Ball::Ball()
{
	radius = 10;
	ball.setFillColor(sf::Color::Yellow);
	ball.setRadius(radius);
	ball.setPosition(400, 300);
	velocity = Vector2f(300, 300);
	ball.setOrigin(radius, radius);
	
}

void Ball::restart(){
	ball.setPosition(400, 300);
	srand(time(NULL));

	int n = rand() % 2 + 1;
	if (n == 1)
	velocity = Vector2f(-150, 100);
	else if (n == 0)
		velocity = Vector2f(150, 100);
}

void Ball::update(float deltaTime,Paddle player,Paddle AIplayer)
{
	ball.setPosition(ball.getPosition() + velocity * deltaTime);

	if (ball.getPosition().y > (600 - radius))
	{
		velocity.y = -velocity.y;
	}
	if (ball.getPosition().x > (800 - radius))
	{
		velocity.x = -velocity.x;
	}
	if (ball.getPosition().y < (0 + radius))
	{
		velocity.y = -velocity.y;
	}
	if (ball.getPosition().x <(0 + radius))
	{
		velocity.x = -velocity.x;
	}
	if (ball.getGlobalBounds().intersects(player.paddle.getGlobalBounds())) {
		velocity.x = -velocity.x + 70;//increase speed every time 
	}
	if (ball.getGlobalBounds().intersects(AIplayer.paddle.getGlobalBounds())) {
		velocity.x = -velocity.x - 70;
	}



}


Vector2f Ball::getPosition()
{
	return ball.getPosition();
}
