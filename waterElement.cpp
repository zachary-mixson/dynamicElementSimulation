#include "waterElement.h"

WaterElement::WaterElement()
{
	elementColor = sf::Color::Blue;

	element.setFillColor(elementColor);
	setDensity(1);
	setGravity(3);

}
