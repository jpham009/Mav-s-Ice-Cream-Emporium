#include "test_item.h"
#include "item.h"
#include <iostream>

bool test_item() {
  std::string expected = "";
  bool passed = true; // Optimist!

  //
  // Test constructor
  //

  std::string x_name = "Fudge Ripple";
  std::string x_description = "Chocolatey goodness in vanilla swirl";
  double x_cost = 0.75;
  double x_price = 1.50;

  Item item{x_name, x_description, x_cost, x_price};

  if (item.name() != x_name ||
      item.description() != x_description ||
      item.cost() != x_cost ||
      item.price() != x_price ||
      item.quantity() != 0) {
    std::cerr << "#### Item constructor fail" << std::endl;
    std::cerr << "Expected: " << x_name << ',' 
                              << x_description << ','
                              << x_cost << ','
                              << x_price << ','
                              << '0' << std::endl;
    std::cerr << "Actual:   " << item.name() << ',' 
                              << item.description() << ','
                              << item.cost() << ','
                              << item.price() << ','
                              << item.quantity() << std::endl;
    passed = false;
  }

  //
  // Report results
  //

  return passed;
}
