#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <sstream>
static int order_counter = 1; //order numbers

Mainwin::Mainwin() {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(575, 200);

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
    //menuitem_new->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_new_game_click));
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
    //menuitem_customer->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_customer_click));
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
    restock_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_about_click));
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
    add_customer_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    toolbar2->append(*add_customer_button);

	// 	A D D  S E R V E R 
    add_server_image = Gtk::manage(new Gtk::Image("add_server.png"));
    Gtk::ToolButton *add_server_button = Gtk::manage(new Gtk::ToolButton(*add_server_image));
    add_server_button->set_tooltip_markup("Add Server");
    add_server_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    toolbar2->append(*add_server_button);

	// 	L I S T  A L L  C U S T O M E R S
    list_customers_image = Gtk::manage(new Gtk::Image("list_customers.png"));
    Gtk::ToolButton *list_customers_button = Gtk::manage(new Gtk::ToolButton(*list_customers_image));
    list_customers_button->set_tooltip_markup("List All Customers");
    list_customers_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    toolbar2->append(*list_customers_button);

	// 	L I S T  A L L  E M P L O Y E E S 
    list_servers_image = Gtk::manage(new Gtk::Image("list_employees.png"));
    Gtk::ToolButton *list_servers_button = Gtk::manage(new Gtk::ToolButton(*list_servers_image));
    list_servers_button->set_tooltip_markup("List All Employees");
    list_servers_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
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
    //new_emporium_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_new_emporium_click));
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
    money_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_about_click));
    toolbar->append(*money_button);
/////////////////////////////////////////////////////////////////////////////////////////////

    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for game messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->add(*msg);

    // Make the box and everything in it visible
    vbox->show_all();



	////////////////////////TODO////////////////////


	//Auto-Load Defaults
	on_load_defaults_click();
	
	//Status bar initialize
	status();


}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_quit_click() {
    hide();
}

////////////////////////////////////////////TODO////////////////////////////////////////////

void Mainwin::on_create_order_click() {
	try { //OG code
	Mice::Order order = create_order(); 
	} 
	catch(std::runtime_error e) { // User canceled order
   	}
}

void Mainwin::status(){
 // s collects the status message
    Glib::ustring s = "";
	
	s += "";
		
// Display the collected status on the status bar
    msg->set_markup(s);	
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
		Gtk::MessageDialog *dialog = new Gtk::MessageDialog(load_defaults, "Default Items Loaded"); 
		Gtk::Image *default_image = new Gtk::Image("defaults_loaded.png");
		default_image->show();
		dialog->set_image(*default_image);
        dialog->run();
        dialog->close();
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

void Mainwin::menu_click() {
	std::string title = "<span font='14' weight='bold' color='#0077ff'>\nMav's Ice Cream Emporium Menu</span>\n\n";
	std::string hcontainers = "<span weight='bold' underline='single'>Containers</span>\n";
	std::string hscoops = "<span weight='bold' underline='single'>Scoops</span>\n";
	std::string htoppings = "<span weight='bold' underline='single'>Toppings</span>\n";
	std::string menu = title + hcontainers + containers_to_string() + "\n" + hscoops +  scoops_to_string() + "\n" + htoppings + toppings_to_string() + "\n"; 


	Gtk::MessageDialog *dialog = new Gtk::MessageDialog(menu, "MICE Menu"); 
	Gtk::Image *menu_image = new Gtk::Image("menu_logo.png");
	dialog->set_image(*menu_image);
	menu_image->show(); 
	dialog->run();
	dialog->close();

}






