#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>

Mice::Order Mainwin::create_order() {
//	Gtk::Dialog temp;
//temp.set_default_size(200,200);
//	Gtk::VBox b_temp;
//	Gtk::Spinner spinner;

	
//	b_temp.pack_start(spinner, Gtk::PACK_SHRINK);
//	temp.get_vbox()->set_center_widget(spinner);
//	spinner.start(); 
//	temp.set_transient_for(*this);
//	temp.show_all();
//	temp.run();
///////////////////
//	spinner.stop();
//	temp.hide();

//


		Gtk::Dialog dialog;
		dialog.set_title("Create order");
			dialog.set_border_width(15); //borders
		// Name 
		Gtk::VBox b_name;
		
	
		Gtk::Label l_name{"How many servings would you like to order?\n"};
		b_name.pack_start(l_name, Gtk::PACK_SHRINK);
		dialog.get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

		Gtk::VBox spin_box;

		Gtk::SpinButton spin;
		spin.set_range(1,10);
		spin.set_value(1);
		spin.set_increments(1,1);
		spin.set_alignment(Gtk::ALIGN_CENTER);
		
		//orders_spin.set_range(1, 10, 1);
		spin_box.pack_start(spin, Gtk::PACK_SHRINK);
		spin_box.set_halign(Gtk::ALIGN_CENTER);
		spin_box.set_margin_bottom(30);
		dialog.get_vbox()->pack_start(spin_box);


		// Show dialog
		dialog.add_button("Cancel", 0);
		dialog.add_button("OK", 1);
		dialog.set_transient_for(*this);
		dialog.show_all();
		dialog.run();
		//int num_of_servings = std::stoi(e_name.get_text());
		int num_of_servings = (int)spin.get_value();		
		dialog.hide();
		
	
		//int num_of_servings = result; //TODO//Enter number of serving(ENTRY)
		if (num_of_servings == -1 || num_of_servings > 10) throw std::runtime_error("Canceled");

		Mice::Order order{num_of_servings};
		
	//vector of servings 
		for(int i = 0; i < num_of_servings; i++){
			order.add_serving(Mainwin::create_serving());
		}



	////////////////////////////////////////////////////////////
		Gtk::Dialog dialog2;
		dialog2.set_title("Confirm");
		dialog2.set_border_width(15);
		
		// 
		Gtk::VBox b_confirm;
		b_confirm.set_border_width(15);
		b_confirm.set_margin_left(20);
		b_confirm.set_margin_right(20);
		b_confirm.set_margin_bottom(15);
		Gtk::Label l_confirm{"Is your order correct?\n"};
		b_confirm.pack_start(l_confirm, Gtk::PACK_SHRINK);
		//dialog2.get_vbox()->pack_start(b_checkout, Gtk::PACK_SHRINK);
		
		//
		Gtk::Label l_order{order.to_string()};
		b_confirm.pack_start(l_order, Gtk::PACK_SHRINK);
		dialog2.get_vbox()->pack_start(b_confirm, Gtk::PACK_SHRINK);

	
		// Show dialog
		dialog2.add_button("No", 0);
		dialog2.add_button("Yes", 1);
		dialog2.set_transient_for(*this);
		dialog2.show_all();
		dialog2.run();
		
		dialog2.hide();
/////////////////////////////////////////////////////////////////
Gtk::Dialog dialog3;
		dialog3.set_title("Checkout");
		dialog3.set_border_width(15);
		// 
		Gtk::VBox b_checkout;
	

		b_checkout.set_border_width(25);
		b_checkout.set_margin_bottom(15);
		std::string total_string = "Your total is $" + order.total();
		Gtk::Label l_checkout{total_string};
		b_checkout.pack_start(l_checkout);
		//dialog2.get_vbox()->pack_start(b_checkout, Gtk::PACK_SHRINK);
		
		//
		b_checkout.pack_start(l_checkout);
		dialog3.get_vbox()->pack_start(b_checkout);

	
		// Show dialog
		dialog3.add_button("Cancel", 0);
		dialog3.add_button("Pay", 1);
		dialog3.set_transient_for(*this);
		dialog3.show_all();
		dialog3.run();
		
		dialog3.hide();
///////////////////////////////////////////////////////////////////
Gtk::Dialog dialog4;
		dialog4.set_title("Payment Approved");
		dialog4.set_border_width(15);
		
		// 
		Gtk::VBox b_payment;

		b_payment.set_border_width(30);
		b_payment.set_margin_bottom(15);
		std::string thankyou_string = "Thank you for your purchase!\n\n You are order number #" + std::to_string(order.order_number());
		Gtk::Label l_payment{thankyou_string};
		b_payment.pack_start(l_payment);
		//dialog2.get_vbox()->pack_start(b_checkout, Gtk::PACK_SHRINK);
		
		//
		b_payment.pack_start(l_payment);
		dialog4.get_vbox()->pack_start(b_payment);
		dialog4.add_button("Ok", 1);

	
		// Show dialog
		dialog4.set_transient_for(*this);
		dialog4.show_all();
		dialog4.run();
		
		dialog4.hide();
		

		 

		return order; 

}
