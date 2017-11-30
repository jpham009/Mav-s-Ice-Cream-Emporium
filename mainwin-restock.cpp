#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>


void Mainwin::on_restock_click(){


	//define
	restockdialog = new Gtk::Dialog("Restock");
	restockdialog->override_background_color(Gdk::RGBA("#f7f7f7"));
	restockdialog->get_vbox()->override_background_color(Gdk::RGBA("#f7f7f7"));
	Gtk::HBox *hb_all = Gtk::manage(new Gtk::HBox());
	Gtk::VBox *vb_containers = Gtk::manage(new Gtk::VBox());
	Gtk::VBox *vb_scoops = Gtk::manage(new Gtk::VBox());
	Gtk::VBox *vb_toppings = Gtk::manage(new Gtk::VBox());
	
	
	hb_all->set_border_width(30);
	hb_all->override_background_color(Gdk::RGBA("#f7f7f7"));

	l_container = Gtk::manage(new Gtk::Label());
	l_container->set_markup("<span font='18' underline='single'> Containers </span>");
	l_container->set_padding(0, 25);
	vb_containers->pack_start(*l_container, Gtk::PACK_SHRINK);
	for(Mice::Container container : _emp->containers()){
		grid_container = Gtk::manage(new Gtk::Grid());
		name_container = Gtk::manage(new Gtk::Label());
		std::string name_c = "<span weight='bold'>" + container.name() + "</span>";
		name_container->set_markup(name_c);
		quantity_container = Gtk::manage(new Gtk::Label());
		q_container_vector.push_back(quantity_container);
		if(container.quantity() > 15){
		std::string ss_container2 = "<span color='green' weight='bold'>Quantity: [ " + std::to_string(container.quantity()) + " ]</span>";
		quantity_container->set_markup(ss_container2);	
		}
		else if(container.quantity() <= 15 && container.quantity() > 5){
		std::string ss_container2 = "<span color='#ff7200' weight='bold'>Quantity: [ " + std::to_string(container.quantity()) + " ]</span>";
		quantity_container->set_markup(ss_container2);	
		}
		else{
		std::string ss_container2 = "<span color='red' weight='bold'>Quantity: [ " + std::to_string(container.quantity()) + " ]</span>";
		quantity_container->set_markup(ss_container2);	
		}

		name_container->set_alignment(0,0.5);		
		grid_container->add(*name_container);
		grid_container->add(*quantity_container);
		grid_container->set_column_homogeneous(true);
		vb_containers->pack_start(*grid_container, Gtk::PACK_SHRINK);
	}	
	
	l_scoop = Gtk::manage(new Gtk::Label()); 
	l_scoop->set_markup("<span font='18' underline='single'> Scoops </span>");
	l_scoop->set_padding(0, 25);
	vb_scoops->pack_start(*l_scoop, Gtk::PACK_SHRINK);
	for(Mice::Scoop scoop : _emp->scoops()){
		grid_scoop = Gtk::manage(new Gtk::Grid());
		name_scoop = Gtk::manage(new Gtk::Label(scoop.name()));
		std::string name_s = "<span weight='bold'>" + scoop.name() + "</span>";
		name_scoop->set_markup(name_s);
		quantity_scoop = Gtk::manage(new Gtk::Label());
		q_scoop_vector.push_back(quantity_scoop);
		if(scoop.quantity() > 15){
		std::string ss_scoop2 = "<span color='green' weight='bold'>Quantity: [ " + std::to_string(scoop.quantity()) + " ]</span>";
		quantity_scoop->set_markup(ss_scoop2);	
		}
		else if(scoop.quantity() <= 15 && scoop.quantity() > 5){
		std::string ss_scoop2 = "<span color='#ff7200' weight='bold'>Quantity: [ " + std::to_string(scoop.quantity()) + " ]</span>";
		quantity_scoop->set_markup(ss_scoop2);
		}
		else{
		std::string ss_scoop2 = "<span color='red' weight='bold'>Quantity: [ " + std::to_string(scoop.quantity()) + " ]</span>";
		quantity_scoop->set_markup(ss_scoop2);
		}
		grid_scoop->set_column_homogeneous(true);
		name_scoop->set_alignment(0,0.5);		
		grid_scoop->add(*name_scoop);
		grid_scoop->add(*quantity_scoop);
		vb_scoops->pack_start(*grid_scoop, Gtk::PACK_SHRINK);
	}	

	l_topping = Gtk::manage(new Gtk::Label()); 
	l_topping->set_markup("<span font='18' underline='single'> Toppings </span>");
	l_topping->set_padding(0, 25);
	vb_toppings->pack_start(*l_topping, Gtk::PACK_SHRINK);
	
	for(Mice::Topping topping : _emp->toppings()){
		grid_topping = Gtk::manage(new Gtk::Grid());
		name_topping = Gtk::manage(new Gtk::Label(topping.name()));
		std::string name_t = "<span weight='bold'>" + topping.name() + "</span>";
		name_topping->set_markup(name_t);
		quantity_topping = Gtk::manage(new Gtk::Label());
		q_topping_vector.push_back(quantity_topping);
		if(topping.quantity() > 15){

			std::string ss_topping2 = "<span color='green' weight='bold'>Quantity: [ " + std::to_string(topping.quantity()) + " ]</span>";
			quantity_topping->set_markup(ss_topping2);	
			}
			else if(topping.quantity() <= 15 && topping.quantity() > 5){
			std::string ss_topping2 = "<span color='#ff7200' weight='bold'>Quantity: [ " + std::to_string(topping.quantity()) + " ]</span>";
			quantity_topping->set_markup(ss_topping2);
			}
			else{
			std::string ss_topping2 = "<span color='red' weight='bold'>Quantity: [ " + std::to_string(topping.quantity()) + " ]</span>";
			quantity_topping->set_markup(ss_topping2);
			}

		
		grid_topping->set_column_homogeneous(true);
		name_topping->set_alignment(0,0.5);		
		grid_topping->add(*name_topping);
		grid_topping->add(*quantity_topping);
		vb_toppings->pack_start(*grid_topping, Gtk::PACK_SHRINK);
	}	

	
	hb_all->pack_start(*vb_containers);
	hb_all->pack_start(*vb_scoops);
	hb_all->pack_start(*vb_toppings);
	hb_all->set_homogeneous(true);
	hb_all->set_spacing(35);
	hb_all->set_margin_bottom(30);
	
	restockdialog->get_vbox()->pack_start(*hb_all);
	restockdialog->add_button("Cancel", 0);
	restockdialog->add_button("Restock", 1);
	restockdialog->set_transient_for(*this);
	restockdialog->show_all();
	int result = restockdialog->run();
	if (result == 1){
		restock();
		on_restock_click();

	} 

		restockdialog->hide();


	return;

}


