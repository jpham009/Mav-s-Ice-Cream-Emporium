#ifndef MAINWIN_H
#define MAINWIN_H

#include "container.h"
#include "scoop.h"
#include "topping.h"
#include "serving.h"
#include <gtkmm.h>
#include <string>

class Mainwin : public Gtk::Window
{
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        //void on_file_new_click();                   // Create a new Emporium
        //void on_create_order_click();               // Create a new order
        //void on_create_customer_click();            // Create a new customer
        void on_create_item_click();                  // Create a new item
        //void on_create_server_click();              // Create a new server
        //void on_about_click();                      // Display About dialog
        void on_quit_click();                         // Exit the program
    private:
        //void create_order();                        // Create a new order
        Mice::Serving create_serving();             // Create a new serving
        int select_container();                       // Select a container index
        int select_scoop();                           // Select a scoop
        int select_topping();                         // Select a container
        int select_from_vector
            (std::vector<std::string> names, 
             std::string title);                      // Select from a list of strings

        std::vector<Mice::Container> _containers;     // All defined containers
        std::vector<Mice::Scoop> _scoops;             // All defined scoops
        std::vector<Mice::Topping> _toppings;         // All defined toppings
};
#endif 

