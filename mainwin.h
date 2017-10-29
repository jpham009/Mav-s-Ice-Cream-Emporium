#ifndef MAINWIN_H
#define MAINWIN_H

#include <gtkmm.h>

class Mainwin : public Gtk::Window
{
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        //void on_file_new_click();             // Create a new Emporium
        //void on_create_order_click();         // Create a new order
        //void on_create_customer_click();      // Create a new customer
        void on_create_item_click();          // Create a new item
        //void on_create_server_click();        // Create a new server
        //void on_about_click();                // Display About dialog
        void on_quit_click();                 // Exit the program
    private:
        //void create_order();                  // Create a new order
        //Serving create_serving();             // Create a new serving
        //Container select_container();         // Select a container
        //Scoop select_scoop();                 // Select a scoop
        //Topping select_topping();             // Select a container
};
#endif 

