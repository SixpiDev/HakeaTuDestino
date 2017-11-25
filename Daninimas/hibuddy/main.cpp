#include <SFML/Graphics.hpp>

#define kVel 8

int main()
{

    sf::RenderWindow window(sf::VideoMode(1000, 600), "hibuddyAPP");

    sf::Texture tMap;
    if (!tMap.loadFromFile("assets/mapa.png"))
    {
        // error...
    }
    sf::Sprite sMap;
    tMap.setSmooth(true);
    sMap.setTexture(tMap);
    sMap.setOrigin(1357/2,628/2);
    sMap.setPosition(315, 395);

    sf::Texture tMira;
    if (!tMira.loadFromFile("assets/mira.png"))
    {
        // error...
    }
    sf::Sprite sMira;
    tMira.setSmooth(true);
    sMira.setTexture(tMira);
    sMira.setOrigin(9/2,9/2);
    sMira.setPosition(315, 395);

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
                sMap.move(kVel,0);
                sMap.setOrigin((sMap.getOrigin().x)-kVel, sMap.getOrigin().y);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                // move right...
                sMap.move(-kVel,0);
                sMap.setOrigin((sMap.getOrigin().x)+kVel, sMap.getOrigin().y);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                // move up...
                sMap.move(0,kVel);
                sMap.setOrigin((sMap.getOrigin().x), (sMap.getOrigin().y)-kVel);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                // move left...
                sMap.move(0,-kVel);
                sMap.setOrigin((sMap.getOrigin().x), (sMap.getOrigin().y)+kVel);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Add)){
                //zoom in
                sMap.scale(1.08f, 1.08f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract)){
                //zoom out
                sMap.scale(0.92f, 0.92f);
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sMap);
        window.draw(sHud);
        window.draw(sMira);
        window.display();
    }

    return 0;
}
