#include "Paddle.h"



Paddle::Paddle(float xPos, float yPos)
{
	size = Vector2f(20, 70);
	paddle.setSize(size);
	paddle.setFillColor(sf::Color(222,184,135));
	paddle.setPosition(xPos, yPos);
	paddle.setOrigin(size.x / 2, size.y / 2);
	paddle.setOutlineThickness(3);
}


void Paddle::paddle_update(float deltaTime)
{
	Vector2f pos = paddle.getPosition();


	if (Keyboard::isKeyPressed(Keyboard::Up))
		if (paddle.getPosition().y - 50 > 0)
		pos.y -= 200 * deltaTime;
	if (Keyboard::isKeyPressed(Keyboard::Down))
		if (paddle.getPosition().y + 50 < 600)
		pos.y += 200 * deltaTime;

	paddle.setPosition(pos);

}





Vector2f Paddle::getPosition()
{
	return paddle.getPosition();
}


