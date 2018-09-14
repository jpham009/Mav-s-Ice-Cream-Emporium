#include "mainwin.h"

Mainwin::Mainwin() {
////////// L O A D  D E F A U L T S //////////
	// Start with a default emporium
    _emp = new Mice::Emporium{"Default"};
    set_title("Mav's Ice Cream Emporium");	

	//Easter Egg - Test Persons
	easter_egg(); 
	start();
}

Mainwin::~Mainwin() { }

void Mainwin::start(){
	

	////////// L O G I N //////////
	std::vector<int> login_vector = login();
	p_access = login_vector[0];
	p_index = login_vector[1];
	
	if(p_access==0) {username = "Owner"; role = "Big Boss Man"; order_s = "999";}
	else if(p_access==1) {username = _emp->manager(p_index).name(); role = _emp->manager(p_index).type(); order_s = std::to_string(_emp->manager(p_index).num_orders());}
	else if(p_access==2) {username = _emp->server(p_index).name(); role = _emp->server(p_index).type();}
	else if(p_access==3) {username = _emp->customer(p_index).name(); role = _emp->customer(p_index).type();}
	else {username = "Guest"; role = "Guest"; order_s = "Guest";}


    // /////////////////
    // 	M A I N  W I N 
    // /////////////////

    set_default_size(575, 200);
	set_position(Gtk::WIN_POS_CENTER);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

if(p_access <= 2){

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

    //         S A V E  E M P O R I U M
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_file_save_click));
    filemenu->append(*menuitem_save);
 //         O P E N   E M P O R I U M
    // (Owner) “Open an Emporium File” Append Open to the File menu
     Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_file_open_click));
    filemenu->append(*menuitem_open);

    //         L O A D   D E F A U L T S 
    // (TODO: Test Only) “Create a New Emporium” Append defaults to the File menu
    Gtk::MenuItem *menuitem_load_defaults= Gtk::manage(new Gtk::MenuItem("_Load Defaults", true));
    menuitem_load_defaults->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_about_click));
	menuitem_load_defaults->set_sensitive(false);
    filemenu->append(*menuitem_load_defaults);
	
	

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    filemenu->append(*menuitem_quit);

//    //
//    //     C R E A T E
//    // Create a Create menu and add to the menu bar
//    Gtk::MenuItem *menuitem_create = Gtk::manage(new Gtk::MenuItem("_Options", true));
//    menubar->append(*menuitem_create);
//    Gtk::Menu *createmenu = Gtk::manage(new Gtk::Menu());
//    menuitem_create->set_submenu(*createmenu);

//    //         O R D E R
//    // (All) “Create Delicious Ice Cream Treats” Append Order to the Create menu
//    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Create an Order", true));
//    menuitem_order->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_order_click));
//    createmenu->append(*menuitem_order);

//    //         C U S T O M E R
//    // (Server, Manager, Owner) “Create a New Customer” Append Customer to the Create menu
//    Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Add New Customer", true));
//    menuitem_customer->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_add_customer_click));
//    createmenu->append(*menuitem_customer);

//    //         I T E M 
//    // (Owner, Manager) “Create a New Container, Ice Cream Flavor, or Topping” Append Item to the Create menu
//    Gtk::MenuItem *menuitem_item = Gtk::manage(new Gtk::MenuItem("_Add New Item", true));
//    menuitem_item->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_item_click));
//    createmenu->append(*menuitem_item);

    //         S E R V E R
    // (Owner, Manager) “Add a New Employee” Append Server to the Create menu
   // Gtk::MenuItem *menuitem_server = Gtk::manage(new Gtk::MenuItem("_Add New Server", true));
    //menuitem_server->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_server_click));
  //  createmenu->append(*menuitem_server);

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

