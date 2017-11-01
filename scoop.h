#ifndef _SCOOP_H
#define _SCOOP_H

#include "item.h"

namespace Mice {

class Scoop : public Item {
  public:
    Scoop(std::string name, std::string description, double cost, double price);
    std::string type() const override;
};

}
#endif
