#include "mainwin-orderwin.h"

static int WINCOUNT = 1;

Orderwin::Orderwin(){

mainbox = Gtk::manage(new Gtk::VBox());
levelbox1 = Gtk::manage(new Gtk::HBox());
levelbox2 = Gtk::manage(new Gtk::HBox());

button1 = Gtk::manage(new Gtk::Button());
button2 = Gtk::manage(new Gtk::Button());
button3 = Gtk::manage(new Gtk::Button());
button4 = Gtk::manage(new Gtk::Button());
button5 = Gtk::manage(new Gtk::Button());
button6 = Gtk::manage(new Gtk::Button());

cancel_button1 = Gtk::manage(new Gtk::Button());
cancel_button2 = Gtk::manage(new Gtk::Button());
cancel_button3 = Gtk::manage(new Gtk::Button());
cancel_button4 = Gtk::manage(new Gtk::Button());
cancel_button5 = Gtk::manage(new Gtk::Button());
cancel_button6 = Gtk::manage(new Gtk::Button());


refresh_button = Gtk::manage(new Gtk::Button());
innerbox1 = Gtk::manage(new Gtk::VBox());
innerbox2 = Gtk::manage(new Gtk::VBox());
innerbox3 = Gtk::manage(new Gtk::VBox());
innerbox4 = Gtk::manage(new Gtk::VBox());
innerbox5 = Gtk::manage(new Gtk::VBox());
innerbox6 = Gtk::manage(new Gtk::VBox());

inner2box1 = Gtk::manage(new Gtk::VBox());
inner2box2 = Gtk::manage(new Gtk::VBox());
inner2box3 = Gtk::manage(new Gtk::VBox());
inner2box4 = Gtk::manage(new Gtk::VBox());
inner2box5 = Gtk::manage(new Gtk::VBox());
inner2box6 = Gtk::manage(new Gtk::VBox());
inner3box1 = Gtk::manage(new Gtk::HBox());
inner3box2 = Gtk::manage(new Gtk::HBox());
inner3box3 = Gtk::manage(new Gtk::HBox());
inner3box4 = Gtk::manage(new Gtk::HBox());
inner3box5 = Gtk::manage(new Gtk::HBox());
inner3box6 = Gtk::manage(new Gtk::HBox());
scroll1 = Gtk::manage(new Gtk::ScrolledWindow());
scroll2 = Gtk::manage(new Gtk::ScrolledWindow());
scroll3 = Gtk::manage(new Gtk::ScrolledWindow());
scroll4 = Gtk::manage(new Gtk::ScrolledWindow());
scroll5 = Gtk::manage(new Gtk::ScrolledWindow());
scroll6 = Gtk::manage(new Gtk::ScrolledWindow());

frame1 = Gtk::manage(new Gtk::Frame());
frame2 = Gtk::manage(new Gtk::Frame());
frame3 = Gtk::manage(new Gtk::Frame());
frame4 = Gtk::manage(new Gtk::Frame());
frame5 = Gtk::manage(new Gtk::Frame());
frame6 = Gtk::manage(new Gtk::Frame());

slabel1 = Gtk::manage(new Gtk::Label());
slabel2 = Gtk::manage(new Gtk::Label());
slabel3 = Gtk::manage(new Gtk::Label());
slabel4 = Gtk::manage(new Gtk::Label());
slabel5 = Gtk::manage(new Gtk::Label());
slabel6 = Gtk::manage(new Gtk::Label());

label1 = Gtk::manage(new Gtk::Label());
label2 = Gtk::manage(new Gtk::Label());
label3 = Gtk::manage(new Gtk::Label());
label4 = Gtk::manage(new Gtk::Label());
label5 = Gtk::manage(new Gtk::Label());
label6 = Gtk::manage(new Gtk::Label());

rowbox1 = Gtk::manage(new Gtk::VBox());
rowbox2 = Gtk::manage(new Gtk::VBox());
rowbox3 = Gtk::manage(new Gtk::VBox());
rowbox4 = Gtk::manage(new Gtk::VBox());
rowbox5 = Gtk::manage(new Gtk::VBox());
rowbox6 = Gtk::manage(new Gtk::VBox());




set_transient_for(*this);


//refreshing screen
button1->set_label("Fill");
button2->set_label("Fill");
button3->set_label("Fill");
button4->set_label("Fill");
button5->set_label("Fill");
button6->set_label("Fill");
cancel_button1->set_label("Cancel");
cancel_button2->set_label("Cancel");
cancel_button3->set_label("Cancel");
cancel_button4->set_label("Cancel");
cancel_button5->set_label("Cancel");
cancel_button6->set_label("Cancel");
button1->set_sensitive(true);
button2->set_sensitive(true);
button3->set_sensitive(true);
button4->set_sensitive(true);
button5->set_sensitive(true);
button6->set_sensitive(true);
cancel_button1->set_sensitive(true);
cancel_button2->set_sensitive(true);
cancel_button3->set_sensitive(true);
cancel_button4->set_sensitive(true);
cancel_button5->set_sensitive(true);
cancel_button6->set_sensitive(true);




//TODO


set_default_size(1000,800);
set_border_width(5);
get_vbox()->pack_start(*mainbox);

mainbox->set_homogeneous(true);

levelbox1->set_homogeneous(true);
levelbox2->set_homogeneous(true);

rowbox1->set_border_width(5);
rowbox2->set_border_width(5);
rowbox3->set_border_width(5);
rowbox4->set_border_width(5);
rowbox5->set_border_width(5);
rowbox6->set_border_width(5);

frame1->set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
frame2->set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
frame3->set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
frame4->set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
frame5->set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
frame6->set_shadow_type(Gtk::SHADOW_ETCHED_OUT);

button1->set_halign(Gtk::ALIGN_END);
button2->set_halign(Gtk::ALIGN_END);
button3->set_halign(Gtk::ALIGN_END);
button4->set_halign(Gtk::ALIGN_END);
button5->set_halign(Gtk::ALIGN_END);
button6->set_halign(Gtk::ALIGN_END);
button1->set_valign(Gtk::ALIGN_END);
button2->set_valign(Gtk::ALIGN_END);
button3->set_valign(Gtk::ALIGN_END);
button4->set_valign(Gtk::ALIGN_END);
button5->set_valign(Gtk::ALIGN_END);
button6->set_valign(Gtk::ALIGN_END);
button1->set_margin_right(3);
button2->set_margin_right(3);
button3->set_margin_right(3);
button4->set_margin_right(3);
button5->set_margin_right(3);
button6->set_margin_right(3);
button1->set_margin_bottom(3);
button2->set_margin_bottom(3);
button3->set_margin_bottom(3);
button4->set_margin_bottom(3);
button5->set_margin_bottom(3);
button6->set_margin_bottom(3);


cancel_button1->set_halign(Gtk::ALIGN_END);
cancel_button2->set_halign(Gtk::ALIGN_END);
cancel_button3->set_halign(Gtk::ALIGN_END);
cancel_button4->set_halign(Gtk::ALIGN_END);
cancel_button5->set_halign(Gtk::ALIGN_END);
cancel_button6->set_halign(Gtk::ALIGN_END);
cancel_button1->set_valign(Gtk::ALIGN_END);
cancel_button2->set_valign(Gtk::ALIGN_END);
cancel_button3->set_valign(Gtk::ALIGN_END);
cancel_button4->set_valign(Gtk::ALIGN_END);
cancel_button5->set_valign(Gtk::ALIGN_END);
cancel_button6->set_valign(Gtk::ALIGN_END);
cancel_button1->set_margin_bottom(3);
cancel_button2->set_margin_bottom(3);
cancel_button3->set_margin_bottom(3);
cancel_button4->set_margin_bottom(3);
cancel_button5->set_margin_bottom(3);
cancel_button6->set_margin_bottom(3);

scroll1->set_border_width(3);	
scroll2->set_border_width(3);	
scroll3->set_border_width(3);	
scroll4->set_border_width(3);	
scroll5->set_border_width(3);	
scroll6->set_border_width(3);	

scroll1->add(*inner2box1);
scroll2->add(*inner2box2);
scroll3->add(*inner2box3);
scroll4->add(*inner2box4);
scroll5->add(*inner2box5);
scroll6->add(*inner2box6);

inner3box1->pack_end(*button1,Gtk::PACK_SHRINK);
inner3box2->pack_end(*button2,Gtk::PACK_SHRINK);
inner3box3->pack_end(*button3,Gtk::PACK_SHRINK);
inner3box4->pack_end(*button4,Gtk::PACK_SHRINK);
inner3box5->pack_end(*button5,Gtk::PACK_SHRINK);
inner3box6->pack_end(*button6,Gtk::PACK_SHRINK);

inner3box1->pack_end(*cancel_button1, Gtk::PACK_SHRINK);
inner3box2->pack_end(*cancel_button2, Gtk::PACK_SHRINK);
inner3box3->pack_end(*cancel_button3, Gtk::PACK_SHRINK);
inner3box4->pack_end(*cancel_button4, Gtk::PACK_SHRINK);
inner3box5->pack_end(*cancel_button5, Gtk::PACK_SHRINK);
inner3box6->pack_end(*cancel_button6, Gtk::PACK_SHRINK);
	
inner2box1->pack_start(*label1, Gtk::PACK_SHRINK);	
inner2box2->pack_start(*label2, Gtk::PACK_SHRINK);	
inner2box3->pack_start(*label3, Gtk::PACK_SHRINK);	
inner2box4->pack_start(*label4, Gtk::PACK_SHRINK);	
inner2box5->pack_start(*label5, Gtk::PACK_SHRINK);	
inner2box6->pack_start(*label6, Gtk::PACK_SHRINK);		

inner2box1->pack_start(*slabel1);
inner2box2->pack_start(*slabel2);
inner2box3->pack_start(*slabel3);
inner2box4->pack_start(*slabel4);
inner2box5->pack_start(*slabel5);
inner2box6->pack_start(*slabel6);

inner2box1->pack_end(*inner3box1, Gtk::PACK_SHRINK);
inner2box2->pack_end(*inner3box2, Gtk::PACK_SHRINK);
inner2box3->pack_end(*inner3box3, Gtk::PACK_SHRINK);
inner2box4->pack_end(*inner3box4, Gtk::PACK_SHRINK);
inner2box5->pack_end(*inner3box5, Gtk::PACK_SHRINK);
inner2box6->pack_end(*inner3box6, Gtk::PACK_SHRINK);

//functions
button1->signal_clicked().connect(sigc::mem_fun(*this, &Orderwin::click1));
button2->signal_clicked().connect(sigc::mem_fun(*this, &Orderwin::click2));
button3->signal_clicked().connect(sigc::mem_fun(*this, &Orderwin::click3));
button4->signal_clicked().connect(sigc::mem_fun(*this, &Orderwin::click4));
button5->signal_clicked().connect(sigc::mem_fun(*this, &Orderwin::click5));
button6->signal_clicked().connect(sigc::mem_fun(*this, &Orderwin::click6));

cancel_button1->signal_clicked().connect(sigc::mem_fun(*this, &Orderwin::cancel1));
cancel_button2->signal_clicked().connect(sigc::mem_fun(*this, &Orderwin::cancel2));
cancel_button3->signal_clicked().connect(sigc::mem_fun(*this, &Orderwin::cancel3));
cancel_button4->signal_clicked().connect(sigc::mem_fun(*this, &Orderwin::cancel4));
cancel_button5->signal_clicked().connect(sigc::mem_fun(*this, &Orderwin::cancel5));
cancel_button6->signal_clicked().connect(sigc::mem_fun(*this, &Orderwin::cancel6));

innerbox1->pack_end(*scroll1); 
innerbox2->pack_end(*scroll2); 
innerbox3->pack_end(*scroll3); 
innerbox4->pack_end(*scroll4); 
innerbox5->pack_end(*scroll5); 
innerbox6->pack_end(*scroll6); 

innerbox1->set_margin_top(10);
innerbox2->set_margin_top(10);
innerbox3->set_margin_top(10);
innerbox4->set_margin_top(10);
innerbox5->set_margin_top(10);
innerbox6->set_margin_top(10);

frame1->add(*innerbox1);
frame2->add(*innerbox2);
frame3->add(*innerbox3);
frame4->add(*innerbox4);
frame5->add(*innerbox5);
frame6->add(*innerbox6);

rowbox1->pack_start(*frame1);
rowbox2->pack_start(*frame2);
rowbox3->pack_start(*frame3);
rowbox4->pack_start(*frame4);
rowbox5->pack_start(*frame5);
rowbox6->pack_start(*frame6);

levelbox1->pack_start(*rowbox1);
levelbox1->pack_start(*rowbox2);
levelbox1->pack_start(*rowbox3);
levelbox2->pack_start(*rowbox4);
levelbox2->pack_start(*rowbox5);
levelbox2->pack_start(*rowbox6);

mainbox->pack_start(*levelbox1);
mainbox->pack_start(*levelbox2);
//refresh_button->set_valign(Gtk::ALIGN_END);
//refresh_button->set_halign(Gtk::ALIGN_END);

//refresh_button->signal_clicked()->connect(sigc::mem_fun(*this, &Orderwin::clickrefresh));
innerbox1->show();
innerbox2->show();
innerbox3->show();
innerbox4->show();
innerbox5->show();
innerbox6->show();

button1->show();
button2->show(); 
button3->show(); 
button4->show(); 
button5->show(); 
button6->show();  

scroll1->show();
scroll2->show();
scroll3->show();
scroll4->show();
scroll5->show();
scroll6->show();

frame1->show();
frame2->show();
frame3->show();
frame4->show();
frame5->show();
frame6->show();

rowbox1->show();
rowbox2->show();
rowbox3->show();
rowbox4->show();
rowbox5->show();
rowbox6->show();

levelbox1->show();
levelbox2->show();
mainbox->show();




}


