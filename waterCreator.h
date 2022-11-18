#include "elementCreator.h"
class WaterCreator :
    public ElementCreator
{

    Element* FactoryMethod() const override {
        return new WaterElement();
    }
};