#ifndef MAINWIN_H
#define MAINWIN_H

#include <exception>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "container.h"
#include "scoop.h"
#include "topping.h"
#include "serving.h"
#include <gtkmm.h>
#include <string>
#include "order.h"
#include "customer.h"
#include "server.h"
#include "manager.h"
#include "emporium.h"
#include "mainwin-orderwin.h"

static int WINDOW_COUNTER =1;
static int emp_count = 1;
static int order_counter = 1; //order numbers
static int fill_counter = 1; //track filled orders
static int customer_id = 10000; 
static int employee_id = 20000;
static int p_access{4};
static int p_index{4};
static std::string username;
static std::string role;
static int gallery_image = 0;

template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 2)
{
    std::ostringstream out;
    out << std::fixed << std::setprecision(n) << a_value;
    return out.str();
}

class Mainwin : public Gtk::Window
{
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        //void on_file_new_click();                   // Create a new Emporium
        void on_create_order_click();                 // Create a new order
        //void on_create_customer_click();            // Create a new customer
        void on_create_item_click();                  // Create a new item
        //void on_create_server_click();              // Create a new server
        void on_about_click();                        // Display About dialog
        void on_quit_click();                         // Exit the program
        void on_load_defaults_click();                    // Load Defaults
		void menu_click();
		std::string containers_to_string();
		std::string scoops_to_string(); 
		std::string toppings_to_string(); 
		Mice::Order create_order();  
		void status(std::string message); 

		void start();
		void logout();
		
		///////////////TODO///////////////
		void pending_orders();


		//Functions
		std::string customers_to_string();
		std::string managers_to_string();
		std::string servers_to_string();

		void on_list_customers(); 
		void on_list_employees();
	
		void easter_egg(); // load test persons

		void add_new_customer();	
		void add_new_server();
		void add_new_manager(); 

		double balance();
		double money_in();
		double money_out();
		double profit();

		void on_add_server_click();
		void on_add_customer_click();
		void on_money_click(); 
	
		void on_restock_click();

		vector<int> login();
		void fill_order(Mice::Order order);
		void restock();
	void on_order_screen_click();
		void on_fill_order_click(); 
void on_file_open_click(); 
void on_file_save_click();

void order_window();

//TODO
std::vector<int> _pending;
std::vector<std::string> _pendingstring;

void clickrefresh();


//TODO

void gallery();
//menuwin
Orderwin *winwin;
Gtk::Dialog *menuwin;
std::vector <std::string> _pic_strings;

std::vector <std::string> _itemdescriptions;
std::vector <std::string> _itemnames;
	std::vector <Gtk::Image*> _gallery;
	Gtk::Button *left_button;
	Gtk::Button *right_button;
	Gtk::Image *itemimage; 
Gtk::Label *itemlabel;
Gtk::Label *itemtitle;
Gtk::VBox *itembox;
Gtk::HBox *picbox;




void menu_window_next();
void menu_window_prev();

//TODO

	//Restock Variables
	Gtk::Dialog *restockdialog;
	Gtk::HBox *hb_all;
	Gtk::VBox *vb_containers;
	Gtk::VBox *vb_scoops;
	Gtk::VBox *vb_toppings;
	Gtk::Label *l_container;
	Gtk::Grid *grid_container;
	Gtk::Label *name_container;
	Gtk::Label *quantity_container; 
	Gtk::Label *l_scoop;
	Gtk::Grid *grid_scoop; 
	Gtk::Label *name_scoop;
	Gtk::Label *quantity_scoop;
	Gtk::Label *l_topping;
	Gtk::Grid *grid_topping;
	Gtk::Label *name_topping;
	Gtk::Label *quantity_topping;

	vector <Gtk::Label*> q_scoop_vector;
	vector <Gtk::Label*> q_container_vector;
	vector <Gtk::Label*> q_topping_vector;

	
//

void add_manager();



		std::vector<int> _scoop_selection;
		std::vector<int> _container_selection;
		std::vector<int> _topping_selection;

		double _balance{1000};
		double _money_in{0};
		double _money_out{0};
		double _profit{0};

	std::string name_s;
	std::string order_s;
Gtk::Label *name_m;
		Gtk::Label *order_m;		
		///////////////TODO///////////////
    


    private:


		
        Mice::Emporium* _emp;                          // Currently active emporium	
		void save_emporium();
	
        Mice::Serving create_serving();               // Create a new serving
        int select_container();                       // Select a container index
        int select_scoop();                           // Select a scoop index
        int select_topping();                         // Select a container index
        int select_from_vector
            (std::vector<std::string> names, 
             std::string title);                      // Select from a list of strings


		Gtk::Image *new_order_image;   
		Gtk::Image *add_customer_image;
		Gtk::Image *add_server_image;
		Gtk::Image *money_image;
		Gtk::Image *list_customers_image;
		Gtk::Image *list_servers_image;
		Gtk::Image *menu_image;
		Gtk::Image *pending_image;
		Gtk::Image *menuwin_image;
		
};
#endif 

