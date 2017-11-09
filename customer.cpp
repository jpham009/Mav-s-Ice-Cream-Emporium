#include "customer.h"

namespace Mice{

static int customer_id = 10000;

Customer::Customer(std::string name, std::string phone, std::string id) : Person(name, phone, id, 0) {}

string Customer::type(){
	return "Customer";
}

}
