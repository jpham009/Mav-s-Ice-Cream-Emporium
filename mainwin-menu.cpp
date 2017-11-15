#include "mainwin.h"

void Mainwin::menu_click() {
	std::string title = "<span font='14' weight='bold' color='#0077ff'>\nMav's Ice Cream Emporium Menu</span>\n\n";
	std::string hcontainers = "<span weight='bold' underline='single'>Containers</span>\n";
	std::string hscoops = "<span weight='bold' underline='single'>Scoops</span>\n";
	std::string htoppings = "<span weight='bold' underline='single'>Toppings</span>\n";
	std::string menu = title + hcontainers + containers_to_string() + "\n" + hscoops +  scoops_to_string() + "\n" + htoppings + toppings_to_string() + "\n"; 


	Gtk::MessageDialog dialog(menu, "MICE Menu"); 
	dialog.set_transient_for(*this);
	Gtk::Image menu_image("menu_image.png");
	dialog.set_image(menu_image);
	menu_image.set_halign(Gtk::ALIGN_START);
	menu_image.set_valign(Gtk::ALIGN_CENTER);
	dialog.show_all();
	dialog.run();
	dialog.close();

}






