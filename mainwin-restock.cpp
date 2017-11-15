#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>


void Mainwin::on_restock_click(){
	Gtk::Dialog dialog("Restock");
	dialog.set_border_width(30);
	
	Gtk::HBox hb_all;
	Gtk::VBox vb_containers;
	Gtk::VBox vb_scoops;
	Gtk::VBox vb_toppings;
	

	Gtk::Label l_container;
	l_container.set_markup("<span font='18' underline='single'> Containers </span>");
	l_container.set_padding(0, 25);
	vb_containers.pack_start(l_container, Gtk::PACK_SHRINK);
	for(Mice::Container container : _containers){
		Gtk::Grid *grid_container = Gtk::manage(new Gtk::Grid());
		Gtk::Label *name_container = Gtk::manage(new Gtk::Label(container.name()));
		Gtk::Label *quantity_container = Gtk::manage(new Gtk::Label());
		if(container.quantity() == 0){
		ostringstream ss_container;
		ss_container << "<span color='red' weight='bold'>Quantity: [ " << std::to_string(container.quantity()) << " ]</span>";
		std::string ss_container2 = ss_container.str();	
		
		quantity_container->set_markup(ss_container2);
		}
		else{
			quantity_container->set_text("Quantity: [ " + std::to_string(container.quantity()) + " ]");		
		}

		name_container->set_alignment(0,0.5);		
		grid_container->add(*name_container);
		grid_container->add(*quantity_container);
		grid_container->set_column_homogeneous(true);
		vb_containers.pack_start(*grid_container, Gtk::PACK_SHRINK);
	}	
	
	Gtk::Label l_scoop;
	l_scoop.set_markup("<span font='18' underline='single'> Scoops </span>");
	l_scoop.set_padding(0, 25);
	vb_scoops.pack_start(l_scoop, Gtk::PACK_SHRINK);
	for(Mice::Scoop scoop : _scoops){
		Gtk::Grid *grid_scoop = Gtk::manage(new Gtk::Grid());
		Gtk::Label *name_scoop = Gtk::manage(new Gtk::Label(scoop.name()));
		Gtk::Label *quantity_scoop = Gtk::manage(new Gtk::Label());
		if(scoop.quantity() == 0){
		ostringstream ss_scoop;
		ss_scoop << "<span color='red' weight='bold'>Quantity: [ " << std::to_string(scoop.quantity()) << " ]</span>";
		std::string ss_scoop2 = ss_scoop.str();	
		
		quantity_scoop->set_markup(ss_scoop2);
		}
		else{
			quantity_scoop->set_text("Quantity: [ " + std::to_string(scoop.quantity()) + " ]");		
		}

		grid_scoop->set_column_homogeneous(true);
		name_scoop->set_alignment(0,0.5);		
		grid_scoop->add(*name_scoop);
		grid_scoop->add(*quantity_scoop);
		vb_scoops.pack_start(*grid_scoop, Gtk::PACK_SHRINK);
	}	

	Gtk::Label l_topping;
	l_topping.set_markup("<span font='18' underline='single'> Toppings </span>");
	l_topping.set_padding(0, 25);
	vb_toppings.pack_start(l_topping, Gtk::PACK_SHRINK);
	for(Mice::Topping topping : _toppings){
		Gtk::Grid *grid_topping = Gtk::manage(new Gtk::Grid());
		Gtk::Label *name_topping = Gtk::manage(new Gtk::Label(topping.name()));
		Gtk::Label *quantity_topping = Gtk::manage(new Gtk::Label());

		if(topping.quantity() == 0){
		ostringstream ss_top;
		ss_top << "<span color='red' weight='bold'>Quantity: [ " << std::to_string(topping.quantity()) << " ]</span>";
		std::string ss_top2 = ss_top.str();	
		
		quantity_topping->set_markup(ss_top2);
		}
		else{
			quantity_topping->set_text("Quantity: [ " + std::to_string(topping.quantity()) + " ]");		
		}

		
		grid_topping->set_column_homogeneous(true);
		name_topping->set_alignment(0,0.5);		
		grid_topping->add(*name_topping);
		grid_topping->add(*quantity_topping);
		vb_toppings.pack_start(*grid_topping, Gtk::PACK_SHRINK);
	}	

	
	hb_all.pack_start(vb_containers);
	hb_all.pack_start(vb_scoops);
	hb_all.pack_start(vb_toppings);
	hb_all.set_homogeneous(true);
	hb_all.set_spacing(35);
	hb_all.set_margin_bottom(30);
	
	dialog.get_vbox()->pack_start(hb_all);
	dialog.add_button("Cancel", 0);
	dialog.add_button("Restock", 1);
	dialog.set_transient_for(*this);
	dialog.show_all();
	int result = dialog.run();
	if (result == 1){
		restock();
		
	} 
	
	dialog.close();

	return;

}


void Mainwin::restock(){
	
	double restock_cost = 0;
	for(Mice::Container container : _containers){
		restock_cost += (container.max_quantity()-container.quantity())*container.cost(); 
	}
	for(Mice::Scoop scoop : _scoops){
		restock_cost += (scoop.max_quantity()-scoop.quantity())*scoop.cost(); 
	}
	for(Mice::Topping topping : _toppings){
		restock_cost += (topping.max_quantity()-topping.quantity())*topping.cost(); 
	}
	_balance -= restock_cost;

	std::string confirm = "Restock cost will be $" + to_string_with_precision(restock_cost);
	Gtk::Dialog dialog1("Confirm");
	dialog1.set_transient_for(*this); 
	Gtk::Label l_confirm(confirm);
	dialog1.set_border_width(15);
	l_confirm.set_margin_bottom(15);
	dialog1.get_vbox()->pack_start(l_confirm);
	dialog1.add_button("Cancel", 0);
	dialog1.add_button("Ok", 1);
	dialog1.show_all();	
	int result = dialog1.run();
	if (result == 0){
		Gtk::MessageDialog cancel("Your request has been cancelled!");
		cancel.run();
		cancel.close();		
		return; 
	} 
		
	std::string s = "Your balance is: $" + to_string_with_precision(_balance);
	Gtk::MessageDialog dialog(s);
	dialog.set_transient_for(*this);
	dialog.run(); 
	dialog.close();
	return;
}