Orderwin::~Orderwin(){}

void Orderwin::click1(){
	fill_order1();
	button1->set_sensitive(false);
	button1->hide();
	cancel_button1->hide();
	slabel1->set_sensitive(false);
	set_slabel1("<span color='green' weight='bold' font='20'>- Order #" + get_order1() + " -</span><span color='green' weight='bold' font='20'>\n\n   READY!</span>");
	slabel1->set_alignment(Gtk::ALIGN_CENTER, Gtk::ALIGN_CENTER);
	return;
}
void Orderwin::click2(){
	fill_order2();
	cancel_button2->hide();
	button2->hide();
	slabel2->set_sensitive(false);
	set_slabel2("<span color='green' weight='bold' font='20'>- Order #" + get_order2() + " -</span><span color='green' weight='bold' font='20'>\n\n   READY!</span>");
	slabel2->set_alignment(Gtk::ALIGN_CENTER, Gtk::ALIGN_CENTER);
	return;
}
void Orderwin::click3(){
	fill_order3();
	button3->set_sensitive(false);
	cancel_button3->hide();
	button3->set_label("FILLED");
	slabel3->set_sensitive(false);
	set_slabel3("<span color='green' weight='bold' font='20'>- Order #" + get_order3() + " -</span><span color='green' weight='bold' font='20'>\n\n   READY!</span>");
	slabel3->set_alignment(Gtk::ALIGN_CENTER, Gtk::ALIGN_CENTER);
	return;
}
void Orderwin::click4(){
	fill_order4();
	button4->set_sensitive(false);
	cancel_button4->hide();
	button4->set_label("FILLED");
	slabel4->set_sensitive(false);
	set_slabel4("<span color='green' weight='bold' font='20'>- Order #" + get_order4() + " -</span><span color='green' weight='bold' font='20'>\n\n   READY!</span>");
	slabel4->set_alignment(Gtk::ALIGN_CENTER, Gtk::ALIGN_CENTER);
	return;
}
void Orderwin::click5(){
	fill_order5();
	button5->set_sensitive(false);
	cancel_button5->hide();
	button5->set_label("FILLED");
	slabel5->set_sensitive(false);
	set_slabel5("<span color='green' weight='bold' font='20'>- Order #" + get_order5() + " -</span><span color='green' weight='bold' font='20'>\n\n   READY!</span>");
	slabel5->set_alignment(Gtk::ALIGN_CENTER, Gtk::ALIGN_CENTER);
	return;
}

