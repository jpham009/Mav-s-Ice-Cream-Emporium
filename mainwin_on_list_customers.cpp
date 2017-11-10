#include "mainwin.h"

void Mainwin::on_list_customers() {
	std::string title = "<span font='14' weight='bold' color='#0077ff'>\nM.I.C.E. Customers List</span>\n\n";
	std::string hcustomers = "<span weight='bold' underline='single'>Customers</span>\n";
	std::string menu = title + hcustomers + customers_to_string() + "\n"; 


	Gtk::MessageDialog dialog(menu, "List All Customers"); 
	dialog.set_transient_for(*this);
	Gtk::Image menu_image("tinycone.png");	
	dialog.set_image(menu_image);
	menu_image.set_halign(Gtk::ALIGN_START);
	menu_image.set_valign(Gtk::ALIGN_CENTER);
	dialog.show_all(); 
	dialog.run();
	dialog.close();

}