void Mainwin::restock(){
	
	double restock_cost = 0;
	for(Mice::Container container : _emp->containers()){
		restock_cost += (container.max_quantity()-container.quantity())*container.cost(); 
	}
	for(Mice::Scoop scoop : _emp->scoops()){
		restock_cost += (scoop.max_quantity()-scoop.quantity())*scoop.cost(); 
	}
	for(Mice::Topping topping : _emp->toppings()){
		restock_cost += (topping.max_quantity()-topping.quantity())*topping.cost(); 
	}
//	
	if(restock_cost == 0){ Gtk::MessageDialog *dialog0 = new Gtk::MessageDialog("There is nothing to restock..."); dialog0->set_transient_for(*this); restockdialog->hide(); dialog0->run(); dialog0->close(); delete dialog0; return;}

	std::string confirm = "Restock cost will be $" + to_string_with_precision(restock_cost) + "\nAre you sure you want to restock?";
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
		dialog1.close();
		restockdialog->hide();
		return;	
	}
	else{
		//charge
	_balance -= restock_cost;
	_money_out += restock_cost;
		for(int i = 0; i < _emp->containers().size(); i++){
			_emp->container(i).restock();
		}
		for(int i = 0; i < _emp->scoops().size(); i++){
			_emp->scoop(i).restock();
		}
		for(int i = 0; i < _emp->toppings().size(); i++){
			_emp->topping(i).restock();
		}
		restockdialog->hide();
	}
	return;
}

