#include <SFML/Graphics.hpp>
#include "game.h"

using namespace sf;

int height = 800;
int width = 800;

int main()
{
    RenderWindow window(VideoMode(width, height), "SFML works!");
    window.setPosition(Vector2i((1920 - width) / 2, (1080 - height) / 2));
    Game game(100, 100, -0.1, 0.1);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
        }
        window.clear();
        game.update();
        window.draw(game.rect);
        window.draw(game.rect);
        window.display();
    }

    return 0;
}
