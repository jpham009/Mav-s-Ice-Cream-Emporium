#include "mainwin.h"


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

