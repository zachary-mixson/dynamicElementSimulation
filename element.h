#pragma once
#include <SFML/Graphics.hpp>
class Element
{
public:

	Element();

	int x, y;

	sf::RectangleShape element;

	sf::Color elementColor;

	int getSize();

	int getDensity();

	int getGravity();

	void setDensity(int density);

	void setGravity(int gravity);

private:

	int elementSize = 10;

	int elementDensity;

	int elementGravity;

};
