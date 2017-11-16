#include "mainwin.h"


Mainwin::Mainwin() {

	////////// L O A D  D E F A U L T S //////////

	//Auto-Load Defaults
	on_load_defaults_click();

	//Easter Egg - Test Persons
	easter_egg(); 


	////////// L O G I N //////////
	std::vector<int> login_vector = login();
	p_access = login_vector[0];
	p_index = login_vector[1];
	

	if(p_access==1) {username = _managers[p_index].name(); role = _managers[p_index].type(); order_s = std::to_string(_managers[p_index].get_orders());}
	else if(p_access==2) {username = _servers[p_index].name(); role = _servers[p_index].type();}
	else if(p_access==3) {username = _customers[p_index].name(); role = _customers[p_index].type();}
	else {username = "Guest"; role = "Guest"; order_s = "Guest";}


    // /////////////////
    // 	M A I N  W I N 
    // /////////////////

    set_default_size(575, 200);
	set_position(Gtk::WIN_POS_CENTER);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

if(p_access <=3){

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

}

	//////////////////////////////
	// C O N S U M E R  L O G O //
	//////////////////////////////

if(p_access >= 3){
Gtk::HBox *hb_title = Gtk::manage(new Gtk::HBox());
Gtk::Image *order_logo = Gtk::manage(new Gtk::Image("order_logo.png"));
order_logo->set_margin_right(30);
 
//Gtk::Label *l_title = Gtk::manage(new Gtk::Label());
//std::string s_title = "<span font='18' color='blue' weight='bold'>    Mav's\n Ice Cream\n Emporium</span>";
//l_title->set_markup(s_title);
//l_title->set_halign(Gtk::ALIGN_CENTER);
//hb_title->pack_start(*l_title); 

hb_title->pack_start(*order_logo); 
hb_title->set_halign(Gtk::ALIGN_CENTER);
hb_title->set_valign(Gtk::ALIGN_START);
hb_title->set_margin_top(50);
hb_title->set_margin_bottom(80);
	vbox->add(*hb_title);
	vbox->override_background_color(Gdk::RGBA("#f7f7f7"));
	

}
	///////////////////
	// T O O L B A R //
	///////////////////

 	Gtk::Toolbar *toolbar3 = Gtk::manage(new Gtk::Toolbar);
	
	toolbar3->set_halign(Gtk::ALIGN_CENTER);
	toolbar3->set_valign(Gtk::ALIGN_CENTER);
	if(p_access >= 3){
		toolbar3->override_background_color(Gdk::RGBA("opaque"));
		toolbar3->set_margin_bottom(100);
	}
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


if(p_access <= 2){

	//  F I L L  O R D E R 
	Gtk::Image *fill_order_image = Gtk::manage(new Gtk::Image("fill_order.png"));
    Gtk::ToolButton *fill_order_button = Gtk::manage(new Gtk::ToolButton(*fill_order_image));
    fill_order_button->set_tooltip_markup("Fill Order");
    fill_order_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_fill_order_click));
    toolbar3->append(*fill_order_button);

//		R E S T O C K
	Gtk::Image *restock_image = Gtk::manage(new Gtk::Image("restock.png"));
    Gtk::ToolButton *restock_button = Gtk::manage(new Gtk::ToolButton(*restock_image));
    restock_button->set_tooltip_markup("Restock");
    restock_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_restock_click));
    toolbar3->append(*restock_button);


}

