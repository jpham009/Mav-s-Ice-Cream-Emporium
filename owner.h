#ifndef _OWNER_H
#define _OWNER_H
#include <string>
#include <iostream>
#include <vector>
#include "person.h"

using namespace std;

class Owner : public Person{
	public: 
	Owner(std::string name, std::string phone, std::string id, double salary);
	string type() override;

	private:
	int access = 0;	

};



#endif //_OWNER_H
