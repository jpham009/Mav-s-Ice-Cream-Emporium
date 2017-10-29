#ifndef _SERVING_H
#define _SERVING_H

#include "container.h"
#include "scoop.h"
#include "topping.h"
#include <vector>

class Serving {
  public:
    Serving(Container container);
    Container container();
    std::vector<Scoop> scoops();
    std::vector<Topping> toppings();
    double cost();
    double price();
  private:
    Container _container;
    std::vector<Scoop> _scoops;
    std::vector<Topping> _toppings;
};

#endif
