#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h> 
#include <time.h>

using namespace sf;

class Game
{
public:
	RectangleShape rect;
	float dx, dy;
	float width, height;
	Game(float width, float height, float dx, float dy)
	{
		this -> width = width;
		this -> height = height;
		this -> dx = dx;
		this -> dy = dy;
		RectangleShape rectangle(Vector2f(width, height));
		rect = rectangle;
		rect.setPosition(Vector2f(rand() % 700, rand() % 700));
	}
	void update()
	{
		Vector2f v = rect.getPosition();
		if (v.x + dx + width > 800 || v.x + dx < 0)
			dx *= -1;
		if (v.y + dy + height > 800 || v.y + dy < 0)
			dy *= -1;
		rect.setPosition(Vector2f(v.x + dx, v.y + dy));
	}
};