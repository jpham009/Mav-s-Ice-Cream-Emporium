#ifndef _ITEM_H
#define _ITEM_H

#include <string>

namespace Mice {

class Item {
  public:
    Item(std::string name, std::string description, double cost, double price);
    void restock(int quantity = 25);
    void consume(int quantity = 1);
    virtual std::string type() const;
    std::string name() const;
    std::string description() const;
    double cost() const;
    double price() const;
    int quantity() const;
	int max_quantity() const;
  private:
    std::string _name;
    std::string _description;
    double _cost;
    double _price;
    int _quantity;
	int _max_quantity;
    // Gtk::Image _photo;
};

}

std::ostream& operator<<(std::ostream& os, const Mice::Item& item);

#endif
