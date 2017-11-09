#include "person.h"
#include <iomanip>


Person::Person(std::string name, std::string phone, std::string id, double salary) : _name{name}, _phone{phone}, _id{id}, _salary{salary}{}

string Person::type(){
	return "Person";
}

void Person::toggle_active(){
	if(_active == true){
		_active = false;
	}
	else{
		_active = true;
	}
}

void Person::active(){
	if(_active == true){
		cout << "Active" << endl;
	}
	else{
		cout << "Inactive" << endl;
	}

}

std::string Person::name(){return _name;}
std::string Person::phone(){return _phone;}
std::string Person::id(){return _id;}
double Person::salary(){return _salary;}

void Person::set_name(string name){ _name = name;}
void Person::set_phone(string phone){ _phone = phone;}
void Person::set_salary(double salary){ _salary = salary;}

void Person::print(){
	std::cout.precision(2);
	std::cout << std::fixed;
	std::cout << "Name: " << _name << " | Phone: " << _phone << " | ID: " << _id << " | Role: " << type() << " | Salary: " << _salary << std::endl;

}




