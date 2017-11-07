#ifndef MAINWIN_H
#define MAINWIN_H

#include "container.h"
#include "scoop.h"
#include "topping.h"
#include "serving.h"
#include <gtkmm.h>
#include <string>
#include "dialogs.h"

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

        void on_button1_click();         // Select one stick from pile
        void on_button2_click();         // Select two sticks from pile
        void on_button3_click();         // Select three sticks from pile
		void on_new_order_click(); 
		///////////////TODO///////////////
		void menu_click();

		string containers_to_string();
		string scoops_to_string(); 
		string toppings_to_string(); 
		///////////////TODO///////////////
    


    private:
        //void create_order();                        // Create a new order
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

