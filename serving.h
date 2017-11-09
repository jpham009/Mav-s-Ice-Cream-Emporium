#ifndef _SERVING_H
#define _SERVING_H

#include "container.h"
#include "scoop.h"
#include "topping.h"
#include <vector>

namespace Mice {

class Serving {
  public:
    Serving(Container container);
    void add_scoop(Scoop scoop);
    void add_topping(Topping topping);
    Container container() const;
    std::vector<Scoop> scoops() const;
    std::vector<Topping> toppings() const;
    double cost() const;
    double price() const;
	Scoop scoop(int i);
	Topping topping(int i);
  private:
    Container _container;
    std::vector<Scoop> _scoops;
    std::vector<Topping> _toppings;
};

}

std::ostream& operator<<(std::ostream& os, const Mice::Serving& serving);

#endif
