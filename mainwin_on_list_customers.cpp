#include "mainwin.h"

void Mainwin::on_list_customers() {
	std::string title = "<span font='14' weight='bold' color='#0077ff'>\nM.I.C.E. Customers List</span>\n\n";
	std::string hcustomers = "<span weight='bold' underline='single'>Customers</span>\n";
	std::string menu = title + hcustomers + customers_to_string() + "\n"; 


	Gtk::MessageDialog *dialog = new Gtk::MessageDialog(menu, "List All Customers"); 
	Gtk::Image *menu_image = new Gtk::Image("");
	dialog->set_image(*menu_image);
	menu_image->show(); 
	dialog->run();
	dialog->close();

}
