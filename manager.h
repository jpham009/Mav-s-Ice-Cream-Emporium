#ifndef _MANAGER_H
#define _MANAGER_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "customer.h"
#include "person.h"
#include "server.h"
#include "container.h"
#include "topping.h"
#include "scoop.h"
#include "serving.h"


using namespace std;

namespace Mice{

class Manager : public Person {
	public:
	Manager(std::string name, std::string id, std::string phone,  double salary);
	Manager(std::istream& ist);
       void save(std::ostream& ost);
	string type() override;

	//set
	void set_salary(double);

	void order_up();
	//get
	double get_salary();
	int get_orders();
	void get_customer(); //need to ADD 
	void order_filled();
	int _num_orders;
	double pay_manager();
	int num_orders(); 
	int salary();


///////////TODO/////////////////

	void print_customer();

	void add_container();
	void add_scoop();
	void add_topping();
	
////////////////////////////	
	private:
	int access = 1; //admin access
	double _salary{0};

	//total earnings


};

}
#endif //_MANAGER_H

