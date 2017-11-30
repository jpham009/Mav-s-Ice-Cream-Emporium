#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include <iostream> 
#include <string>
#include <vector>
#include "person.h"
#include <fstream>

namespace Mice{

class Customer : public Person {
	public:
	Customer(std::string name, std::string id, std::string phone);
    Customer(std::istream& ist);
    void save(std::ostream& ost);
	std::string type() override;

	private:
	int access = 3; //user access

};

}
#endif //_CUSTOMER_H
