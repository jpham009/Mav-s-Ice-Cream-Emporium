#include "test_scoop.h"
#include "scoop.h"
#include <iostream>

bool test_scoop() {
  std::string expected = "";
  bool passed = true; // Optimist!

  //
  // Test constructor
  //

  std::string x_name = "Fudge Ripple";
  std::string x_description = "Chocolatey goodness in vanilla swirl";
  double x_cost = 0.75;
  double x_price = 1.50;

  Scoop scoop{x_name, x_description, x_cost, x_price};

  if (scoop.name() != x_name ||
      scoop.description() != x_description ||
      scoop.cost() != x_cost ||
      scoop.price() != x_price ||
      scoop.quantity() != 0) {
    std::cerr << "#### Scoop constructor fail" << std::endl;
    std::cerr << "Expected: " << x_name << ','
                              << x_description << ','
                              << x_cost << ','
                              << x_price << ','
                              << '0' << std::endl;
    std::cerr << "Actual:   " << scoop.name() << ','
                              << scoop.description() << ','
                              << scoop.cost() << ','
                              << scoop.price() << ','
                              << scoop.quantity() << std::endl;
    passed = false;
  }

  //
  // Report results
  //

  return passed;
}
