#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include <iostream> 
#include <string>
#include <vector>
#include "person.h"

using namespace std;


class Customer : public Person {
	public:
	Customer(std::string name, std::string phone, std::string id);
	string type() override;
	
	private:


	int access = 3; //user access

};

#endif //_CUSTOMER_H
