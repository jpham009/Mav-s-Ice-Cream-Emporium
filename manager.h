#ifndef _MANAGER_H
#define _MANAGER_H
#include <string>
#include <iostream>
#include <vector>
#include "customer.h"
#include "person.h"
#include "server.h"
#include "container.h"
#include "topping.h"
#include "scoop.h"
#include "serving.h"


using namespace std;

class Manager : public Person {
	public:
	Manager(std::string name, std::string phone, std::string id, double salary);
	string type() override;

	//set
	void set_salary(double);

	//get
	double get_salary();
	int get_orders();
	void get_customer(); //need to ADD 
	void order_filled();

///////////TODO/////////////////

	void print_customer();

	void add_container();
	void add_scoop();
	void add_topping();
	
////////////////////////////	
	private:
	int access = 1; //admin access
	double salary;
	int orders = 0;

	//total earnings
////////////////////////////
	vector<Customer> customerData;
////////////////////////////


};
#endif //_MANAGER_H

