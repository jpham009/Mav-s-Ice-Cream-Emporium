#include "serving.h"

namespace Mice {

Serving::Serving(Container container) : _container{container} { }
Container Serving::container() {return _container;}

void Serving::add_scoop(Scoop scoop) {_scoops.push_back(scoop);}
void Serving::add_topping(Topping topping) {_toppings.push_back(topping);}
std::vector<Scoop> Serving::scoops() {return _scoops;}
std::vector<Topping> Serving::toppings() {return _toppings;}

double Serving::cost() {
    double total = _container.cost();
    for (Scoop scoop : _scoops) total += scoop.cost();
    for (Topping topping : _toppings) total += topping.cost();
    return total;
}

double Serving::price() {
    double total = _container.price();
    for (Scoop scoop : _scoops) total += scoop.price();
    for (Topping topping : _toppings) total += topping.price();
    return total;
}

}
