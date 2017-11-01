#include "mainwin.h"
#include <exception>
#include <stdexcept>

Mainwin::Mainwin() {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(800, 600);

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

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    filemenu->append(*menuitem_quit);

    //
    //     C R E A T E
    // Create a Create menu and add to the menu bar
    Gtk::MenuItem *menuitem_create = Gtk::manage(new Gtk::MenuItem("_Create", true));
    menubar->append(*menuitem_create);
    Gtk::Menu *createmenu = Gtk::manage(new Gtk::Menu());
    menuitem_create->set_submenu(*createmenu);

    //         O R D E R
    // (All) “Create Delicious Ice Cream Treats” Append Order to the Create menu
    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Order...", true));
    //menuitem_order->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_order_click));
    createmenu->append(*menuitem_order);

    //         C U S T O M E R
    // (Server, Manager, Owner) “Create a New Customer” Append Customer to the Create menu
    Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer...", true));
    //menuitem_customer->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_customer_click));
    createmenu->append(*menuitem_customer);

    //         I T E M 
    // (Owner, Manager) “Create a New Container, Ice Cream Flavor, or Topping” Append Item to the Create menu
    Gtk::MenuItem *menuitem_item = Gtk::manage(new Gtk::MenuItem("_Item...", true));
    menuitem_item->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_item_click));
    createmenu->append(*menuitem_item);

    //         S E R V E R
    // (Owner, Manager) “Add a New Employee” Append Server to the Create menu
    Gtk::MenuItem *menuitem_server = Gtk::manage(new Gtk::MenuItem("_Server...", true));
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
    //menuitem_about->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_about_click));
    helpmenu->append(*menuitem_about);

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    //     N E W   E M P O R I U M
    // Add a new game icon
    Gtk::ToolButton *new_emporium_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_emporium_button->set_tooltip_markup("Create a New Emporium");
    //new_emporium_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_new_emporium_click));
    toolbar->append(*new_emporium_button);

    //     Q U I T
    // Add a icon for quitting
    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit MICE");
    quit_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep);
    toolbar->append(*quit_button);

    // Make the box and everything in it visible
    vbox->show_all();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_quit_click() {
    hide();
}

void Mainwin::on_create_item_click() {

    // /////////////////////////////
    // Select Item Type
    Gtk::Dialog dialog_type{"Select Item Type", *this};
    //dialog_type.set_title("Select Item Type");
    const int WIDTH = 15;

    // Type
    Gtk::HBox b_type;

    Gtk::Label l_type{"Type:"};
    l_type.set_width_chars(WIDTH);
    b_type.pack_start(l_type, Gtk::PACK_SHRINK);

    // TODO: Replace this with 3 large, colorful buttons
    Gtk::ComboBoxText c_type;
    c_type.set_size_request(WIDTH*10);
    const int CONTAINER = 0;
    c_type.append("Container");
    const int SCOOP = 1;
    c_type.append("Ice Cream Flavor");
    const int TOPPING = 2;
    c_type.append("Topping");
    b_type.pack_start(c_type, Gtk::PACK_SHRINK);
    dialog_type.get_vbox()->pack_start(b_type, Gtk::PACK_SHRINK);

    // Show dialog_type
    dialog_type.add_button("Cancel", 0);
    dialog_type.add_button("OK", 1);
    dialog_type.show_all();
    if (dialog_type.run() != 1) return;

    int type = c_type.get_active_row_number();

    dialog_type.close();

    // //////////////////////////////
    // Define Item

    Gtk::Dialog dialog;
    if (type == CONTAINER) dialog.set_title("Create Container");
    else if (type == SCOOP) dialog.set_title("Create Flavor");
    else dialog.set_title("Create Topping");
    dialog.set_transient_for(*this);

    // Name 
    Gtk::HBox b_name;

    Gtk::Label l_name{"Name:"};
    l_name.set_width_chars(WIDTH);
    b_name.pack_start(l_name, Gtk::PACK_SHRINK);

    Gtk::Entry e_name;
    e_name.set_max_length(WIDTH*4);
    b_name.pack_start(e_name, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

    // TODO: Replace this with a Gtk::TextView inside a Gtk::ScrolledWindow
    // Description
    Gtk::HBox b_desc;

    Gtk::Label l_desc{"Description:"};
    l_desc.set_width_chars(WIDTH);
    b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);

    Gtk::Entry e_desc;
    e_desc.set_max_length(WIDTH*4);
    b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK);

    // Cost
    Gtk::HBox b_cost;

    Gtk::Label l_cost{"Cost:"};
    l_cost.set_width_chars(WIDTH);
    b_cost.pack_start(l_cost, Gtk::PACK_SHRINK);

    Gtk::Entry e_cost;
    e_cost.set_max_length(WIDTH*4);
    b_cost.pack_start(e_cost, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_cost, Gtk::PACK_SHRINK);

    // Price
    Gtk::HBox b_price;

    Gtk::Label l_price{"Price:"};
    l_price.set_width_chars(WIDTH);
    b_price.pack_start(l_price, Gtk::PACK_SHRINK);

    Gtk::Entry e_price;
    e_price.set_max_length(WIDTH*4);
    b_price.pack_start(e_price, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_price, Gtk::PACK_SHRINK);

    // Max Scoops (Container only)
    // TODO: TWILIGHT ZONE: Only works for "if" beside last line
    //       Check assembly - is this an optimizer bug?
    // if (type == CONTAINER) {
        Gtk::HBox b_max_scoops;

        Gtk::Label l_max_scoops{"Max Scoops:"};
        l_max_scoops.set_width_chars(WIDTH);
        b_max_scoops.pack_start(l_max_scoops, Gtk::PACK_SHRINK);

        Gtk::Entry e_max_scoops;
        e_max_scoops.set_max_length(WIDTH*4);
        b_max_scoops.pack_start(e_max_scoops, Gtk::PACK_SHRINK);
    if (type == CONTAINER) {
        dialog.get_vbox()->pack_start(b_max_scoops, Gtk::PACK_SHRINK);
    }

    // Show dialog
    dialog.add_button("Cancel", 0);
    dialog.add_button("OK", 1);
    dialog.show_all();
    if (dialog.run() != 1) return;

    bool valid_data = false;
    double d_cost;
    double d_price;
    int i_max_scoops;

    while(!valid_data) {
        valid_data = true;
        try {
            d_cost = std::stoi(e_cost.get_text());
        } catch(std::exception e) {
            e_cost.set_text("*** invalid cost ***");
            valid_data = false;
        }
        try {
            d_price = std::stoi(e_price.get_text());
        } catch(std::exception e) {
            e_price.set_text("*** invalid price ***");
            valid_data = false;
        }
        if (type == CONTAINER) {
            try {
                i_max_scoops = std::stoi(e_max_scoops.get_text());
            } catch(std::exception e) {
                e_max_scoops.set_text("*** invalid max scoops ***");
                valid_data = false;
            }
        }
    }
        
    // Instance item
    if (type == CONTAINER) {
        Mice::Container c{e_name.get_text(), e_desc.get_text(), d_cost, d_price, i_max_scoops};
        _containers.push_back(c);
    } else if (type == SCOOP) {
        _scoops.push_back(
            Mice::Scoop{e_name.get_text(), e_desc.get_text(), d_cost, d_price});
    } else {
        _toppings.push_back(
            Mice::Topping{e_name.get_text(), e_desc.get_text(), d_cost, d_price, 0});
    }
    
    dialog.close();
}

