#include "item.h"
#include <iostream>
#include <iomanip>

namespace Mice {

Item::Item(std::string name, std::string description, double cost, double price) : _name{name}, _description{description}, _cost{cost}, _price {price}, _quantity{14}{ }
Item::Item() : _name{""}, _description{""}, _cost{0}, _price{0}, _quantity{0} { }
std::string Item::type() const {return "Item";}
void Item::restock(int quantity) {_quantity  = quantity;}
void Item::consume(int quantity) {_quantity -= quantity;}
std::string Item::name() const {return _name;}
std::string Item::description() const {return _description;}
double Item::cost() const {return _cost;}
double Item::price() const {return _price;}
int Item::quantity() const {return _quantity;}
int Item::max_quantity() const{return _max_quantity;}

}

// POLYMORPHISM at item.name()
std::ostream& operator<<(std::ostream& os, const Mice::Item& item) {
    os << std::setw(40) << item.type() + ": " + item.name() << " $" 
       << std::setprecision(2) << std::fixed << item.price(); 
    return os;
}

