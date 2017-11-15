#include "mainwin.h"



std::string Mainwin::containers_to_string(){
	std::string containers_string = "";
	for(int i = 0; i < Mainwin::_containers.size(); i++){
		containers_string += Mainwin::_containers[i].name() + "\n";
	}
	return containers_string;
}

std::string Mainwin::scoops_to_string(){
	std::string scoops_string = "";
	for(int i = 0; i < Mainwin::_scoops.size(); i++){
		scoops_string += Mainwin::_scoops[i].name() + "\n";
	}
	return scoops_string;
}

std::string Mainwin::toppings_to_string(){
	std::string toppings_string = "";
	for(int i = 0; i < Mainwin::_toppings.size(); i++){
		toppings_string += Mainwin::_toppings[i].name() + "\n";
	}
	return toppings_string;
} 

std::string Mainwin::customers_to_string(){
	std::string customers_string = "";
	for(int i = 0; i < Mainwin::_customers.size(); i++){
		customers_string += Mainwin::_customers[i].name() + "\n";
	}
	return customers_string;
} 

std::string Mainwin::servers_to_string(){
	std::string servers_string = "";
	for(int i = 0; i < Mainwin::_servers.size(); i++){
		servers_string += Mainwin::_servers[i].name() + "\n";
	}
	return servers_string;
} 
std::string Mainwin::managers_to_string(){
	std::string managers_string = "";
	for(int i = 0; i < Mainwin::_managers.size(); i++){
		managers_string += Mainwin::_managers[i].name() + "\n";
	}
	return managers_string;
} 




