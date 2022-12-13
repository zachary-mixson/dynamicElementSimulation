#include <SFML/Graphics.hpp>
#include <iostream>
#include "elementCreator.h"
#include "waterCreator.h"
#include "earthCreator.h"
#include <windows.h> 
#include <cstdlib>





int main()
{
    const int WINDOW_WIDTH = 1000;
    const int WINDOW_HEIGHT = 1000;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Dynamic Element Simulation");


    std::vector<Element> waterVector;
    std::vector<Element> earthVector;

    ElementCreator* waterCreator = new WaterCreator();
    ElementCreator* earthCreator = new EarthCreator();



    const int mapArraySizeY = WINDOW_HEIGHT / 10;
    const int mapArraySizeX = WINDOW_WIDTH / 10;

    char collisionArray[mapArraySizeX][mapArraySizeY];

    for (int y = 0; y <= mapArraySizeY - 1; y++) {
        for (int x = 0; x <= mapArraySizeX - 1; x++) {
            collisionArray[x][y] = ' ';
        }
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2f mouseScreenPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

            Element water = *waterCreator->FactoryMethod();
            water.element.setOutlineColor(sf::Color::White);
            water.element.setOutlineThickness(1);
            water.x = mouseScreenPosition.x / 10;
            water.y = mouseScreenPosition.y / 10;

            collisionArray[water.x][water.y] = 'w';

            waterVector.push_back(water);

        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            sf::Vector2f mouseScreenPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

            Element earth = *earthCreator->FactoryMethod();

            earth.element.setOutlineColor(sf::Color::White);
            earth.element.setOutlineThickness(1);

            earth.x = mouseScreenPosition.x / 10;
            earth.y = mouseScreenPosition.y / 10;

            collisionArray[earth.x][earth.y] = 'e';
            earth.element.setPosition(sf::Vector2f(earth.x * earth.element.getSize().x, earth.y * earth.element.getSize().y));

            earthVector.push_back(earth);

        }


        // UPDATE WATER MOVEMENT

        for (auto& waterElement : waterVector) {

            if (waterElement.y <= 99 && collisionArray[waterElement.x][waterElement.y + 1] == ' ') {

                collisionArray[waterElement.x][waterElement.y] = ' ';

                waterElement.y += 1;

                collisionArray[waterElement.x][waterElement.y] = 'w';
                waterElement.element.setPosition(sf::Vector2f(waterElement.x * waterElement.element.getSize().x, waterElement.y * waterElement.element.getSize().y));



            }
            else if (waterElement.y <= 99 && collisionArray[waterElement.x + 1][waterElement.y] == ' ') {

                collisionArray[waterElement.x][waterElement.y] = ' ';

                waterElement.x += 1;

                collisionArray[waterElement.x][waterElement.y] = 'w';
                waterElement.element.setPosition(sf::Vector2f(waterElement.x * waterElement.element.getSize().x, waterElement.y * waterElement.element.getSize().y));


            }
            else if (waterElement.y <= 99 && collisionArray[waterElement.x - 1][waterElement.y] == ' ') {

                collisionArray[waterElement.x][waterElement.y] = ' ';

                waterElement.x -= 1;

                collisionArray[waterElement.x][waterElement.y] = 'w';
                waterElement.element.setPosition(sf::Vector2f(waterElement.x * waterElement.element.getSize().x, waterElement.y * waterElement.element.getSize().y));

            }


        }

        // DRAW ELEMENTS TO WINDOW

        window.clear(sf::Color::Black);

        for (auto& waterElement : waterVector) {

            window.draw(waterElement.element);
        }

        for (auto& earthElement : earthVector) {

            window.draw(earthElement.element);


        }


        Sleep(.5);
        window.display();

    }



    return 0;
}

