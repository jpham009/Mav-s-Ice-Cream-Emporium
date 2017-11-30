#ifndef ORDERWIN_H
#define ORDERWIN_H
#include <exception>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <gtkmm.h>

class Orderwin : public Gtk::Dialog {
	public:
		Orderwin();
		virtual ~Orderwin();
		void clickrefresh();
		void click1();
		void click2();
		void click3();
		void click4();
		void click5();
		void click6();
		void cancel1();
		void cancel2();
		void cancel3();
		void cancel4();
		void cancel5();
		void cancel6();
		void set_slabel1(std::string);
		void set_slabel2(std::string);
		void set_slabel3(std::string);
		void set_slabel4(std::string);
		void set_slabel5(std::string);
		void set_slabel6(std::string);
		void set_label1(std::string);
		void set_label2(std::string);
		void set_label3(std::string);
		void set_label4(std::string);
		void set_label5(std::string);
		void set_label6(std::string);
		void show_order(int i);
		void order_num1(std::string); 
		void order_num2(std::string); 
		void order_num3(std::string); 
		void order_num4(std::string); 
		void order_num5(std::string); 
		void order_num6(std::string); 
	
		std::string get_order1();
		std::string get_order2();
		std::string get_order3();
		std::string get_order4();
		std::string get_order5();
		std::string get_order6();
		void cancel_order1();
		void cancel_order2();
		void cancel_order3();
		void cancel_order4();
		void cancel_order5();
		void cancel_order6();
		void fill_order1();
		void fill_order2();
		void fill_order3();
		void fill_order4();
		void fill_order5();
		void fill_order6();

		
int filled1();
int filled2();
int filled3();
int filled4();
int filled5();
int filled6();



	private:

		int _filled1{0};
		int _filled2{0};
		int _filled3{0};
		int _filled4{0};
		int _filled5{0};
		int _filled6{0};
	

		std::string _order1;
		std::string _order2;
		std::string _order3;
		std::string _order4;
		std::string _order5;
		std::string _order6;

		Gtk::Button *button1;
		Gtk::Button *button2;
		Gtk::Button *button3;
		Gtk::Button *button4;
		Gtk::Button *button5;
		Gtk::Button *button6;

		Gtk::Button *cancel_button1;
		Gtk::Button *cancel_button2;
		Gtk::Button *cancel_button3;
		Gtk::Button *cancel_button4;
		Gtk::Button *cancel_button5;
		Gtk::Button *cancel_button6;


		Gtk::Button *refresh_button;
		Gtk::VBox *innerbox1;
		Gtk::VBox *innerbox2;
		Gtk::VBox *innerbox3;
		Gtk::VBox *innerbox4;
		Gtk::VBox *innerbox5;
		Gtk::VBox *innerbox6;

		Gtk::VBox *inner2box1;
		Gtk::VBox *inner2box2;
		Gtk::VBox *inner2box3;
		Gtk::VBox *inner2box4;
		Gtk::VBox *inner2box5;
		Gtk::VBox *inner2box6;
		Gtk::HBox *inner3box1;
		Gtk::HBox *inner3box2;
		Gtk::HBox *inner3box3;
		Gtk::HBox *inner3box4;
		Gtk::HBox *inner3box5;
		Gtk::HBox *inner3box6;
		Gtk::ScrolledWindow *scroll1;
		Gtk::ScrolledWindow *scroll2;
		Gtk::ScrolledWindow *scroll3;
		Gtk::ScrolledWindow *scroll4;
		Gtk::ScrolledWindow *scroll5;
		Gtk::ScrolledWindow *scroll6;
		Gtk::Label *slabel1;
		Gtk::Label *slabel2;
		Gtk::Label *slabel3;
		Gtk::Label *slabel4;
		Gtk::Label *slabel5;
		Gtk::Label *slabel6;
		Gtk::VBox *rowbox1;
		Gtk::VBox *rowbox2;
		Gtk::VBox *rowbox3;
		Gtk::VBox *rowbox4;
		Gtk::VBox *rowbox5;
		Gtk::VBox *rowbox6;
		Gtk::Frame *frame1;
		Gtk::Frame *frame2;
		Gtk::Frame *frame3;
		Gtk::Frame *frame4;
		Gtk::Frame *frame5;
		Gtk::Frame *frame6;
		Gtk::Label *label1;
		Gtk::Label *label2;
		Gtk::Label *label3;
		Gtk::Label *label4;
		Gtk::Label *label5;
		Gtk::Label *label6;
Gtk::HBox *levelbox1;
Gtk::HBox *levelbox2;
Gtk::VBox *mainbox;

};


#endif //ORDERWIN_H
