#include "elementCreator.h"
class SandCreator :
    public ElementCreator
{

    Element* FactoryMethod() const override {
        return new SandElement();
    }
};