void Orderwin::click6(){
	fill_order6();
	button6->set_sensitive(false);
	cancel_button6->hide();
	button6->set_label("FILLED");
	slabel6->set_sensitive(false);
	set_slabel6("<span color='green' weight='bold' font='20'>- Order #" + get_order6() + " -</span><span color='green' weight='bold' font='20'>\n\n   READY!</span>");
	slabel6->set_alignment(Gtk::ALIGN_CENTER, Gtk::ALIGN_CENTER);
	return;
}



void Orderwin::cancel1(){
	Gtk::MessageDialog dcancel1("Are you sure you want to cancel this order?", true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_YES_NO, false);
	dcancel1.set_transient_for(*this);
	if(Gtk::RESPONSE_NO == dcancel1.run()){
		dcancel1.close();
		return;
	}
	else{
		cancel_order1();
		cancel_button1->set_sensitive(false);
		button1->hide();
		cancel_button1->set_label("CANCELLED");
		set_slabel1("<span color='red' weight='bold' font='20'>- Order #" + get_order1() + " -</span><span color='red' weight='bold' font='18'>\n\nCANCELLED!</span>");
	slabel1->set_alignment(Gtk::ALIGN_CENTER, Gtk::ALIGN_CENTER);

		return;
	}
return;
}	


void Orderwin::cancel2(){
	Gtk::MessageDialog dcancel2("Are you sure you want to cancel this order?", true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_YES_NO, false);
	dcancel2.set_transient_for(*this);
	if(Gtk::RESPONSE_NO == dcancel2.run()){
		dcancel2.close();
		return;
	}
	else{
	cancel_order2();
		cancel_button2->set_sensitive(false);
		button2->hide();
		cancel_button2->set_label("CANCELLED");
		set_slabel2("<span color='red' weight='bold' font='20'>- Order #" + get_order2() + " -</span><span color='red' weight='bold' font='18'>\n\nCANCELLED!</span>");
	slabel2->set_alignment(Gtk::ALIGN_CENTER, Gtk::ALIGN_CENTER);
		return;
	}
}

