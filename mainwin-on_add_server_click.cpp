#include "mainwin.h"

void Mainwin::on_add_server_click() {


    Gtk::Dialog dialog{"Add Server", *this};
    dialog.set_transient_for(*this);
    const int WIDTH = 15;

   
 	    // Name 
    Gtk::HBox b_name;

    Gtk::Label l_name{"Name:"};
    l_name.set_width_chars(WIDTH);
    b_name.pack_start(l_name, Gtk::PACK_SHRINK);

    Gtk::Entry e_name;
    e_name.set_max_length(WIDTH*4);
    b_name.pack_start(e_name, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);


    // Phone
    Gtk::HBox b_phone;

    Gtk::Label l_phone{"Phone:"};
    l_phone.set_width_chars(WIDTH);
    b_phone.pack_start(l_phone, Gtk::PACK_SHRINK);

    Gtk::Entry e_phone;
    e_phone.set_max_length(WIDTH*4);
    b_phone.pack_start(e_phone, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_phone, Gtk::PACK_SHRINK);

    // Salary
    Gtk::HBox b_salary;

    Gtk::Label l_salary{"Salary:"};
    l_salary.set_width_chars(WIDTH);
    b_salary.pack_start(l_salary, Gtk::PACK_SHRINK);

    Gtk::Entry e_salary;
    e_salary.set_max_length(WIDTH*4);
    b_salary.pack_start(e_salary, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_salary, Gtk::PACK_SHRINK);


    // Show dialog
    dialog.add_button("Cancel", 0);
    dialog.add_button("OK", 1);
    dialog.show_all();

    bool valid_data = false;
    double d_salary;


    while(!valid_data) {
		int result = dialog.run();
        if (result != 1) {
            dialog.close();
			Gtk::MessageDialog mdialog("Your request has been cancelled!"); 
			mdialog.set_transient_for(*this);
			dialog.hide();
			mdialog.run(); 
			dialog.close();
            return;
        }

        valid_data = true;
        try {
            d_salary = std::stod(e_salary.get_text());
        } catch(std::exception e) {
            e_salary.set_text("*** invalid salary ***");
            valid_data = false;
        }
    }
	Mice::Server new_server(e_name.get_text(), e_phone.get_text(), std::to_string(employee_id), d_salary);
		_emp->add_server(new_server);

	Gtk::MessageDialog mdialog(e_name.get_text() + "\nEmployee ID: #" + std::to_string(employee_id) + "\nhas been added!");
	mdialog.set_transient_for(*this);
	employee_id++; 
	dialog.hide();
	mdialog.run(); 
	dialog.close();
	return;
}

