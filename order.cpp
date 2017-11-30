#include "order.h"
#include <iostream>
#include <sstream>
#include <iomanip>
namespace Mice{

template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 2)
{
    std::ostringstream out;
    out << std::fixed << std::setprecision(n) << a_value;
    return out.str();
}


Order::Order(int num_of_servings) : _num_of_servings{num_of_servings}{}

void Order::add_serving(Serving serving){
	_servings.push_back(serving);
}

std::vector<Serving> Order::servings() {return _servings;}
double Order::total_price(){ return _total_price;}
std::string Order::total_price_string(){return to_string_with_precision(_total_price);}
void Order::total(){ 
	for(int i = 0; i < _servings.size(); i++){
		_total_price += _servings[i].container().price();
	for (Scoop scoop : _servings[i].scoops()) _total_price += scoop.price();
	for (Topping topping : _servings[i].toppings()) _total_price += topping.price();
	}
	return;
}

void Order::fill(){ //state change
	_state = true; 
}

bool Order::state(){
	return _state;
}

bool Order::get_paid(){
	return _paid;
}

bool Order::paid(){
	_paid = true;
}


void Order::to_string(){
	_order_string = "";
	std::string s = "\n";
	
	for(int i = 0; i < _servings.size(); i++){
		double serving_price = 0;
		s += "[Serving #" + std::to_string(i+1) +"]";
		s = s + "\n   CONTAINER: " + _servings[i].container().name() + "\t$" + to_string_with_precision(_servings[i].container().price()) + "\n"; 
		serving_price += _servings[i].container().price();
	
		for (Scoop scoop : _servings[i].scoops()) {
			s += "   SCOOP: " + scoop.name() + "\t$" + to_string_with_precision(scoop.price()) + "\n"; 
		serving_price += scoop.price();
		}
	
		for (Topping topping : _servings[i].toppings()){
			 s += "   TOPPING: " + topping.name() + "\t$" + to_string_with_precision(topping.price()) + "\n"; 
		serving_price += topping.price(); 	
		}
		
		//s += "\tServing price: $" + to_string_with_precision(serving_price) + "\n\n";
	}

		Order::total();
		s+= "\nYour total is: " + total_price_string() + "\n\n"; 

	_order_string = s; 
	return;
}


std::string Order::get_order_string(){
	return _order_string;	
}

void Order::cancel(){
	_cancelled = true;
}
bool Order::cancelled(){
	return _cancelled;
}

int Order::order_number(){
	return _order_number++; //increase counter
}
int Order::get_order_number(){
	return _order_number;
}

void Order::set_order_number(int i){
	_order_number = i;
}




} //end of namespace


//std::ostream& operator<<(std::ostream& os, const Mice::Order& order) {
// 	for (Mice::Serving s : order.servings()) os << std::endl << s;
//    return os;
//}



