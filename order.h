#ifndef _ORDER_H
#define _ORDER_H

#include "serving.h"
#include <string>
#include <iostream>
#include <vector>


namespace Mice{

class Order {

	public:
	Order(int num_of_servings);
	void total();
	void add_serving(Serving serving); 
	void to_string();
	std::vector<Serving> servings(); 
	int order_number(); 
	double total_price();
	std::string total_price_string();
	void fill();
	bool state();
	int get_order_number();
	bool get_paid();
	bool paid();
	std::string get_order_string(); 
	std::string _order_string;
	void set_order_number(int i);
	void cancel();
	bool cancelled();
	

	private:
	std::vector<Serving> _servings;	
	int _num_of_servings; 
	double _total_price{0};
	bool _state{false}; 
	bool _paid{false};
	int _order_number;
	bool _cancelled{false};

};

}


#endif //_ORDER_H
