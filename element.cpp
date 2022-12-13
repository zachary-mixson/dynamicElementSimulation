#include "element.h"

Element::Element()
{
	element.setSize(sf::Vector2f(elementSize, elementSize));
	element.setFillColor(elementColor);

}

int Element::getSize()
{
	return elementSize;
}

int Element::getDensity()
{
	return elementDensity;
}

int Element::getGravity()
{
	return elementGravity;
}

void Element::setDensity(int density) {

	elementDensity = density;

};

void Element::setGravity(int gravity) {

	elementGravity = gravity;

};
