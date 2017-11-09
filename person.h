#ifndef _PERSON_H
#define _PERSON_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

//ERRRONE is going to be deriving from this class!!!

class Person{
	public:
	Person(std::string name, std::string phone, std::string id, double salary);
	void toggle_active();
	void active();
	std::string name();
	std::string phone();
	std::string id();
	double salary();
	void print();
	virtual string type();
	//Place and order for ice cream 
	
	void set_name(string name);
	void set_phone(string phone);
	void set_salary(double salary);
	
	private:
	std::string _name{"N/A"};
	std::string _phone{"N/A"};
	std::string _id{"N/A"};
	double _salary{0};
	bool _active = true;

};



#endif //_PERSON_H