Gtk::HBox *hb_title = Gtk::manage(new Gtk::HBox());
Gtk::Image *order_logo;
if(p_access >=2) order_logo = Gtk::manage(new Gtk::Image("order_logo.png"));
else order_logo = Gtk::manage(new Gtk::Image("order_logo_mgt.png"));
order_logo->set_margin_left(50);
hb_title->pack_start(*order_logo); 
hb_title->set_halign(Gtk::ALIGN_CENTER);
hb_title->set_valign(Gtk::ALIGN_START);
if(p_access >=3){ 
hb_title->set_margin_top(50);
hb_title->set_margin_bottom(80);
}
	vbox->add(*hb_title);
	vbox->override_background_color(Gdk::RGBA("#f7f7f7"));
	


	///////////////////
	// T O O L B A R //
	///////////////////

 	Gtk::Toolbar *toolbar3 = Gtk::manage(new Gtk::Toolbar);
	
	toolbar3->set_halign(Gtk::ALIGN_CENTER);
	toolbar3->set_valign(Gtk::ALIGN_CENTER);
	toolbar3->override_background_color(Gdk::RGBA("opaque"));
if(p_access >= 3){
	toolbar3->set_margin_bottom(100);
}
	toolbar3->set_hexpand(true);
    vbox->add(*toolbar3);

   	//   C R E A T E   O R D E R
    Gtk::Image *create_order_button_image = Gtk::manage(new Gtk::Image("new_order.png"));
    Gtk::ToolButton *create_order_button = Gtk::manage(new Gtk::ToolButton(*create_order_button_image));
    create_order_button->set_tooltip_markup("Create a new order");
    create_order_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_create_order_click));
    toolbar3->append(*create_order_button);

	//	 M E N U  
	Gtk::Image *menu_image = Gtk::manage(new Gtk::Image("menu.png"));
    Gtk::ToolButton *menu_button = Gtk::manage(new Gtk::ToolButton(*menu_image));
    menu_button->set_tooltip_markup("Menu");
    menu_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::menu_click));
    toolbar3->append(*menu_button);

	// G A L L E R Y 
    menuwin_image = Gtk::manage(new Gtk::Image("gallery.png"));
    Gtk::ToolButton *menuwin_button = Gtk::manage(new Gtk::ToolButton(*menuwin_image));
    menuwin_button->set_tooltip_markup("Gallery");
    menuwin_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::gallery));
    toolbar3->append(*menuwin_button);

	// Q U I T
    Gtk::Image *quit_image = Gtk::manage(new Gtk::Image("logout.png"));
    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(*quit_image));
    quit_button->set_tooltip_markup("Quit");
    quit_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    toolbar3->append(*quit_button);






//	//  F I L L  O R D E R  //OBSOLETE
//	Gtk::Image *fill_order_image = Gtk::manage(new Gtk::Image("fill_order.png"));
//    Gtk::ToolButton *fill_order_button = Gtk::manage(new Gtk::ToolButton(*fill_order_image));
//    fill_order_button->set_tooltip_markup("Fill Order");
//    fill_order_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_fill_order_click));
//    toolbar3->append(*fill_order_button);

