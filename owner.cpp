#include "owner.h"

namespace Mice{

Owner::Owner(std::string name,  std::string id, std::string phone) : Person(name, id, phone){}

std::string Owner::type(){ return "Head Honcho";}

}
