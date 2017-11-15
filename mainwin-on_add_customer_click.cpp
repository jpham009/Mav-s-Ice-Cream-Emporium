#include "mainwin.h"

void Mainwin::on_add_customer_click() {


    Gtk::Dialog dialog{"Add Customer", *this};
	dialog.set_border_width(15); //borders
	dialog.set_transient_for(*this);
    const int WIDTH = 15;

   
 	    // Name 
    Gtk::HBox b_custname;
    Gtk::Label l_custname{"Name:"};
    l_custname.set_width_chars(WIDTH);
    b_custname.pack_start(l_custname, Gtk::PACK_SHRINK);

    Gtk::Entry e_custname;
    e_custname.set_max_length(WIDTH*4);
    b_custname.pack_start(e_custname, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_custname, Gtk::PACK_SHRINK);


    // Phone
    Gtk::HBox b_custphone;
	b_custphone.set_margin_bottom(15);

    Gtk::Label l_custphone{"Phone:"};
    l_custphone.set_width_chars(WIDTH);
    b_custphone.pack_start(l_custphone, Gtk::PACK_SHRINK);

    Gtk::Entry e_custphone;
    e_custphone.set_max_length(WIDTH*4);
    b_custphone.pack_start(e_custphone, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_custphone, Gtk::PACK_SHRINK);

    // Show dialog
    dialog.add_button("Cancel", 0);
    dialog.add_button("OK", 1);
    dialog.show_all();

	int result = dialog.run();
	if(result == 1){ 
		// Instance item
		Mice::Customer new_customer(e_custname.get_text(), e_custphone.get_text(), std::to_string(customer_id));
		_customers.push_back(new_customer);
		Gtk::MessageDialog mdialog(e_custname.get_text() + "\nCustomer ID: #" + std::to_string(customer_id) + "\nhas been added!");
		mdialog.set_transient_for(*this);
		customer_id++; 
		dialog.hide();
		mdialog.run();  
	}
	else{
		Gtk::MessageDialog mdialog("Your request has been cancelled!"); 
		mdialog.set_transient_for(*this);
		dialog.hide();
		mdialog.run();  
	}
 		dialog.close();
}