if(p_access <= 2){
 	Gtk::Toolbar *toolbar2 = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar2);

	// 	A D D  C U S T O M E R 
    add_customer_image = Gtk::manage(new Gtk::Image("add_customer.png"));
    Gtk::ToolButton *add_customer_button = Gtk::manage(new Gtk::ToolButton(*add_customer_image));
    add_customer_button->set_tooltip_markup("Add Customer");
    add_customer_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_add_customer_click));
    toolbar2->append(*add_customer_button);

	// 	L I S T  A L L  C U S T O M E R S
    list_customers_image = Gtk::manage(new Gtk::Image("list_customers.png"));
    Gtk::ToolButton *list_customers_button = Gtk::manage(new Gtk::ToolButton(*list_customers_image));
    list_customers_button->set_tooltip_markup("List All Customers");
    list_customers_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_list_customers));
    toolbar2->append(*list_customers_button);

	if(p_access <=1){
	// 	A D D  S E R V E R 
    add_server_image = Gtk::manage(new Gtk::Image("add_server.png"));
    Gtk::ToolButton *add_server_button = Gtk::manage(new Gtk::ToolButton(*add_server_image));
    add_server_button->set_tooltip_markup("Add Server");
    add_server_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_add_server_click));
    toolbar2->append(*add_server_button);


	// 	L I S T  A L L  E M P L O Y E E S 
    list_servers_image = Gtk::manage(new Gtk::Image("list_employees.png"));
    Gtk::ToolButton *list_servers_button = Gtk::manage(new Gtk::ToolButton(*list_servers_image));
    list_servers_button->set_tooltip_markup("List All Employees");
    list_servers_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_list_employees));
    toolbar2->append(*list_servers_button);
		
	}
}


if(p_access <= 1){  
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
}	

	//////////////////////////
    /// E N D :: M A I N  W I N  
    //////////////////////////


	////////////////////////TODO////////////////////////

	
	//// S T A T U S   B A R   D I S P L A Y ////
    // Provide a status bar for game messages
    name_m = Gtk::manage(new Gtk::Label("Logged in: " + username + " (" + role + ") "));
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


void Mainwin::status(std::string message){ //TODO
// // s collects the status message
//    Glib::ustring s = "Logged in: ";
//	
//	s += message;
//		
//// Display the collected status on the status bar
//    msg->set_markup(s);	
}

void Mainwin::on_quit_click() {
    hide();
}


vector<int> Mainwin::login() { //TODO first
//return {list, index}

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
	

	//login vector
	std::vector<int> login_vector;
	
	if(dialog.run() == 1){
		//login
		
		for(int i = 0; i < _managers.size(); i++){
			if(_managers[i].name() == e_custname.get_text()){
				login_vector.push_back(1); login_vector.push_back(i);
				return login_vector;
			}
		}
		for(int i = 0; i < _servers.size(); i++){
			if(_servers[i].name() == e_custname.get_text()){
				login_vector.push_back(2); login_vector.push_back(i);
				return login_vector;
			}
		}	
		for(int i = 0; i < _customers.size(); i++){
			if(_customers[i].name() == e_custname.get_text()){
				login_vector.push_back(1); login_vector.push_back(i);
				return login_vector;
			}
		}
		login_vector.push_back(9); login_vector.push_back(9);
		return login_vector;	
	}
	else{
		dialog.close();
		
	}

}
    

void Mainwin::on_create_order_click(){
	try { //OG code 
	Mice::Order order = create_order();
	_orders.push_back(order);

	} 
	catch(std::runtime_error e) { // User canceled order
   	}
}


void Mainwin::on_fill_order_click(){
	if (_orders.empty()) return;
	if (fill_counter > order_counter) return;
	_orders[fill_counter-1].fill(); 
	std::string s = "Order #" + to_string(fill_counter) + " has been filled!"; //check
	Gtk::MessageDialog dialog(s);
	dialog.run(); 
	dialog.close();
	fill_counter++;
	return; 
}


void Mainwin::easter_egg(){
	_customers.push_back(Mice::Customer{"Cheryl Dyer", "8178902356", std::to_string(customer_id++)});
	_customers.push_back(Mice::Customer{"Daniel Fagan", "8178809444", std::to_string(customer_id++)});
	_customers.push_back(Mice::Customer{"Michael Fagan", "8178912365", std::to_string(customer_id++)});
	_servers.push_back(Mice::Server{"Michelle Pham", "6825590111", std::to_string(employee_id++), 12.50});
	_servers.push_back(Mice::Server{"Russell Pham", "6824914447", std::to_string(employee_id++), 11.50});
	_servers.push_back(Mice::Server{"Connor Pham", "6825932036", std::to_string(employee_id++), 11.75});
	_managers.push_back(Mice::Manager{"Johnny Pham", "6825590692", std::to_string(employee_id++), 19.50});		
	_managers.push_back(Mice::Manager{"SUPERUSER", "Super User", "SUPERUSER", 1.00});
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

