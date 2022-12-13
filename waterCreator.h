#include "elementCreator.h"
class WaterCreator : public ElementCreator
{
public:
    Element* FactoryMethod() const override {
        return new WaterElement();
    }

private:


};
