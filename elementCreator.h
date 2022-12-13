#pragma once
#include <SFML/Graphics.hpp>
#include "element.h"
#include "waterElement.h"
#include "sandElement.h"
#include "earthElement.h"
class ElementCreator
{
public:

	virtual ~ElementCreator() {};
	virtual Element* FactoryMethod() const = 0;

private:



};
