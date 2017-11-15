#ifndef _ORDER_H
#define _ORDER_H

#include "serving.h"
#include <string>
#include <iostream>
#include <vector>
static int _order_number = 1; 


namespace Mice{

class Order {

	public:
	Order(int num_of_servings);
	//void print_order();
	void total();
	void add_serving(Serving serving); 
	std::string to_string();
	///////////////TODO///////////////
	std::vector<Serving> servings(); 
	int order_number(); 
	double total_price();
	std::string total_price_string();
	void fill();
	bool state();
	
	
	
	///////////////TODO///////////////
	private:
	std::vector<Serving> _servings;	
	int _num_of_servings; 
	double _total_price{0};
	bool _state = false; //true = filled & false = unfilled 

};

}

/*std::ostream& operator<<(std::ostream& os, const Mice::Order& order);*/
#endif //_ORDER_H
