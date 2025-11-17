#include <iostream>
#include "./PatientAdmissionClerk/ayMain.hpp" // Lee Aik Yen
#include "./medicalSupplyManager/cwMain.hpp" // Lee Chen Wei
#include "./emergencyDeptOfficer/emergencyDeptOfficer.hpp" // Soo Chee Yang
#include "./ambulanceDispatcher/mjMain.hpp" // Lee Ming Jia

void printWelcomeScreen()
{
// Use "clear" for macOS/Linux, "cls" for Windows
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif

  std::cout << R"(
=====================================================================================================
#     #                                               ######                                         
#     #  ####   ####  #####  # #####   ##   #         #     #   ##   ##### # ###### #    # #####     
#     # #    # #      #    # #   #    #  #  #         #     #  #  #    #   # #      ##   #   #       
####### #    #  ####  #    # #   #   #    # #         ######  #    #   #   # #####  # #  #   #       
#     # #    #      # #####  #   #   ###### #         #       ######   #   # #      #  # #   #       
#     # #    # #    # #      #   #   #    # #         #       #    #   #   # #      #   ##   #       
#     #  ####   ####  #      #   #   #    # ######    #       #    #   #   # ###### #    #   #       
 #####                          #     #                                                              
#     #   ##   #####  ######    ##   ##   ##   #    #   ##    ####  ###### #    # ###### #    # #####
#        #  #  #    # #         # # # #  #  #  ##   #  #  #  #    # #      ##  ## #      ##   #   #  
#       #    # #    # #####     #  #  # #    # # #  # #    # #      #####  # ## # #####  # #  #   #  
#       ###### #####  #         #     # ###### #  # # ###### #  ### #      #    # #      #  # #   #  
#     # #    # #   #  #         #     # #    # #   ## #    # #    # #      #    # #      #   ##   #  
 #####  #    # #    # ######    #     # #    # #    # #    #  ####  ###### #    # ###### #    #   #  
 #####                                                                                               
#     # #   #  ####  ##### ###### #    #                                                             
#        # #  #        #   #      ##  ##                                                             
 #####    #    ####    #   #####  # ## #                                                             
      #   #        #   #   #      #    #                                                             
#     #   #   #    #   #   #      #    #                                                             
 #####    #    ####    #   ###### #    #                                                             
=======================================================================================================+
|            Description: Simulates Hospital Patient Care Management using Stacks & Queues.            |
+======================================================================================================+
)";
}

int main() {
  int choice = 0;
  while (choice != 5) {
    printWelcomeScreen();
    std::cout << "+======================================================================================================+" << std::endl;
    std::cout << "| Features:                                                                                            |" << std::endl;
    std::cout << "| ‣ [1] [Queue] Patient Admission Clerk     : Lee Aik Yen (TP070648)                                   |" << std::endl;
    std::cout << "| ‣ [2] [Stack] Medical Supply Manager      : Lee Chen Wei (TP069059)                                  |" << std::endl;
    std::cout << "| ‣ [3] [Priority Queue] Emergency Dept Officer : Soo Chee Yang (TP071405)                             |" << std::endl;
    std::cout << "| ‣ [4] [Circular Queue] Ambulance Dispatcher   : Lee Ming Jia (TP070850)                              |" << std::endl;
    std::cout << "+------------------------------------------------------------------------------------------------------+" << std::endl;
    std::cout << "| [5]  Exit Program                                                                                    |" << std::endl;
    std::cout << "+------------------------------------------------------------------------------------------------------+" << std::endl;
    std::cout << "Enter your choice (1-5): ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
      std::cout << "\nLaunching: Patient Admission System..." << std::endl;
      ayMain();
      break;
    case 2:
      std::cout << "\nLaunching: Medical Supply Management..." << std::endl;
      cwMain();
      break;
    case 3:
      std::cout << "\nLaunching: Emergency Department System..." << std::endl;
      emergencyOfficer();
      break;
    case 4:
      std::cout << "\nLaunching: Ambulance Dispatch System..." << std::endl;
      mjMain();
      break;
    case 5:
      std::cout << "\nExiting Hospital Management System. Goodbye!\n"
                << std::endl;
      break;
    default:
      std::cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
      std::cout << "Press Enter to continue...";
      std::cin.ignore();
      std::cin.get();
      break;
    }
  }
  return 0;
}