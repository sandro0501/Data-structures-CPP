
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>


/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2024" << std::endl;

  unsigned long choice = 0;
  std::cout << "Choose the test to execute: " << std::endl << "1. lasdtest" << std::endl << "2. myTest" << std::endl << std::endl;
  std::cout<< "Choice: ";
  std::cin >> choice;
  std::cout << std::endl;

  if (choice == 1) {
    lasdtest(); 
  } else if (choice == 2) {
    mytest();
  } else {
    std::cout << "Ops...Make a correct choice!" << std::endl;
  }

  return 0;
}