void Orderwin::cancel3(){
	Gtk::MessageDialog dcancel3("Are you sure you want to cancel this order?", true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_YES_NO, false);
	dcancel3.set_transient_for(*this);
	if(Gtk::RESPONSE_NO == dcancel3.run()){
		dcancel3.close();
		return;
	}
	else{
		cancel_order3();
		cancel_button3->set_sensitive(false);
		button3->hide();
		cancel_button3->set_label("CANCELLED");
		set_slabel3("<span color='red' weight='bold' font='20'>- Order #" + get_order3() + " -</span><span color='red' weight='bold' font='18'>\n\nCANCELLED!</span>");
	slabel3->set_alignment(Gtk::ALIGN_CENTER, Gtk::ALIGN_CENTER);
		return;
	}
}

void Orderwin::cancel4(){
	Gtk::MessageDialog dcancel4("Are you sure you want to cancel this order?", true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_YES_NO, false);
	dcancel4.set_transient_for(*this);
	if(Gtk::RESPONSE_NO == dcancel4.run()){
		dcancel4.close();
		return;
	}
	else{
		cancel_order4();
		cancel_button4->set_sensitive(false);
		button4->hide();
		cancel_button4->set_label("CANCELLED");
		set_slabel4("<span color='red' weight='bold' font='20'>- Order #" + get_order4() + " -</span><span color='red' weight='bold' font='18'>\n\nCANCELLED!</span>");
	slabel4->set_alignment(Gtk::ALIGN_CENTER, Gtk::ALIGN_CENTER);
		return;
	}
}
void Orderwin::cancel5(){
	Gtk::MessageDialog dcancel5("Are you sure you want to cancel this order?", true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_YES_NO, false);
	dcancel5.set_transient_for(*this);
	if(Gtk::RESPONSE_NO == dcancel5.run()){
		dcancel5.close();
		return;
	}
	else{
		cancel_order5();
		cancel_button5->set_sensitive(false);
		button5->hide();
		cancel_button5->set_label("CANCELLED");
		set_slabel5("<span color='red' weight='bold' font='20'>- Order #" + get_order5() + " -</span><span color='red' weight='bold' font='18'>\n\nCANCELLED!</span>");
	slabel5->set_alignment(Gtk::ALIGN_CENTER, Gtk::ALIGN_CENTER);
		return;
	}
}

