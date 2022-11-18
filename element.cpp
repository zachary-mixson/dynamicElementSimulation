#include "element.h"

Element::Element()
{

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