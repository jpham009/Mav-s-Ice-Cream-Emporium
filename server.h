#ifndef _SERVER_H
#define _SERVER_H
#include <string>
#include <iostream>
#include <vector>
#include "person.h"

using namespace std;


class Server : public Person {
	public:
	Server(string name, string phone, string id, double salary); 
	string type() override;
	
	private:
	int access = 2; //user access

};



#endif //_SERVER_H
