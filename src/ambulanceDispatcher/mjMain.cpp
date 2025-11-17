#include <iostream>
#include <string>
#include <limits>
#include "AmbulanceDispatcher.hpp"

void showMJMenu() {
  std::cout << "\n--- 🚑 Hospital Ambulance Dispatch ---" << std::endl;
  std::cout << "1. Register Ambulance (Manual)" << std::endl;
  std::cout << "2. Register Ambulances (Batch)" << std::endl;
  std::cout << "3. Rotate Ambulance Shift (Dispatch)" << std::endl;
  std::cout << "4. Display Ambulance Schedule" << std::endl;
  std::cout << "5. Exit" << std::endl;
  std::cout << "Enter your choice: ";
}

void mjMain() {
  AmbulanceDispatcher dispatcher;
  int choice;
  
  while (true) {
    showMJMenu();
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    switch (choice) {
      case 1: { // Register Ambulance (Manual)
        std::string driver;
        std::cout << "   Enter Driver's Name: ";
        std::getline(std::cin, driver);
        
        dispatcher.registerAmbulance_Manual(driver);
        break;
      }
      case 2: { // Register Ambulances (Batch)
        int count;
        std::cout << "   How many ambulances to add?: ";
        std::cin >> count;
        
        if (std::cin.fail()) {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cerr << "Invalid input. Please enter a number." << std::endl;
        } else {
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear newline
          dispatcher.registerAmbulance_Batch(count);
        }
        break;
      }
      case 3: { // Rotate Shift
        dispatcher.rotateAmbulanceShift();
        break;
      }
      case 4: { // Display Schedule
        std::cout << "\n--- Current Ambulance Schedule ---" << std::endl;
        dispatcher.displayAmbulanceSchedule();
        std::cout << "------------------------------------" << std::endl;
        break;
      }
      case 5: { // Back to Main Menu
        std::cout << "Returning to Main Menu." << std::endl;
        return;
      }
      default: {
        std::cerr << "Invalid choice. Please try again." << std::endl;
        break;
      }
    }
  }   
}