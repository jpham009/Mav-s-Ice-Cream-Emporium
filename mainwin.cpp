#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <iomanip>

static int order_counter = 1; //order numbers
static int customer_id = 10000; 
static int employee_id = 20000;
Person *current_user;
//if current_user.access() == 1
//switch 

template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 2)
{
    std::ostringstream out;
    out << std::fixed << std::setprecision(n) << a_value;
    return out.str();
}

Mainwin::Mainwin() {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(575, 200);
	set_position(Gtk::WIN_POS_CENTER);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //
    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         N E W   E M P O R I U M
    // (Owner) “Create a New Emporium” Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Emporium", true));
    menuitem_new->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_about_click));
    filemenu->append(*menuitem_new);

    //         L O A D   D E F A U L T S 
    // (TODO: Test Only) “Create a New Emporium” Append defaults to the File menu
    Gtk::MenuItem *menuitem_load_defaults= Gtk::manage(new Gtk::MenuItem("_Load Defaults", true));
    menuitem_load_defaults->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_load_defaults_click));
    filemenu->append(*menuitem_load_defaults);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    filemenu->append(*menuitem_quit);

    //
    //     C R E A T E
    // Create a Create menu and add to the menu bar
    Gtk::MenuItem *menuitem_create = Gtk::manage(new Gtk::MenuItem("_Options", true));
    menubar->append(*menuitem_create);
    Gtk::Menu *createmenu = Gtk::manage(new Gtk::Menu());
    menuitem_create->set_submenu(*createmenu);

    //         O R D E R
    // (All) “Create Delicious Ice Cream Treats” Append Order to the Create menu
    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Create an Order", true));
    menuitem_order->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_order_click));
    createmenu->append(*menuitem_order);

    //         C U S T O M E R
    // (Server, Manager, Owner) “Create a New Customer” Append Customer to the Create menu
    Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Add New Customer", true));
    menuitem_customer->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_add_customer_click));
    createmenu->append(*menuitem_customer);

    //         I T E M 
    // (Owner, Manager) “Create a New Container, Ice Cream Flavor, or Topping” Append Item to the Create menu
    Gtk::MenuItem *menuitem_item = Gtk::manage(new Gtk::MenuItem("_Add New Item", true));
    menuitem_item->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_item_click));
    createmenu->append(*menuitem_item);

    //         S E R V E R
    // (Owner, Manager) “Add a New Employee” Append Server to the Create menu
    Gtk::MenuItem *menuitem_server = Gtk::manage(new Gtk::MenuItem("_Add New Server", true));
    //menuitem_server->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_server_click));
    createmenu->append(*menuitem_server);

    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
    menuitem_about->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_about_click));
    helpmenu->append(*menuitem_about);




/////////////////////////////////////////////////////////////////////////////////////////////

 	Gtk::Toolbar *toolbar3 = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar3);

   	//     C R E A T E   O R D E R
    // Add a Create Order icon
    Gtk::Image *create_order_button_image = Gtk::manage(new Gtk::Image("new_order.png"));
    Gtk::ToolButton *create_order_button = Gtk::manage(new Gtk::ToolButton(*create_order_button_image));
    create_order_button->set_tooltip_markup("Create a new order");
    create_order_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_create_order_click));
    toolbar3->append(*create_order_button);
	
	//		S H O W  M E N U  
	Gtk::Image *menu_image = Gtk::manage(new Gtk::Image("menu.png"));
    Gtk::ToolButton *menu_button = Gtk::manage(new Gtk::ToolButton(*menu_image));
    menu_button->set_tooltip_markup("Menu");
    menu_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::menu_click));
    toolbar3->append(*menu_button);

	//		R E S T O C K
	Gtk::Image *restock_image = Gtk::manage(new Gtk::Image("restock.png"));
    Gtk::ToolButton *restock_button = Gtk::manage(new Gtk::ToolButton(*restock_image));
    restock_button->set_tooltip_markup("Restock");
    restock_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_restock_click));
    toolbar3->append(*restock_button);

	
	

