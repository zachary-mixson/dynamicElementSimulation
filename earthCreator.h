#pragma once
#include "elementCreator.h"
class EarthCreator :
    public ElementCreator
{

    Element* FactoryMethod() const override {
        return new EarthElement();
    }
};
