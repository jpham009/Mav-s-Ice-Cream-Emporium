#include "mainwin.h"



void Mainwin::fill_order(Mice::Order order){
	_money_in += order.total_price(); 
	_balance += order.total_price();  


	for(int i = 0; i < _container_selection.size(); i++){
		_emp->container(i).consume(); 
	}
	for(int i = 0; i < _scoop_selection.size(); i++){
		_emp->scoop(i).consume(); 
	}
	for(int i = 0; i < _topping_selection.size(); i++){
		_emp->topping(i).consume(); 
	}
	
//	std::string s = "";
//	for(Mice::Container container : _emp->containers()) s = s + "Item:" + container.name() + " Qty:" + std::to_string(container.quantity()) + "\n";
//	for(Mice::Scoop scoop : _emp->scoops()) s = s + "Item:" + scoop.name() + " Qty:" + std::to_string(scoop.quantity()) + "\n";
//	for(Mice::Topping topping : _emp->toppings()) s = s + "Item:" + topping.name() + " Qty:" + std::to_string(topping.quantity()) + "\n";
//	s = s + "Money in the bank: " + to_string_with_precision(_balance);
//	Gtk::MessageDialog mdialog(s);
//	mdialog.run(); 
//	mdialog.close(); 
	
}