void Orderwin::cancel6(){
		cancel_order6();
	Gtk::MessageDialog dcancel6("Are you sure you want to cancel this order?", true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_YES_NO, false);
	dcancel6.set_transient_for(*this);
	if(Gtk::RESPONSE_NO == dcancel6.run()){
		dcancel6.close();
		return;
	}
	else{
		cancel_button6->set_sensitive(false);
		button6->hide();
		cancel_button6->set_label("CANCELLED");
		set_slabel6("<span color='red' weight='bold' font='20'>- Order #" + get_order6() + " -</span><span color='red' weight='bold' font='18'>\n\nCANCELLED!</span>");
	slabel6->set_alignment(Gtk::ALIGN_CENTER, Gtk::ALIGN_CENTER);
		return;
	}
}


void Orderwin::set_slabel1(std::string newlabel){slabel1->set_markup(newlabel);}
void Orderwin::set_slabel2(std::string newlabel){slabel2->set_markup(newlabel);}
void Orderwin::set_slabel3(std::string newlabel){slabel3->set_markup(newlabel);}
void Orderwin::set_slabel4(std::string newlabel){slabel4->set_markup(newlabel);}
void Orderwin::set_slabel5(std::string newlabel){slabel5->set_markup(newlabel);}
void Orderwin::set_slabel6(std::string newlabel){slabel6->set_markup(newlabel);}