// void Mainwin::on_about_click() {
// }

// /////////////////
// U T I L I T I E S
// /////////////////

int Mainwin::select_container() {
    std::vector<std::string> names;
    for (Mice::Container c : _containers) names.push_back(c.name());
    return select_from_vector(names, "Container");
}

int Mainwin::select_scoop() {
    std::vector<std::string> names;
    for (Mice::Scoop s : _scoops) names.push_back(s.name());
    return select_from_vector(names, "Scoop");
}

int Mainwin::select_topping() {
    std::vector<std::string> names;
    for (Mice::Topping t : _toppings) names.push_back(t.name());
    return select_from_vector(names, "Topping");
}

int Mainwin::select_from_vector(std::vector<std::string> names, std::string title) {

    Gtk::Dialog dialog_index{"Select " + title, *this};
    const int WIDTH = 15;

    // Container
    Gtk::HBox b_index;

    Gtk::Label l_index{title + ":"};
    l_index.set_width_chars(WIDTH);
    b_index.pack_start(l_index, Gtk::PACK_SHRINK);

    // Create dropdown list
    Gtk::ComboBoxText c_index;
    c_index.set_size_request(WIDTH*10);
    for (std::string s : names) c_index.append(s);
    b_index.pack_start(c_index, Gtk::PACK_SHRINK);
    dialog_index.get_vbox()->pack_start(b_index, Gtk::PACK_SHRINK);

    // Show dialog_index
    dialog_index.add_button("Cancel", 0);
    dialog_index.add_button("OK", 1);
    dialog_index.show_all();
    if (dialog_index.run() != 1) return -1;

    int index = c_index.get_active_row_number();

    dialog_index.close();

    return index;
}

Mice::Serving Mainwin::create_serving() {
    int container = select_container();
    if (container == -1) throw std::runtime_error("Canceled");

    Mice::Serving serving{_containers[container]};

    bool has_no_scoops = true;
    for (int i=0; i<_containers[container].max_scoops(); ++i) {
        int scoop = select_scoop();
        if (scoop == -1) break;
        serving.add_scoop(_scoops[i]);
        has_no_scoops = false;
    }
    if (has_no_scoops) throw std::runtime_error("Canceled");

    while (true) {
        int topping = select_topping();
        if (topping = -1) break;
        else serving.add_topping(_toppings[topping]);
    }
    return serving;
}