//SEPARATOR
// Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
//   sep->set_expand(true);  // The expanding sep forces the Quit button to the right
//   toolbar->append(*sep);

 	Gtk::Toolbar *toolbar2 = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar2);

	// 	A D D  C U S T O M E R 
    add_customer_image = Gtk::manage(new Gtk::Image("add_customer.png"));
    Gtk::ToolButton *add_customer_button = Gtk::manage(new Gtk::ToolButton(*add_customer_image));
    add_customer_button->set_tooltip_markup("Add Customer");
    add_customer_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_add_customer_click));
    toolbar2->append(*add_customer_button);

	// 	A D D  S E R V E R 
    add_server_image = Gtk::manage(new Gtk::Image("add_server.png"));
    Gtk::ToolButton *add_server_button = Gtk::manage(new Gtk::ToolButton(*add_server_image));
    add_server_button->set_tooltip_markup("Add Server");
    add_server_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_add_server_click));
    toolbar2->append(*add_server_button);

	// 	L I S T  A L L  C U S T O M E R S
    list_customers_image = Gtk::manage(new Gtk::Image("list_customers.png"));
    Gtk::ToolButton *list_customers_button = Gtk::manage(new Gtk::ToolButton(*list_customers_image));
    list_customers_button->set_tooltip_markup("List All Customers");
    list_customers_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_list_customers));
    toolbar2->append(*list_customers_button);

	// 	L I S T  A L L  E M P L O Y E E S 
    list_servers_image = Gtk::manage(new Gtk::Image("list_employees.png"));
    Gtk::ToolButton *list_servers_button = Gtk::manage(new Gtk::ToolButton(*list_servers_image));
    list_servers_button->set_tooltip_markup("List All Employees");
    list_servers_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_list_employees));
    toolbar2->append(*list_servers_button);


/////////////////////////////////////////////////////////////////////////////////////////////
    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    //     N E W   E M P O R I U M
    // Add a new emporium icon
	Gtk::Image *new_emporium_image = Gtk::manage(new Gtk::Image("new_emporium.png"));
    Gtk::ToolButton *new_emporium_button = Gtk::manage(new Gtk::ToolButton(*new_emporium_image));
    new_emporium_button->set_tooltip_markup("Create a New Emporium");
    new_emporium_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_about_click));
    toolbar->append(*new_emporium_button);


    //     C R E A T E   N E W   I T E M
    // Add a Create Item icon
    Gtk::Image *create_item_button_image = Gtk::manage(new Gtk::Image("create_item.png"));
    Gtk::ToolButton *create_item_button = Gtk::manage(new Gtk::ToolButton(*create_item_button_image));
    create_item_button->set_tooltip_markup("Create a new item");
    create_item_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_create_item_click));
    toolbar->append(*create_item_button);

	//	M O N E Y
    money_image = Gtk::manage(new Gtk::Image("money.png"));
    Gtk::ToolButton *money_button = Gtk::manage(new Gtk::ToolButton(*money_image));
    money_button->set_tooltip_markup("$$$");
    money_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_money_click));
    toolbar->append(*money_button);
/////////////////////////////////////////////////////////////////////////////////////////////





	////////////////////////TODO////////////////////

	//Auto-Load Defaults
	on_load_defaults_click();

	//Easter Egg - Test Persons
	easter_egg(); 

	//Status bar initialize


//TODO	
	Mice::Manager *manager = login();
	name_s = manager->name();
	manager->order_up();
	order_s = std::to_string(manager->get_orders());
	
	//status(manager->name());
	
	    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for game messages
    name_m = Gtk::manage(new Gtk::Label("Logged in: " + name_s));
    //msg->set_hexpand(true);
	order_m = Gtk::manage(new Gtk::Label("Order: " + order_s));
	order_m->set_alignment(0);
	order_m->set_margin_left(10);
	name_m->set_alignment(1);
	name_m->set_margin_right(10);
	
	Gtk::Box *b_status = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    add(*b_status);
	b_status->pack_start(*order_m, Gtk::PACK_SHRINK);
    b_status->pack_end(*name_m, Gtk::PACK_SHRINK);
	b_status->show_all();
	vbox->pack_start(*b_status);

    // Make the box and everything in it visible
    vbox->show_all();
	

}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::status(std::string message){
// // s collects the status message
//    Glib::ustring s = "Logged in: ";
//	
//	s += message;
//		
//// Display the collected status on the status bar
//    msg->set_markup(s);	
}
////////////////////////////////////////////TODO////////////////////////////////////////////
void Mainwin::on_quit_click() {
    hide();
}


