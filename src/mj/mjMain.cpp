#include <iostream>
#include <string>
#include <limits>
#include "AmbulanceDispatcher.hpp"

void showMenu() {
  std::cout << "\n--- 🚑 Hospital Ambulance Dispatch ---" << std::endl;
  std::cout << "1. Register New Ambulance" << std::endl;
  std::cout << "2. Rotate Ambulance Shift (Dispatch)" << std::endl;
  std::cout << "3. Display Ambulance Schedule" << std::endl;
  std::cout << "4. Exit" << std::endl;
  std::cout << "Enter your choice: ";
}

int main() {
  // 1. Create an instance of your class
  AmbulanceDispatcher dispatcher;
  int choice;
  
  // 2. Start the menu loop
  while (true) {
    showMenu();
    
    // 3. Get user's choice
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    // 4. Handle the choice
    switch (choice) {
      case 1: { // Register Ambulance
        std::string driver;
        std::cout << "   Enter Driver's Name: ";
        std::getline(std::cin, driver);
        
        dispatcher.registerAmbulance(driver);
        break;
      }
      case 2: { // Rotate Shift
        dispatcher.rotateAmbulanceShift();
        break;
      }
      case 3: { // Display Schedule
        std::cout << "\n--- Current Ambulance Schedule ---" << std::endl;
        dispatcher.displayAmbulanceSchedule();
        std::cout << "------------------------------------" << std::endl;
        break;
      }
      case 4: { // Exit
        std::cout << "Shutting down dispatch system." << std::endl;
        return 0; // Exits the main function and ends the program
      }
      default: {
        std::cerr << "Invalid choice. Please try again." << std::endl;
        break;
      }
    }
  }
    
  return 0;
}