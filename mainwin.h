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
#include "dialogs.h"
#include "order.h"
#include "customer.h"
#include "server.h"
#include "manager.h"


static int order_counter = 1; //order numbers
static int fill_counter = 1; //track filled orders
static int customer_id = 10000; 
static int employee_id = 20000;

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


		
		///////////////TODO///////////////



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

		void on_fill_order_click(); 





		//Variables
		std::vector<Mice::Order> _orders;
		std::vector<Mice::Manager> _managers;
		std::vector<Mice::Server> _servers;
		std::vector<Mice::Customer> _customers; 
		
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
                             						 // Create a new order
        Mice::Serving create_serving();               // Create a new serving
        int select_container();                       // Select a container index
        int select_scoop();                           // Select a scoop index
        int select_topping();                         // Select a container index
        int select_from_vector
            (std::vector<std::string> names, 
             std::string title);                      // Select from a list of strings

        std::vector<Mice::Container> _containers;     // All defined containers
        std::vector<Mice::Scoop> _scoops;             // All defined scoops
        std::vector<Mice::Topping> _toppings;         // All defined toppings
        std::vector<Mice::Serving> _servings;         // All defined servings		

		Gtk::Image *new_order_image;   
		Gtk::Image *add_customer_image;
		Gtk::Image *add_server_image;
		Gtk::Image *money_image;
		Gtk::Image *list_customers_image;
		Gtk::Image *list_servers_image;
		Gtk::Image *menu_image;
		
};
#endif 