////////////////////////////////////////////TODO////////////////////////////////////////////

void Mainwin::order_filled(Mice::Order order){
	_money_in += order.total_price(); 
	_balance += _money_in; 


	for(int i = 0; i < _container_selection.size(); i++){
		_containers[i].consume(); 
	}
	for(int i = 0; i < _scoop_selection.size(); i++){
		_scoops[i].consume(); 
	}
	for(int i = 0; i < _topping_selection.size(); i++){
		_toppings[i].consume(); 
	}
	

	std::string s = "";
	for(Mice::Container container : _containers) s = s + "Item:" + container.name() + " Qty:" + std::to_string(container.quantity()) + "\n";
	for(Mice::Scoop scoop : _scoops) s = s + "Item:" + scoop.name() + " Qty:" + std::to_string(scoop.quantity()) + "\n";
	for(Mice::Topping topping : _toppings) s = s + "Item:" + topping.name() + " Qty:" + std::to_string(topping.quantity()) + "\n";
	
	s = s + "Money in the bank: " + to_string_with_precision(_balance);
	

	Gtk::MessageDialog mdialog(s);
	mdialog.run(); 
	mdialog.close(); 

	////TODO
	
}

Mice::Manager* Mainwin::login() {


    Gtk::Dialog dialog{"Login", *this};
	dialog.set_border_width(15); //borders
	dialog.set_transient_for(*this);
    const int WIDTH = 15;

   
 	    // Name 
    Gtk::HBox b_custname;
    Gtk::Label l_custname{"Username:"};
    l_custname.set_width_chars(WIDTH);
    b_custname.pack_start(l_custname, Gtk::PACK_SHRINK);

    Gtk::Entry e_custname;
    e_custname.set_max_length(WIDTH*4);
    b_custname.pack_start(e_custname, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_custname, Gtk::PACK_SHRINK);


    // Phone
    Gtk::HBox b_custphone;
	b_custphone.set_margin_bottom(15);

    Gtk::Label l_custphone{"Password:"};
    l_custphone.set_width_chars(WIDTH);
    b_custphone.pack_start(l_custphone, Gtk::PACK_SHRINK);

    Gtk::Entry e_custphone;
    e_custphone.set_max_length(WIDTH*4);
    b_custphone.pack_start(e_custphone, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_custphone, Gtk::PACK_SHRINK);

    // Show dialog
    dialog.add_button("Cancel", 0);
    dialog.add_button("Login", 1);
    dialog.show_all();

////KILLS YOU
//	bool valid_data = false;
//	while(!valid_data) {
//	if(dialog.run() == 1){
//		//login
//		for(int i = 0; i < Mainwin::_managers.size(); i++){
//			if(l_custname.get_text() == Mainwin::_managers[i].name()){
//			valid_data = true; 
//			cout << Mainwin::_managers[i].name() << endl; 
//			Mice::Manager* manager_user = &_managers[i];
//			return manager_user;
//			dialog.close();
//			}
//		}
//	}
//	else{
//		dialog.close();
//		}
//	}

	return &_managers[0];

}

//		for(int i = 0; i < Mainwin::_servers.size(); i++){
//			if(l_custname.get_text() == Mainwin::_servers[i].name()){
//			dialog.close();
//			 return &Mainwin::_servers[i];
//			}
//		}


    

////////////////////////////////////////////TODO////////////////////////////////////////////

void Mainwin::on_create_order_click(){
	try { //OG code 
	Mice::Order order = create_order();
	order_filled(order);
	_orders.push_back(order);

	} 
	catch(std::runtime_error e) { // User canceled order
   	}
}

////////////////////////////////////////////TODO////////////////////////////////////////////

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
	if(result == 1){
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
		
	std::string s = "Your balance is: $" + to_string_with_precision(_balance);
	Gtk::MessageDialog dialog(s);
	dialog.run(); 
	dialog.close();
	return;
}


////////////////////////////////////////////TODO////////////////////////////////////////////


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

////////////////////////////////////////////TODO////////////////////////////////////////////
////////////////////////////////////////////TODO////////////////////////////////////////////


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
		_servers.push_back(new_server);

	Gtk::MessageDialog mdialog(e_name.get_text() + "\nEmployee ID: #" + std::to_string(employee_id) + "\nhas been added!");
	mdialog.set_transient_for(*this);
	employee_id++; 
	dialog.hide();
	mdialog.run(); 
	dialog.close();
	return;
}