void Orderwin::set_label1(std::string newlabel){label1->set_markup(newlabel);}
void Orderwin::set_label2(std::string newlabel){label2->set_markup(newlabel);}
void Orderwin::set_label3(std::string newlabel){label3->set_markup(newlabel);}
void Orderwin::set_label4(std::string newlabel){label4->set_markup(newlabel);}
void Orderwin::set_label5(std::string newlabel){label5->set_markup(newlabel);}
void Orderwin::set_label6(std::string newlabel){label6->set_markup(newlabel);}

void Orderwin::show_order(int i){
	if(i >= 1) rowbox1->show_all();
	if(i >= 2) rowbox2->show_all();
	if(i >= 3) rowbox3->show_all();
	if(i >= 4) rowbox4->show_all();
	if(i >= 5) rowbox5->show_all();
	if(i >= 6) rowbox6->show_all();
}

void Orderwin::order_num1(std::string s) {Orderwin::_order1 = s;}
void Orderwin::order_num2(std::string s) {Orderwin::_order2 = s;}
void Orderwin::order_num3(std::string s) {Orderwin::_order3 = s;}
void Orderwin::order_num4(std::string s) {Orderwin::_order4 = s;}
void Orderwin::order_num5(std::string s) {Orderwin::_order5 = s;}
void Orderwin::order_num6(std::string s) {Orderwin::_order6 = s;}

std::string Orderwin::get_order1() {return _order1;}
std::string Orderwin::get_order2() {return _order2;}
std::string Orderwin::get_order3() {return _order3;}
std::string Orderwin::get_order4() {return _order4;}
std::string Orderwin::get_order5() {return _order5;}
std::string Orderwin::get_order6() {return _order6;}

void Orderwin::fill_order1(){ _filled1 = 1;}
void Orderwin::fill_order2(){ _filled2 = 1;}
void Orderwin::fill_order3(){ _filled3 = 1;}
void Orderwin::fill_order4(){ _filled4 = 1;}
void Orderwin::fill_order5(){ _filled5 = 1;}
void Orderwin::fill_order6(){ _filled6 = 1;}

void Orderwin::cancel_order1(){_filled1 = 2;}
void Orderwin::cancel_order2(){_filled2 = 2;}
void Orderwin::cancel_order3(){_filled3 = 2;}
void Orderwin::cancel_order4(){_filled4 = 2;}
void Orderwin::cancel_order5(){_filled5 = 2;}
void Orderwin::cancel_order6(){_filled6 = 2;}

int Orderwin::filled1(){return _filled1;}
int Orderwin::filled2(){return _filled2;}
int Orderwin::filled3(){return _filled3;}
int Orderwin::filled4(){return _filled4;}
int Orderwin::filled5(){return _filled5;}
int Orderwin::filled6(){return _filled6;}

