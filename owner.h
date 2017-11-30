#ifndef _OWNER_H
#define _OWNER_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "person.h"

namespace Mice{

class Owner : public Person{
	public: 
	Owner(std::string name, std::string id, std::string phone);
	std::string type() override;

	private:
	int access = 0;	

};

}


#endif //_OWNER_H