////////////////////////////////////////////TODO////////////////////////////////////////////

void Mainwin::on_load_defaults_click() {
		
        _containers.push_back(
            Mice::Container{"Sugar Cone", "The classic, crunchy, sweet ice cream cone.", 0.25, 0.50, 2});
        _containers.push_back(
            Mice::Container{"Waffle Cone", "The all-favorite handmade waffle cone has a crispy, syrupy qualities made with real brown sugar.", 0.35, 0.75, 3});
        _containers.push_back(
			Mice::Container{"Cake Cone", "A wafer cone, light and flaky.", 0.25, 0.50, 2});
        _containers.push_back(
            Mice::Container{"Cup", "Just a basic cup to hold your ice cream in!", 0.05, 0.15, 2});

        _scoops.push_back(
            Mice::Scoop{"Chocolate", "Rich, creamy chocolate ice cream made with the finest imported Belgium chocolate", 0.20, 0.50});
        _scoops.push_back(
            Mice::Scoop{"Vanilla", "Creamy handmade vanilla ice cream", 0.20, 0.50});
        _scoops.push_back(
            Mice::Scoop{"Strawberry", "Smooth, Creamy strawberry ice cream made with succulent strawberries.", 0.20, 0.50});
		
			_scoops.push_back(
            Mice::Scoop{"Mint Chocolate Chip", "Refreshing, creamy mint ice cream sprinkled with delicious semi-sweet chocolate chips.", 0.20, 0.50});
			_scoops.push_back(
            Mice::Scoop{"Rocky Road", "A rich, dark chocolate ice cream generously sprinkled with chopped, roasted almonds and miniature marshmallows.", 0.20, 0.50});
			_scoops.push_back(
            Mice::Scoop{"Neopolitan", "Vanilla, Chocolate, and Strawberry ice cream. All in a scoop!", 0.20, 0.50});
			_scoops.push_back(
            Mice::Scoop{"Rainbow Sherbet", "Juicy orange, tart lime and sweet raspberry create a wonderful refreshing taste sure to please!", 0.20, 0.50});
			_scoops.push_back(
            Mice::Scoop{"Cherry Amaretto", "A delightful flavor of black cherry with the sweetness of almond", 0.20, 0.50});

        _toppings.push_back(
            Mice::Topping{"Chocolate Syrup", "Drizzle your ice cream with a sweet semi-sweet chocolate syrup", 0.1, 0.2, 0});
        _toppings.push_back(
            Mice::Topping{"Caramel Syrup", "Smother your ice cream in mouthwatering caramel syrup", 0.1, 0.25, 0});
        _toppings.push_back(
            Mice::Topping{"Maraschino Cherry", "The classic maraschino. Who doesn't want a cherry on top?!", 0.1, 0.2, 0});
		_toppings.push_back(
            Mice::Topping{"Sprinkles", "A rainbow of tiny candies on your ice cream", 0.1, 0.2, 0});

        // Display acknowledgement
		std::string load_defaults = "<span font='14' weight='bold' color='#0077ff'>\n\nWelcome to the Mav's Ice Cream Emporium!</span>\n\n<span font='12'>              Your default items have been loaded!</span>";		
		Gtk::MessageDialog dialog(load_defaults, "Default Items Loaded"); 
		dialog.set_transient_for(*this);
		dialog.set_position(Gtk::WIN_POS_CENTER);
		Gtk::Image default_image("defaults_loaded.png");		
		dialog.set_image(default_image);		
		default_image.set_halign(Gtk::ALIGN_START);
		default_image.set_valign(Gtk::ALIGN_CENTER);
		dialog.show_all();
        dialog.run();
        dialog.close();
 } 

/////TODO NEW STUFF

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

void Mainwin::on_list_employees() {
	std::string title = "<span font='14' weight='bold' color='#0077ff'>\nM.I.C.E. Employees List</span>\n\n";
	std::string hmanagers = "<span weight='bold' underline='single'>Managers</span>\n";
	std::string hservers = "<span weight='bold' underline='single'>Servers</span>\n";
	std::string menu = title + hmanagers + managers_to_string() + "\n" + hservers +  servers_to_string(); 
	Gtk::MessageDialog dialog(menu, "List All Employees"); 
	Gtk::Image menu_image("tinycone.png");
	dialog.set_image(menu_image);
    dialog.set_transient_for(*this);
	menu_image.set_halign(Gtk::ALIGN_START);
	menu_image.set_valign(Gtk::ALIGN_CENTER);
	dialog.show_all(); 
	dialog.run();
	dialog.close();
}

