#include "mainwin.h"

vector<int> Mainwin::login() {//return {list, index}

    Gtk::Dialog dialog("Login");
	dialog.override_background_color(Gdk::RGBA("#f7f7f7"));
 	dialog.set_default_size(575, 200);
	dialog.set_position(Gtk::WIN_POS_CENTER);
	dialog.set_transient_for(*this);
    const int WIDTH = 20;
	Gtk::VBox mainbox;
	dialog.get_vbox()->set_halign(Gtk::ALIGN_CENTER);
	dialog.get_vbox()->override_background_color(Gdk::RGBA("#f7f7f7"));
	dialog.get_vbox()->pack_start(mainbox);
	Gtk::Image logo("order_logo.png");
	mainbox.pack_start(logo);
	mainbox.set_halign(Gtk::ALIGN_CENTER);
	mainbox.override_background_color(Gdk::RGBA("#f7f7f7"));
	mainbox.set_margin_left(50);
	mainbox.set_margin_right(50);
	mainbox.set_margin_top(50);
	mainbox.set_margin_bottom(50);
	
	//buttons
	Gtk::Button b_cancel("Cancel");
	Gtk::Button b_login("Login");
	Gtk::Button b_guest("Guest Login");
	dialog.add_action_widget(b_guest,2); 
	dialog.add_action_widget(b_cancel,0);
	dialog.add_action_widget(b_login,1);	
	b_guest.set_halign(Gtk::ALIGN_START);
	b_guest.set_margin_bottom(50);
	b_guest.set_margin_right(175);
	b_cancel.set_margin_bottom(50);
	b_cancel.set_halign(Gtk::ALIGN_END);
	b_login.set_margin_bottom(50);
	b_login.set_margin_right(50);
	b_login.set_halign(Gtk::ALIGN_END);
	b_login.set_can_default(true);
	b_login.grab_default();
	dialog.set_default(b_login);

 	// Name 
    Gtk::HBox b_username;
	b_username.set_halign(Gtk::ALIGN_CENTER);
    Gtk::Label l_username("Username:");
    l_username.set_width_chars(WIDTH);
    b_username.pack_start(l_username, Gtk::PACK_SHRINK);
	

    Gtk::Entry e_username;
    e_username.set_max_length(WIDTH*4);
    b_username.pack_start(e_username, Gtk::PACK_SHRINK);
	mainbox.pack_start(b_username, Gtk::PACK_SHRINK);
	e_username.set_activates_default(true);
	e_username.set_text("OWNER1325");
    // Phone
    Gtk::HBox b_userpassword;
	b_userpassword.set_halign(Gtk::ALIGN_CENTER);
	b_userpassword.set_margin_bottom(15);

    Gtk::Label l_userpassword("Password:");
    l_userpassword.set_width_chars(WIDTH);
    b_userpassword.pack_start(l_userpassword, Gtk::PACK_SHRINK);

    Gtk::Entry e_userpassword;
    e_userpassword.set_max_length(WIDTH*4);
    b_userpassword.pack_start(e_userpassword, Gtk::PACK_SHRINK);
	e_userpassword.set_text("********");
	e_userpassword.set_sensitive(false);
    mainbox.pack_start(b_userpassword, Gtk::PACK_SHRINK);

	Gtk::Label l_invalid;
	l_invalid.set_markup(" ");
	mainbox.pack_start(l_invalid, Gtk::PACK_SHRINK); 

    // Show dialog
    dialog.show_all();
	
	//login vector
	std::vector<int> login_vector;
	
	int result;
	while(true){
		result = dialog.run();
		if(result == 1){
			if(e_username.get_text() == "OWNER1325"){
				login_vector.push_back(0); login_vector.push_back(0);
				return login_vector;	
			} 
			for(int i = 0; i < _emp->num_managers(); i++){
				if(_emp->manager(i).name() == e_username.get_text()){
					login_vector.push_back(1); login_vector.push_back(i);
					return login_vector;
				}
			}
			for(int i = 0; i < _emp->num_servers(); i++){
				if(_emp->server(i).name() == e_username.get_text()){
					login_vector.push_back(2); login_vector.push_back(i);
					return login_vector;
				}
			}	
			for(int i = 0; i < _emp->num_customers(); i++){
				if(_emp->customer(i).name() == e_username.get_text()){
					login_vector.push_back(3); login_vector.push_back(i);
					return login_vector;
				}
			}
	
			l_invalid.set_markup("<span color='red'>Invalid username/password</span>");
		}
		else if(result == 2){
			login_vector.push_back(9);login_vector.push_back(9);
			return login_vector;
		}
		else{
			dialog.close();
			close();
			break;
		}
	}
  
}
    
