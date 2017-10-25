#include "test_item.h"
#include "test_scoop.h"
#include <iostream>

int main() {
  if (!(test_item() &&
        test_scoop()))
    std::cerr << "fail" << std::endl;
} 
