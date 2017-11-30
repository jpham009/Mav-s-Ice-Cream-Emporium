#include "mainwin.h"

void Mainwin::easter_egg(){
	_emp->add_customer(Mice::Customer{"Cheryl Dyer", "8178902356", std::to_string(customer_id++)});
	_emp->add_customer(Mice::Customer{"Daniel Fagan", "8178809444", std::to_string(customer_id++)});
	_emp->add_customer(Mice::Customer{"Michael Fagan", "8178912365", std::to_string(customer_id++)});
	_emp->add_server(Mice::Server{"Michelle Pham", "6825590111", std::to_string(employee_id++), 12.50});
	_emp->add_server(Mice::Server{"Russell Pham", "6824914447", std::to_string(employee_id++), 11.50});
	_emp->add_server(Mice::Server{"Connor Pham", "6825932036", std::to_string(employee_id++), 11.75});
	_emp->add_manager(Mice::Manager{"Johnny Pham", "6825590692", std::to_string(employee_id++), 19.50});		
	_emp->add_manager(Mice::Manager{"MANAGER1325", "Manager", "Manager", 1.00});
	_emp->add_server(Mice::Server{"SERVER1325", "Server", "Server", 1.00});
	_emp->add_customer(Mice::Customer{"CUSTOMER", "Customer", "Customer"});
	return;
}
