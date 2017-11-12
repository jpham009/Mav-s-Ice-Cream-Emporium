#include "manager.h"

namespace Mice{

static int employee_id = 10000;

Manager::Manager(std::string name, std::string phone, std::string id, double salary) : Person(name, phone, id, salary){}

string Manager::type(){
	return "Manager";
}

/// EMPLOYEE SET FUNCTIONS
void Manager::set_salary(double newSalary){salary = newSalary;}

void Manager::order_filled(){++orders;}

//// EMPLOYEE GET FUNCTIONS
int Manager::get_orders(){ return orders;}


void Manager::print_customer(){
	for(int i = 0; i < customerData.size(); i++){
	   //modify only active customer?
	   cout << "Name: " << customerData[i].name() << " , Phone: " << customerData[i].phone() << endl;
	}
}

void Manager::order_up(){
	++orders;
}

//// CUSTOMER Get FUNCTIONS
////TODO///////////

//ADD ITEM CONTAINER,SCOOP,TOPPING

}



