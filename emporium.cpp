#include "emporium.h"
#include <stdexcept>

namespace Mice {

Emporium::Emporium(std::string name) : _name{name}, _cash_register{0}, _id{0} { 
//Auto-Load Defaults
Emporium::on_load_defaults_click(); 
}

Emporium::Emporium(std::istream& ist) {
    // WARNING: Do NOT strip the header - pass the FULL FILE to Emporium!
    std::string header1, header2;

    std::getline(ist, header1); // magic cookie
    std::getline(ist, header2);
    if (header1 != "MICE") throw std::runtime_error("NOT an Emporium file");
    if (header2 != "0.1") throw std::runtime_error("Incompatible file version");
 
    std::getline(ist, header1); // header
    std::getline(ist, header2);
    if (header1 != "#") throw std::runtime_error("No Emporium records in file");
    if (header2 != "EMPORIUM") throw std::runtime_error("Malformed Emporium record");

    std::getline(ist, _name);
    ist >> _cash_register; ist.ignore();
    ist >> _id; ist.ignore();

    while(ist) {
        std::getline(ist, header1); // header
        std::getline(ist, header2);

        if (header1 != "#") throw std::runtime_error("missing # during input");
        if (header2 == "CONTAINER") _containers.push_back(Container{ist});
        else if (header2 == "SCOOP") _scoops.push_back(Scoop{ist});
        else if (header2 == "TOPPING") _toppings.push_back(Topping{ist});
        //else if (header2 == "ORDER") _orders.push_back(Order{ist});
        else if (header2 == "SERVER") _servers.push_back(Server{ist});
        else if (header2 == "CUSTOMER") _customers.push_back(Customer{ist});
        else if (header2 == "END EMPORIUM") break;
        else throw std::runtime_error("invalid item type in Emporium");
    }
}

void Emporium::save(std::ostream& ost) {
        ost << "MICE" << std::endl << "0.1" << std::endl; // magic cookie
        ost << "#" << std::endl << "EMPORIUM" << std::endl; // header
        ost << _name << std::endl;
        ost << _cash_register << std::endl;
        ost << _id << std::endl;

        for (Mice::Container c : _containers) c.save(ost);
        for (Mice::Scoop s : _scoops) s.save(ost);
        for (Mice::Topping t : _toppings) t.save(ost);
      //  for (Mice::Order o : _orders) o.save(ost);
        for (Mice::Server s : _servers) s.save(ost);
        for (Mice::Customer c : _customers) c.save(ost);
        ost << "#" << std::endl << "END EMPORIUM" << std::endl; // footer
}

std::string Emporium::name() {return _name;}
double Emporium::cash_register() {return _cash_register;}
void Emporium::debit(double amount) {_cash_register -= amount;}
void Emporium::credit(double amount) {_cash_register += amount;}
int Emporium::next_id() {return ++_id;}

int Emporium::num_containers() {return _containers.size();}
int Emporium::num_scoops() {return _scoops.size();}
int Emporium::num_toppings() {return _toppings.size();}
int Emporium::num_orders() {return _orders.size();}
int Emporium::num_servers() {return _servers.size();}
int Emporium::num_customers() {return _customers.size();}
int Emporium::num_managers() {return _managers.size();}

Container& Emporium::container(int index) {return _containers[index];}
Scoop& Emporium::scoop(int index) {return _scoops[index];}
Topping& Emporium::topping(int index) {return _toppings[index];}
Order& Emporium::order(int index) {return _orders[index];}
Server& Emporium::server(int index) {return _servers[index];}
Customer& Emporium::customer(int index) {return _customers[index];}
Manager& Emporium::manager(int index) {return _managers[index];}
void Emporium::add_container(Container container) {_containers.push_back(container);}
void Emporium::add_scoop(Scoop scoop) {_scoops.push_back(scoop);}
void Emporium::add_topping(Topping topping) {_toppings.push_back(topping);}
void Emporium::add_order(Order order) {_orders.push_back(order);}
void Emporium::add_server(Server server) {_servers.push_back(server);}
void Emporium::add_customer(Customer customer) {_customers.push_back(customer);}
void Emporium::add_manager(Manager manager) {_managers.push_back(manager);}

 std::vector<Mice::Container>& Emporium::containers() {return _containers;}
 std::vector<Mice::Scoop>& Emporium::scoops() {return _scoops;}
 std::vector<Mice::Topping>& Emporium::toppings() {return _toppings;}
 std::vector<Mice::Order>& Emporium::orders() {return _orders;}
 std::vector<Mice::Server>& Emporium::servers() {return _servers;}
 std::vector<Mice::Customer>& Emporium::customers() {return _customers;}



void Emporium::on_load_defaults_click() {
		
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
 
	}
}
