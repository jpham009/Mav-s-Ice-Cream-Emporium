#include "mainwin.h"



		double Mainwin::balance(){return _balance;}
		double Mainwin::money_in(){return _money_in;}
		double Mainwin::money_out(){return _money_out;}
		double Mainwin::profit(){_profit = _money_in-_money_out; return _profit;}

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

