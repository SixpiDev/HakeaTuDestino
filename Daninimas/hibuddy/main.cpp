#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "hibuddyAPP");

    sf::Texture tMap;
    if (!tMap.loadFromFile("assets/mapa.png"))
    {
        // error...
    }
    sf::Sprite sMap;
    sMap.setTexture(tMap);

    sf::Texture tHud;
    if (!tHud.loadFromFile("assets/hud.png"))
    {
        // error...
    }
    sf::Sprite sHud;
    sHud.setTexture(tHud);


    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                // move left...
                sMap.move(-8,0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                // move right...
                sMap.move(8,0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                // move up...
                sMap.move(0,8);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                // move left...
                sMap.move(0,-8);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::)){
                sf::
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sMap);
        window.draw(sHud);
        window.display();
    }

    return 0;
}
