#include "mainwin.h"


void Mainwin::gallery(){
	_pic_strings.clear();
	_gallery.clear();
	_itemdescriptions.clear();
	_itemnames.clear(); 

	menuwin = new Gtk::Dialog("Menu");
	menuwin->set_default_size(425,425);
	itembox = Gtk::manage(new Gtk::VBox());
	picbox = Gtk::manage(new Gtk::HBox());
	menuwin->set_transient_for(*this);
	menuwin->get_vbox()->pack_start(*itembox, Gtk::PACK_EXPAND_WIDGET); 
			
	_pic_strings.push_back("_chocolate.jpg");
	_pic_strings.push_back("_vanilla.jpg");
	_pic_strings.push_back("_strawberry.jpg");
	_pic_strings.push_back("_mintchocolatechip.jpg");
	_pic_strings.push_back("_rockyroad.jpg");
	_pic_strings.push_back("_neapolitan.jpg");
	_pic_strings.push_back("_rainbowsherbet.jpg");
	_pic_strings.push_back("_cherryamaretto.jpg");
	_pic_strings.push_back("_sugarcone.jpg");
	_pic_strings.push_back("_wafflecone.jpg");
	_pic_strings.push_back("_cakecone.jpg");
	_pic_strings.push_back("_cup.jpg");
	_pic_strings.push_back("_chocolatesyrup.jpg");
	_pic_strings.push_back("_caramelsyrup.jpg");
	_pic_strings.push_back("_cherry.jpg");
	_pic_strings.push_back("_sprinkles.jpg");

	std::string s_item; 
	for(int i = 0; i < 8; i++){ 
		_itemnames.push_back(_emp->scoop(i).name());
		_itemdescriptions.push_back(_emp->scoop(i).description());
	}
	for(int i = 0; i < 4; i++){ 
		_itemnames.push_back(_emp->container(i).name());
		_itemdescriptions.push_back(_emp->container(i).description());
	}
	for(int i = 0; i < 4; i++){ 
		_itemnames.push_back(_emp->topping(i).name());
		_itemdescriptions.push_back(_emp->topping(i).description());
	}
	
	Gtk::Button *left_button = Gtk::manage(new Gtk::Button("<"));
	itemimage = Gtk::manage(new Gtk::Image());
	Gtk::Button *right_button = Gtk::manage(new Gtk::Button(">"));

	itembox->pack_start(*picbox);
	itemtitle = Gtk::manage(new Gtk::Label()); 
	itemlabel = Gtk::manage(new Gtk::Label());
	itembox->pack_start(*itemtitle);
	itembox->pack_start(*itemlabel); 
	
	picbox->set_halign(Gtk::ALIGN_CENTER);
	picbox->set_valign(Gtk::ALIGN_CENTER);
	picbox->pack_start(*left_button);
	picbox->pack_start(*itemimage, Gtk::PACK_SHRINK);
	picbox->pack_end(*right_button, Gtk::PACK_SHRINK); 
	left_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::menu_window_prev));
	right_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::menu_window_next));
	itemimage->set(_pic_strings[gallery_image]);
	itemtitle->set_markup("<span weight='bold'>" + _itemnames[gallery_image] + "</span>");
	itemlabel->set_markup(_itemdescriptions[gallery_image]);
	itemlabel->set_line_wrap(true);
		
	menuwin->show_all();
	menuwin->run();
	menuwin->close();

}

void Mainwin::menu_window_next(){
	if(gallery_image == 16) gallery_image = 0;
	itemimage->set(_pic_strings[gallery_image]);
	itemtitle->set_markup("<span weight='bold'>" + _itemnames[gallery_image] + "</span>");
	itemlabel->set_markup(_itemdescriptions[gallery_image]);
	gallery_image++;

}

void Mainwin::menu_window_prev(){
	if(gallery_image == -1) gallery_image = 15;
	itemimage->set(_pic_strings[gallery_image]);
	itemtitle->set_markup("<span weight='bold'>" + _itemnames[gallery_image] + "</span>");
	itemlabel->set_markup(_itemdescriptions[gallery_image]);
	gallery_image--;

}
