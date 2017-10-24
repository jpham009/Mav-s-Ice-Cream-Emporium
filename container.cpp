#include "container.h"

Container::Container(std::string name, std::string description, double cost, double price,
              int max_scoops)
          : Item(name, description, cost, price), _max_scoops{max_scoops} { }
int Container::max_scoops() {_max_scoops;}
