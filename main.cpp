#include <SFML/Graphics.hpp>
#include <iostream>
#include "elementCreator.h"

int main()
{
    int WINDOW_WIDTH = 1000;
    int WINDOW_HEIGHT = 1000;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "2D platformer");

    

    //ElementCreator* element = waterCreator();
    WaterElement water = WaterElement();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();


        }
   //window.clear();
    

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

            window.draw(water)
        }

   //window.draw(player);

    

    window.display();

    }
    


    return 0;
}



