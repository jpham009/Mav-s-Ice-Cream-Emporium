#include "owner.h"

Owner::Owner(std::string name, std::string phone, std::string id, double salary) : Person(name, phone, id, salary){ }

string Owner::type(){
	return "Head Honcho";
}
