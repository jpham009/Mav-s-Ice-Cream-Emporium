#include "mainwin.h"


void Mainwin::order_window(){
_pending.clear();
_pendingstring.clear();
pending_orders(); 

if (_pending.empty()){
	Gtk::Dialog *cleardialog = new Gtk::Dialog("Pending");
	cleardialog->set_transient_for(*this);
	cleardialog->set_default_size(1000,800);
	Gtk::Label *clearmsg = Gtk::manage(new Gtk::Label());
	clearmsg->set_markup("<span weight='bold' font='16'> There are currently no orders to be filled at the moment... </span>");
	cleardialog->get_vbox()->pack_start(*clearmsg);
	cleardialog->show_all();
	cleardialog->run();
	cleardialog->close();

}
else{

	winwin = new Orderwin(); 
	winwin->set_transient_for(*this);
	//winwin.set_title(std::to_string(WINDOW_COUNTER++));
	if(_pending.size() >= 1){ winwin->set_slabel1(_pendingstring[0]); winwin->show_order(1); winwin->order_num1(std::to_string(_pending[0])); }
	if(_pending.size() >= 1){ winwin->set_label1("<span weight='bold' font='14'>Order #" +  std::to_string(_pending[0]) + "</span>"); }
	if(_pending.size() >= 2){ winwin->set_slabel2(_pendingstring[1]); winwin->show_order(2); winwin->order_num2(std::to_string(_pending[1]));}
	if(_pending.size() >= 2){ winwin->set_label2("<span weight='bold' font='14'>Order #" +  std::to_string(_pending[1]) + "</span>"); }
	if(_pending.size() >= 3){ winwin->set_slabel3(_pendingstring[2]); winwin->show_order(3); winwin->order_num3(std::to_string(_pending[2]));}
	if(_pending.size() >= 3){ winwin->set_label3("<span weight='bold' font='14'>Order #" +  std::to_string(_pending[2]) + "</span>"); }
	if(_pending.size() >= 4){ winwin->set_slabel4(_pendingstring[3]); winwin->show_order(4); winwin->order_num4(std::to_string(_pending[3]));}
	if(_pending.size() >= 4){ winwin->set_label4("<span weight='bold' font='14'>Order #" +  std::to_string(_pending[3]) + "</span>"); }
	if(_pending.size() >= 5){ winwin->set_slabel5(_pendingstring[4]); winwin->show_order(5); winwin->order_num5(std::to_string(_pending[4]));}
	if(_pending.size() >= 5){ winwin->set_label5("<span weight='bold' font='14'>Order #" +  std::to_string(_pending[4]) + "</span>"); }
	if(_pending.size() >= 6){ winwin->set_slabel6(_pendingstring[5]); winwin->show_order(6); winwin->order_num6(std::to_string(_pending[5]));}
	if(_pending.size() >= 6){ winwin->set_label6("<span weight='bold' font='14'>Order #" +  std::to_string(_pending[5]) + "</span>"); }

	winwin->run();

	
	//filled 
	if(_pending.size() >= 1) { if (winwin->filled1() == 1) { _emp->orders().erase(_emp->orders().begin()+0); _pending.erase(_pending.begin() + 0);_pendingstring.erase(_pendingstring.begin() + 0);}}
	if(_pending.size() >= 2) { if (winwin->filled2() == 1) { _emp->orders().erase(_emp->orders().begin()+1); _pending.erase(_pending.begin() + 1);_pendingstring.erase(_pendingstring.begin() + 1);}}
	if(_pending.size() >= 3) { if (winwin->filled3() == 1) { _emp->orders().erase(_emp->orders().begin()+2); _pending.erase(_pending.begin() + 2);_pendingstring.erase(_pendingstring.begin() + 2);}}
	if(_pending.size() >= 4) { if (winwin->filled4() == 1) { _emp->orders().erase(_emp->orders().begin()+3); _pending.erase(_pending.begin() + 3);_pendingstring.erase(_pendingstring.begin() + 3);}}
	if(_pending.size() >= 5) { if (winwin->filled5() == 1) { _emp->orders().erase(_emp->orders().begin()+4); _pending.erase(_pending.begin() + 4);_pendingstring.erase(_pendingstring.begin() + 4);}}
	if(_pending.size() >= 6) { if (winwin->filled6() == 1) { _emp->orders().erase(_emp->orders().begin()+5); _pending.erase(_pending.begin() + 5);_pendingstring.erase(_pendingstring.begin() + 5);}}

	
	
	//cancelled
	if(_pending.size() >= 1) { if (winwin->filled1() == 2) { _emp->orders().erase(_emp->orders().begin()+0); _pending.erase(_pending.begin() + 0);_pendingstring.erase(_pendingstring.begin() + 0); } }
	if(_pending.size() >= 2) { if (winwin->filled2() == 2) { _emp->orders().erase(_emp->orders().begin()+1);_pending.erase(_pending.begin() + 1);_pendingstring.erase(_pendingstring.begin() + 1); } }
	if(_pending.size() >= 3) { if (winwin->filled3() == 2) { _emp->orders().erase(_emp->orders().begin()+2);_pending.erase(_pending.begin() + 2);_pendingstring.erase(_pendingstring.begin() + 2); }}
	if(_pending.size() >= 4) { if (winwin->filled4() == 2) { _emp->orders().erase(_emp->orders().begin()+3);_pending.erase(_pending.begin() + 3);_pendingstring.erase(_pendingstring.begin() + 3); } }
	if(_pending.size() >= 5) { if (winwin->filled5() == 2) { _emp->orders().erase(_emp->orders().begin()+4);_pending.erase(_pending.begin() + 4);_pendingstring.erase(_pendingstring.begin() + 4); } }
	if(_pending.size() >= 6) { if (winwin->filled6() == 2) {_emp->orders().erase(_emp->orders().begin()+5);_pending.erase(_pending.begin() + 5);_pendingstring.erase(_pendingstring.begin() + 5); } }


	winwin->set_label1("");
	winwin->set_label2("");
	winwin->set_label3("");
	winwin->set_label4("");
	winwin->set_label5("");
	winwin->set_label6("");
	winwin->set_slabel1("");
	winwin->set_slabel2("");
	winwin->set_slabel3("");
	winwin->set_slabel4("");
	winwin->set_slabel5("");
	winwin->set_slabel6("");

	winwin->hide(); 
	

	}
}

void Mainwin::pending_orders(){
	for(int i = 0; i < _emp->num_orders(); i++){
		if((_emp->order(i).state() == false) && (_emp->order(i).cancelled() == false)){
			_pending.push_back(_emp->order(i).get_order_number());
			_pendingstring.push_back(_emp->order(i).get_order_string());
		}
	}
	return;
}
