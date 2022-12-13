#include "earthElement.h"

EarthElement::EarthElement() {

	elementColor = sf::Color((150, 75, 0));
	element.setFillColor(elementColor);

	setDensity(3);
	setGravity(0);
};