//		
if(p_access <= 2){
 	Gtk::Toolbar *toolbar2 = Gtk::manage(new Gtk::Toolbar);
	toolbar2->set_halign(Gtk::ALIGN_CENTER);
	toolbar3->set_valign(Gtk::ALIGN_CENTER);
	toolbar2->override_background_color(Gdk::RGBA("opaque"));
    vbox->add(*toolbar2);
	// P E N D I N G  O R D E R S  W I N D O W 
	pending_image = Gtk::manage(new Gtk::Image("pendingorders.png"));
    Gtk::ToolButton *pending_button = Gtk::manage(new Gtk::ToolButton(*pending_image));
    pending_button->set_tooltip_markup("Pending Orders");
    pending_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::order_window));
    toolbar2->append(*pending_button);

	//R E S T O C K
	Gtk::Image *restock_image = Gtk::manage(new Gtk::Image("restock.png"));
    Gtk::ToolButton *restock_button = Gtk::manage(new Gtk::ToolButton(*restock_image));
    restock_button->set_tooltip_markup("Restock");
    restock_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_restock_click));
    toolbar2->append(*restock_button);

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
}
if(p_access <= 1){
	Gtk::Toolbar *toolbar1 = Gtk::manage(new Gtk::Toolbar);
	toolbar1->set_halign(Gtk::ALIGN_CENTER);
	toolbar1->set_valign(Gtk::ALIGN_CENTER);
	toolbar1->override_background_color(Gdk::RGBA("opaque"));
    vbox->add(*toolbar1);

	// 	A D D  S E R V E R 
    add_server_image = Gtk::manage(new Gtk::Image("add_server.png"));
    Gtk::ToolButton *add_server_button = Gtk::manage(new Gtk::ToolButton(*add_server_image));
    add_server_button->set_tooltip_markup("Add Server");
    add_server_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_add_server_click));
    toolbar1->append(*add_server_button);

	// 	L I S T  A L L  E M P L O Y E E S 
    list_servers_image = Gtk::manage(new Gtk::Image("list_employees.png"));
    Gtk::ToolButton *list_servers_button = Gtk::manage(new Gtk::ToolButton(*list_servers_image));
    list_servers_button->set_tooltip_markup("List All Employees");
    list_servers_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_list_employees));
    toolbar1->append(*list_servers_button);
		
	//	C R E A T E   N E W   I T E M
    Gtk::Image *create_item_button_image = Gtk::manage(new Gtk::Image("create_item.png"));
    Gtk::ToolButton *create_item_button = Gtk::manage(new Gtk::ToolButton(*create_item_button_image));
    create_item_button->set_tooltip_markup("Create a new item");
    create_item_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_create_item_click));
    toolbar1->append(*create_item_button);

	//	M O N E Y
    money_image = Gtk::manage(new Gtk::Image("money.png"));
    Gtk::ToolButton *money_button = Gtk::manage(new Gtk::ToolButton(*money_image));
    money_button->set_tooltip_markup("$$$");
    money_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_money_click));
    toolbar1->append(*money_button);

//if(p_access == 0){
	Gtk::Toolbar *toolbar0 = Gtk::manage(new Gtk::Toolbar);
	toolbar0->set_halign(Gtk::ALIGN_CENTER);
	toolbar0->set_valign(Gtk::ALIGN_CENTER);
	toolbar0->override_background_color(Gdk::RGBA("opaque"));
    vbox->add(*toolbar0);

    //	N E W   E M P O R I U M
	Gtk::Image *new_emporium_image = Gtk::manage(new Gtk::Image("new_emporium.png"));
    Gtk::ToolButton *new_emporium_button = Gtk::manage(new Gtk::ToolButton(*new_emporium_image));
    new_emporium_button->set_tooltip_markup("Create a New Emporium");
    new_emporium_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_about_click));
    toolbar0->append(*new_emporium_button);

	//	A D D   M A N A G E R 
    Gtk::Image *add_manager_image = Gtk::manage(new Gtk::Image("manager_icon.png"));
    Gtk::ToolButton *add_manager_button = Gtk::manage(new Gtk::ToolButton(*add_manager_image));
    add_manager_button->set_tooltip_markup("Add a new manager");
    add_manager_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::add_manager));
    toolbar0->append(*add_manager_button);
//}
	
}
	//////////////////////////
    /// E N D :: M A I N  W I N  
    //////////////////////////

	
	//// S T A T U S   B A R   D I S P L A Y ////
    name_m = Gtk::manage(new Gtk::Label("Logged in: " + username + " (" + role + ") "));
	order_m = Gtk::manage(new Gtk::Label("Order: " + order_s));
	order_m->set_alignment(0);
	order_m->set_margin_left(10);
	name_m->set_alignment(1);
	name_m->set_margin_right(10);
	
	Gtk::Box *b_status = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    vbox->add(*b_status);
	b_status->pack_start(*order_m, Gtk::PACK_SHRINK);
    b_status->pack_end(*name_m, Gtk::PACK_SHRINK);
	b_status->show_all();


    // Make the box and everything in it visible
    vbox->show_all();
}

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_quit_click() {
    hide();
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
	return;
}

void Mainwin::logout(){

}


