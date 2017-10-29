#ifndef _CONTAINER_H
#define _CONTAINER_H

#include "item.h"

class Container : public Item {
  public:
    Container(std::string name, std::string description, double cost, double price,
              int max_scoops);
    std::string type() override;
    int max_scoops();
  private:
    int _max_scoops;
};
#endif
