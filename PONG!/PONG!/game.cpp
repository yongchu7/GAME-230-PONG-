#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "paddle.h"
#include "ball.h"
//#include "game.h"
//#include <unistd.h>
using namespace sf;
bool gamerun = true;

int PlayerScore;
int AIScore;
Text text;
RenderWindow window;
RectangleShape top;
RectangleShape left;
RectangleShape right;
RectangleShape bottom;
RectangleShape middleLine;



bool intersects(const CircleShape & rect1, const RectangleShape & rect2)
{
	FloatRect r1 = rect1.getGlobalBounds();
	FloatRect r2 = rect2.getGlobalBounds();
	return r1.intersects(r2);
}

int clamp(const int x, const int a, const int b)
{
	return std::min(std::max(a, x), b);
}

void playground();

Ball ball;
Paddle player(20, 300);
Paddle AIplayer(780, 300);

void AI_update(float deltaTime)
{
	Vector2f AIpos = AIplayer.paddle.getPosition();

	if (ball.getPosition().y > AIpos.y)
	{
		AIpos.y = AIpos.y + 200 * deltaTime;
	}
	else if (ball.getPosition().y < AIpos.y)
	{
		AIpos.y = AIpos.y - 200 * deltaTime;
	}

	AIplayer.paddle.setPosition(AIpos);

}





	int main()
	{
		window.create(VideoMode(800, 600), "Pong");
	
		Music music;
		music.openFromFile("BGM.ogg");
		music.play();
		Clock clock;

		
			while (window.isOpen())
			{
				
					playground();
					if (gamerun == true) {

					Event event;
					while (window.pollEvent(event))
					{
						if (event.type == sf::Event::Closed)
							window.close();
					}
					
						float dt = clock.restart().asSeconds();

						ball.update(dt, player, AIplayer);
						player.paddle_update(dt);

						AI_update(dt);
					}
					
					window.display();
				
			}
		
		



		return 0;
	}

Text score;
void restartgame() {

	PlayerScore = 0;
	AIScore = 0;
}
void playground()
{

	Font font;
	font.loadFromFile("arial.ttf");

	Texture texture;
	texture.loadFromFile("background.jpg");
	Sprite background;
	background.setTexture(texture);
	background.setTextureRect(IntRect(10,10,800,600));
	background.setColor(sf::Color(255, 255, 255, 128));

	top.setPosition(0, 0);
	top.setSize(Vector2f(800, 0));

	bottom.setPosition(0, 600);
	bottom.setSize(Vector2f(800, 600));

	left.setPosition(0, 0);
	left.setSize(Vector2f(0, 600));

	right.setPosition(800, 0);
	right.setSize(Vector2f(800, 600));

	middleLine.setPosition(400, 0);
	middleLine.setSize(Vector2f(0, 600));

	top.setFillColor(Color(100, 100, 100));
	top.setOutlineColor(Color::Red);
	top.setOutlineThickness(5);

	bottom.setFillColor(Color(100, 100, 100));
	bottom.setOutlineColor(Color::Red);
	bottom.setOutlineThickness(5);

	left.setFillColor(Color(100, 100, 100));
	left.setOutlineColor(Color::Red);
	left.setOutlineThickness(5);

	right.setFillColor(Color(100, 100, 100));
	right.setOutlineColor(Color::Red);
	right.setOutlineThickness(5);


	middleLine.setFillColor(Color(100, 100, 100));
	middleLine.setOutlineColor(Color::Green);
	middleLine.setOutlineThickness(1);

	
	

	Text score;
	score.setCharacterSize(50);
	score.setFont(font);
	score.setPosition(20 , 40);
	score.setColor(Color::Green);
	std::stringstream string;
	string << PlayerScore;
	score.setString(string.str());

	Text score2;
	score2.setCharacterSize(50);
	score2.setFont(font);
	score2.setPosition(740, 40);
	score2.setColor(Color::Red);
	std::stringstream string2;
	string2 << AIScore;
	score2.setString(string2.str());
	
	Text won("You have won this game.\n\n Congratulations ! Press SPACE bar to restart!", font, 20);
	won.setPosition(400 - won.getGlobalBounds().width / 2,300 - won.getGlobalBounds().height / 2);
	won.setColor(Color::Green);
	
	Text lost("You have lost this game, \n better luck next time!Press SPACE bar to restart!", font, 20);
	lost.setPosition(400 -lost.getGlobalBounds().width / 2,300- lost.getGlobalBounds().height / 2);
	lost.setColor(Color::Red);

	if (ball.getPosition().x <= 20) {
		AIScore = AIScore + 1;
		ball.restart();
		
	}
	
	if (ball.getPosition().x >= 780) {
		PlayerScore = PlayerScore + 1;
		ball.restart();
		
	}
	 
	

	

	


	window.clear(Color::Black);
	window.draw(background);
	window.draw(left);
	window.draw(right);
	window.draw(ball.ball);
	window.draw(top);
	window.draw(bottom);
	window.draw(player.paddle);
	window.draw(AIplayer.paddle);
	window.draw(middleLine);
	window.draw(score);
	window.draw(score2);
	if (PlayerScore == 5) {
		//window.clear(Color::Black);
		//window.draw(won);
		gamerun = false;
		
		PlayerScore = 0;
		AIScore = 0;
		//sleep(5);
		//restartgame();
		//playground();
		//window.display();
	}
	if (AIScore == 5) {
		
		
		gamerun = false;
		window.clear(Color::Black);
		window.draw(lost);
		//restartgame();
		//sleep(5);
		PlayerScore = 0;
		AIScore = 0;
		//playground();
		}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		gamerun = true;
	}
	}