void Mainwin::add_new_customer(){
	string customer_name = "New Customer";
	string customer_phone = "87878741";
	_customers.push_back(Mice::Customer{customer_name, customer_phone, std::to_string(customer_id++)});
}	
void Mainwin::add_new_server(){
	string server_name = "John Doe";
	string server_phone = "682682682";
	double salary = 11.00;
	_servers.push_back(Mice::Server{server_name, server_phone, std::to_string(employee_id++), salary});
}

void Mainwin::add_new_manager(){
	string manager_name = "George Rice";
	string manager_phone = "13251325";
	double salary = 23.40;
	_managers.push_back(Mice::Manager{manager_name, manager_phone, std::to_string(customer_id++), salary});
	
} 


void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog{};
    dialog.set_transient_for(*this);
    dialog.set_program_name("Mav's Ice Cream Emporium by Johnny Pham");
    auto logo = Gdk::Pixbuf::create_from_file("logo.png");
    dialog.set_logo(logo);
    dialog.set_version("Base written by George Rice");
    dialog.set_copyright("Copyright 2017");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"Johnny Pham"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {"Logo by pngimg.com, http://pngimg.com/uploads/ice_cream/ice_cream_PNG5090.png?i=1",
                                            "License: Creative Commons 4.0 BY-NC"};
    dialog.set_artists(artists);
    dialog.run();
}


std::string Mainwin::containers_to_string(){
	std::string containers_string = "";
	for(int i = 0; i < Mainwin::_containers.size(); i++){
		containers_string += Mainwin::_containers[i].name() + "\n";
	}
	return containers_string;
}

std::string Mainwin::scoops_to_string(){
	std::string scoops_string = "";
	for(int i = 0; i < Mainwin::_scoops.size(); i++){
		scoops_string += Mainwin::_scoops[i].name() + "\n";
	}
	return scoops_string;
}

std::string Mainwin::toppings_to_string(){
	std::string toppings_string = "";
	for(int i = 0; i < Mainwin::_toppings.size(); i++){
		toppings_string += Mainwin::_toppings[i].name() + "\n";
	}
	return toppings_string;
} 

std::string Mainwin::customers_to_string(){
	std::string customers_string = "";
	for(int i = 0; i < Mainwin::_customers.size(); i++){
		customers_string += Mainwin::_customers[i].name() + "\n";
	}
	return customers_string;
} 

std::string Mainwin::servers_to_string(){
	std::string servers_string = "";
	for(int i = 0; i < Mainwin::_servers.size(); i++){
		servers_string += Mainwin::_servers[i].name() + "\n";
	}
	return servers_string;
} 
std::string Mainwin::managers_to_string(){
	std::string managers_string = "";
	for(int i = 0; i < Mainwin::_managers.size(); i++){
		managers_string += Mainwin::_managers[i].name() + "\n";
	}
	return managers_string;
} 







void Mainwin::menu_click() {
	std::string title = "<span font='14' weight='bold' color='#0077ff'>\nMav's Ice Cream Emporium Menu</span>\n\n";
	std::string hcontainers = "<span weight='bold' underline='single'>Containers</span>\n";
	std::string hscoops = "<span weight='bold' underline='single'>Scoops</span>\n";
	std::string htoppings = "<span weight='bold' underline='single'>Toppings</span>\n";
	std::string menu = title + hcontainers + containers_to_string() + "\n" + hscoops +  scoops_to_string() + "\n" + htoppings + toppings_to_string() + "\n"; 


	Gtk::MessageDialog dialog(menu, "MICE Menu"); 
	dialog.set_transient_for(*this);
	Gtk::Image menu_image("menu_logo.png");
	dialog.set_image(menu_image);
	menu_image.set_halign(Gtk::ALIGN_START);
	menu_image.set_valign(Gtk::ALIGN_CENTER);
	dialog.show_all();
	dialog.run();
	dialog.close();

}






