#include "mainwin.h"
#include <iostream>
#include <sstream>
#include <vector>

void Mainwin::order_window(){	



orderwindow.set_default_size(1000,800);
orderwindow.set_border_width(20);


orderwindow.get_vbox()->pack_start(mainbox);
mainbox.set_homogeneous(true);


///



//
levelbox1.set_homogeneous(true);
levelbox2.set_homogeneous(true);
	rowbox1.set_border_width(5);
	rowbox2.set_border_width(5);
	rowbox3.set_border_width(5);
	rowbox4.set_border_width(5);
	rowbox5.set_border_width(5);
	rowbox6.set_border_width(5);


	frame1.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
	frame2.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
	frame3.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
	frame4.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
	frame5.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
	frame6.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);





	button1.set_halign(Gtk::ALIGN_END);
	button2.set_halign(Gtk::ALIGN_END);
	button3.set_halign(Gtk::ALIGN_END);
	button4.set_halign(Gtk::ALIGN_END);
	button5.set_halign(Gtk::ALIGN_END);
	button6.set_halign(Gtk::ALIGN_END);
	button1.set_valign(Gtk::ALIGN_END);
	button2.set_valign(Gtk::ALIGN_END);
	button3.set_valign(Gtk::ALIGN_END);
	button4.set_valign(Gtk::ALIGN_END);
	button5.set_valign(Gtk::ALIGN_END);
	button6.set_valign(Gtk::ALIGN_END);
	button1.set_border_width(10);
	button2.set_border_width(10);
	button3.set_border_width(10);
	button4.set_border_width(10);
	button5.set_border_width(10);
	button6.set_border_width(10);

//


	Gtk::ScrolledWindow scroll1;
	Gtk::ScrolledWindow scroll2;
	Gtk::ScrolledWindow scroll3;
	Gtk::ScrolledWindow scroll4;
	Gtk::ScrolledWindow scroll5;
	Gtk::ScrolledWindow scroll6;

	scroll1.set_border_width(3);	
	scroll2.set_border_width(3);	
	scroll3.set_border_width(3);	
	scroll4.set_border_width(3);	
	scroll5.set_border_width(3);	
	scroll6.set_border_width(3);	



	scroll1.add(inner2box1);
	scroll2.add(inner2box2);
	scroll3.add(inner2box3);
	scroll4.add(inner2box4);
	scroll5.add(inner2box5);
	scroll6.add(inner2box6);

inner2box1.pack_end(button1);
inner2box2.pack_end(button2);
inner2box3.pack_end(button3);
inner2box4.pack_end(button4);
inner2box5.pack_end(button5);
inner2box6.pack_end(button6);
	
	//functions
	button1.signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::click1));
	button2.signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::click2));
	button3.signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::click3));
	button4.signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::click4));
	button5.signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::click5));
	button6.signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::click6));


	innerbox1.pack_end(scroll1); 
	innerbox2.pack_end(scroll2); 
	innerbox3.pack_end(scroll3); 
	innerbox4.pack_end(scroll4); 
	innerbox5.pack_end(scroll5); 
	innerbox6.pack_end(scroll6); 

std::string s1 = "Order #";
std::string s2 = "Order #";
std::string s3 = "Order #";
std::string s4 = "Order #";
std::string s5 = "Order #";
std::string s6 = "Order #";

	_pendingstring.push_back(s1);
	_pendingstring.push_back(s2);
	_pendingstring.push_back(s3);
	_pendingstring.push_back(s4);
	_pendingstring.push_back(s5);
	_pendingstring.push_back(s6);

for (int i = 0; i < _pending.size(); i++){
	_pendingstring[i] += std::to_string(_pending[i]);
}


//_pending

	label1.set_markup(_pendingstring[0]);
	label2.set_markup(_pendingstring[1]);
	label3.set_markup(_pendingstring[2]);
	label4.set_markup(_pendingstring[3]);
	label5.set_markup(_pendingstring[4]);
	label6.set_markup(_pendingstring[5]);

	inner2box1.pack_start(label1, Gtk::PACK_SHRINK);	
	inner2box2.pack_start(label2, Gtk::PACK_SHRINK);	
	inner2box3.pack_start(label3, Gtk::PACK_SHRINK);	
	inner2box4.pack_start(label4, Gtk::PACK_SHRINK);	
	inner2box5.pack_start(label5, Gtk::PACK_SHRINK);	
	inner2box6.pack_start(label6, Gtk::PACK_SHRINK);	

	innerbox1.set_margin_top(15);
	innerbox2.set_margin_top(15);
	innerbox3.set_margin_top(15);
	innerbox4.set_margin_top(15);
	innerbox5.set_margin_top(15);
	innerbox6.set_margin_top(15);

	frame1.add(innerbox1);
	frame2.add(innerbox2);
	frame3.add(innerbox3);
	frame4.add(innerbox4);
	frame5.add(innerbox5);
	frame6.add(innerbox6);

	rowbox1.pack_start(frame1);
	rowbox2.pack_start(frame2);
	rowbox3.pack_start(frame3);
	rowbox4.pack_start(frame4);
	rowbox5.pack_start(frame5);
	rowbox6.pack_start(frame6);

	levelbox1.pack_start(rowbox1);
	levelbox1.pack_start(rowbox2);
	levelbox1.pack_start(rowbox3);
	levelbox2.pack_start(rowbox4);
	levelbox2.pack_start(rowbox5);
	levelbox2.pack_start(rowbox6);

	mainbox.pack_start(levelbox1);
	mainbox.pack_start(levelbox2);//


	refresh_button.signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::clickrefresh));
	mainbox.pack_end(refresh_button, Gtk::PACK_SHRINK);












orderwindow.show_all();
orderwindow.run();

}


void Mainwin::click1(){
	button1.set_sensitive(false);
	
	button1.set_label("Filled");
button1.override_background_color(Gdk::RGBA("#ff4f4f"));

//inner2box1.remove(button1);dope ass shit
//levelbox1.remove(rowbox1);
	return;
}
void Mainwin::click2(){
	button2.set_sensitive(false);
	button2.set_label("Filled");
	return;
}
void Mainwin::click3(){
	button3.set_sensitive(false);
	button3.set_label("Filled");
	return;
}
void Mainwin::click4(){
	button4.set_sensitive(false);
	button4.set_label("Filled");
	return;
}
void Mainwin::click5(){
	button5.set_sensitive(false);
	button5.set_label("Filled");
	return;
}
void Mainwin::click6(){
	button6.set_sensitive(false);
	button6.set_label("Filled");
	return;
}
void Mainwin::clickrefresh(){		
	orders_pending();
}

void Mainwin::orders_pending(){

for(int i = 0; i < _orders.size(); i++){
	if(_orders[i].state() == false){//check
		_pending.push_back(_orders[i].get_order_number()); 
	}
}

}



