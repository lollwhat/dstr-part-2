#include "CustomStack.hpp"
#include <array>
#include <string>
#include <iostream>

CustomStack<std::array<std::string, 5>> arrayStack; //supply id, name, type, quantity, batch

void mainMenu(){
    std::cout << "\n========================================" << std::endl;
    std::cout << "     MEDICAL SUPPLY MANAGER MENU     " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "1. Add Supply Stock" << std::endl;
    std::cout << "2. Use Last Added Supply" << std::endl;
    std::cout << "3. View Current Supplies" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Enter your choice (0-3): ";
}

void medicalSupplyManager(){
    int choice = -1;
    while(choice != 0){
        mainMenu();
        std::cin >> choice;

        switch(choice){
            case 1:{
                std::array<std::string, 5> newSupply;
                std::cout << "Enter Supply ID: ";
                std::cin >> newSupply[0];
                std::cout << "Enter Supply Name: ";
                std::cin >> newSupply[1];
                std::cout << "Enter Supply Type: ";
                std::cin >> newSupply[2];
                std::cout << "Enter Quantity: ";
                std::cin >> newSupply[3];
                std::cout << "Enter Batch Number: ";
                std::cin >> newSupply[4];

                arrayStack.push(newSupply);
                std::cout << "Supply added to stock." << std::endl;
                break;
            }
            case 2:{
                if(arrayStack.isEmpty()){
                    std::cout << "No supplies in stock to use." << std::endl;
                } else {
                    auto usedSupply = arrayStack.pop();
                    std::cout << "Used Supply - ID: " << usedSupply[0] 
                              << ", Name: " << usedSupply[1] 
                              << ", Type: " << usedSupply[2] 
                              << ", Quantity: " << usedSupply[3] 
                              << ", Batch: " << usedSupply[4] << std::endl;
                }
                break;
            }
            case 3:{
                if(arrayStack.isEmpty()){
                    std::cout << "No supplies in stock." << std::endl;
                } else {
                    std::cout << "Current Supplies in Stock (Top to Bottom):" << std::endl;
                    arrayStack.view();
                }
                break;
            }
            case 0:{
                std::cout << "Exiting Medical Supply Manager." << std::endl;
                break;
            }
            default:{
                std::cout << "Invalid choice. Please enter a number between 0 and 3." << std::endl;
                break;
            }
        }
    }
}