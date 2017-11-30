#include "mainwin.h"



std::string Mainwin::containers_to_string(){
	std::string containers_string = "";
	for(int i = 0; i < _emp->num_containers(); i++){
		containers_string += _emp->container(i).name() + "\n";
	}
	return containers_string;
}

std::string Mainwin::scoops_to_string(){
	std::string scoops_string = "";
	for(int i = 0; i < _emp->num_scoops(); i++){
		scoops_string += _emp->scoop(i).name() + "\n";
	}
	return scoops_string;
}

std::string Mainwin::toppings_to_string(){
	std::string toppings_string = "";
	for(int i = 0; i < _emp->num_toppings(); i++){
		toppings_string += _emp->topping(i).name() + "\n";
	}
	return toppings_string;
} 

std::string Mainwin::customers_to_string(){
	std::string customers_string = "";
	for(int i = 0; i < _emp->num_customers(); i++){
		customers_string += _emp->customer(i).name() + "\n";
	}
	return customers_string;
} 

std::string Mainwin::servers_to_string(){
	std::string servers_string = "";
	for(int i = 0; i < _emp->num_servers(); i++){
		servers_string += _emp->server(i).name() + "\n";
	}
	return servers_string;
} 
std::string Mainwin::managers_to_string(){
	std::string managers_string = "";
	for(int i = 0; i < _emp->num_managers(); i++){
		managers_string += _emp->manager(i).name() + "\n";
	}
	return managers_string;
} 




