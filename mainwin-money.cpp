#include "mainwin.h"



		double Mainwin::balance(){return _balance;}
		double Mainwin::money_in(){return _money_in;}
		double Mainwin::money_out(){return _money_out;}
		double Mainwin::profit(){return _profit;}

void Mainwin::on_money_click(){
	std::string s = "Money:\n\nBalance: " + to_string_with_precision(balance()) + "\nMoney in: " + to_string_with_precision(money_in()) + "\nMoney out: " + 	to_string_with_precision(money_out()) + "\nProfit: " + to_string_with_precision(profit()) + "\n";
	
	Gtk::Dialog dialog;	
	dialog.set_size_request(350,300);
    dialog.set_transient_for(*this);
	//dialog.set_default_size(300, 400);
	dialog.set_title("Money");
	   
 	// money 
    Gtk::VBox b_money;

    Gtk::Label l_money{s};
	l_money.set_valign(Gtk::ALIGN_CENTER);
	l_money.set_halign(Gtk::ALIGN_CENTER);
	//l_money.set_margin_bottom(30);
	//l_money.set_margin_top(30);
	l_money.set_padding(30,30);
    b_money.pack_start(l_money);
	dialog.get_vbox()->pack_start(b_money);
	dialog.add_button("Ok", 1);

	dialog.show_all();
	dialog.run(); 
	dialog.close(); 

}

// Server expenses
// Supply expenses
// 


void Mainwin::easter_egg(){
	_customers.push_back(Mice::Customer{"Cheryl Dyer", "8178902356", std::to_string(customer_id++)});
	_customers.push_back(Mice::Customer{"Daniel Fagan", "8178809444", std::to_string(customer_id++)});
	_customers.push_back(Mice::Customer{"Michael Fagan", "8178912365", std::to_string(customer_id++)});
	_servers.push_back(Mice::Server{"Michelle Pham", "6825590111", std::to_string(employee_id++), 12.50});
	_servers.push_back(Mice::Server{"Russell Pham", "6824914447", std::to_string(employee_id++), 11.50});
	_servers.push_back(Mice::Server{"Connor Pham", "6825932036", std::to_string(employee_id++), 11.75});
	_managers.push_back(Mice::Manager{"Johnny Pham", "6825590692", std::to_string(employee_id++), 19.50});	
}

