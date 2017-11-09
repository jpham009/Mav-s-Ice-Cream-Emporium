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

std::vector<Serving> Order::servings() const {return _servings;}

std::string Order::total(){
	for(int i = 0; i < _servings.size(); i++){
		_total_price += _servings[i].container().price();
	for (Scoop scoop : _servings[i].scoops()) _total_price += scoop.price();
	for (Topping topping : _servings[i].toppings()) _total_price += topping.price();
	}
	return to_string_with_precision(_total_price);
}

std::string Order::to_string(){
	std::string s = "\n";
	for(int i = 0; i < _servings.size(); i++){
		s += "Serving #" + std::to_string(i) + "\n";
		s = s + "\nContainer: \n" + "\t" + _servings[i].container().name() + "\t$" + to_string_with_precision(_servings[i].container().price()) + "\n"; 
		s += "Scoops: \n";
		for (Scoop scoop : _servings[i].scoops()) s = s + "\t"+ scoop.name() + "\t$" + to_string_with_precision(scoop.price()) + "\n"; 
		s += "Toppings: \n";
		for (Topping topping : _servings[i].toppings()) s = s + "\t" + topping.name() + "\t$" + to_string_with_precision(topping.price()) + "\n"; 
	}

		s+= "\n\nYour total is: " + to_string_with_precision(total()) + "\n\n"; 

	return s;
}

int Order::order_number(){
	return _order_number++;
}




} //end of namespace


//std::ostream& operator<<(std::ostream& os, const Mice::Order& order) {
// 	for (Mice::Serving s : order.servings()) os << std::endl << s;
//    return os;
//}



