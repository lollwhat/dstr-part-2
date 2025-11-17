#include "CustomStack.hpp"
#include "medicalSupply.hpp"
#include <array>
#include <string>
#include <iostream>
#include <limits>

CustomStack<MedicalSupply> supplyStack; //supply id, name, type, quantity, batch

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

int getMenuChoice(){
    int choice; std::cout << "Enter your choice (0-3): ";
    while (!(std::cin >> choice) || choice < 0 || choice > 3) {
        std::cout << "Invalid input. Please enter a number between 0 and 3: ";
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
    }
    return choice;
}

int main(){
    int choice = -1;
    while(choice != 0){
        mainMenu();
        choice = getMenuChoice();

        switch(choice){
            case 1: {
                MedicalSupply newSupply; // Use the struct
                std::cout << "Enter Supply ID: ";
                std::cin >> newSupply.id;
                std::cout << "Enter Supply Name: ";
                std::cin >> newSupply.name;
                std::cout << "Enter Supply Type: ";
                std::cin >> newSupply.type;
                std::cout << "Enter Quantity: ";
                std::cin >> newSupply.quantity; // Reads directly into the int
                std::cout << "Enter Batch Number: ";
                std::cin >> newSupply.batch;

                supplyStack.push(newSupply); // Add the struct to the correct stack
                std::cout << "Supply added to stock." << std::endl;
                break;
            }
            case 2: {
                if (supplyStack.isEmpty()) { // Check the correct stack
                    std::cout << "No supplies in stock to use." << std::endl;
                } else {
                    auto usedSupply = supplyStack.pop(); // Pop from the correct stack
                    // Use the struct members for clean, readable output
                    std::cout << "Used Supply - ID: " << usedSupply.id
                            << ", Name: " << usedSupply.name
                            << ", Type: " << usedSupply.type
                            << ", Quantity: " << usedSupply.quantity
                            << ", Batch: " << usedSupply.batch << std::endl;
                }
                break;
            }
            case 3:{
                if(supplyStack.isEmpty()){
                    std::cout << "No supplies in stock." << std::endl;
                } else {
                    std::cout << "Current Supplies in Stock (Top to Bottom):" << std::endl;
                    CustomStack<MedicalSupply> tempStack;
                    while (!supplyStack.isEmpty()) {
                        auto supply = supplyStack.pop();
                        std::cout << "ID: " << supply.id
                                << ", Name: " << supply.name
                                << ", Type: " << supply.type
                                << ", Qty: " << supply.quantity
                                << ", Batch: " << supply.batch << std::endl;
                        tempStack.push(supply);
                    }
                    while (!tempStack.isEmpty()) {
                        supplyStack.push(tempStack.pop());
                    }
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

    return 0;
}