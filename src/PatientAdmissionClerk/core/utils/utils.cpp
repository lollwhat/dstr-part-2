/**
 * utils.cpp
 * Utility functions implementation
 */

#include "../../Header/utils/utils.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

std::string getCurrentTimestamp() {
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    return std::string(buffer);
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

bool validateMenuChoice(int& choice, int min, int max) {
    if (!(std::cin >> choice)) {
        clearInputBuffer();
        return false;
    }
    return (choice >= min && choice <= max);
}

void displayMenu() {
    std::cout << "\n\t========================================\n";
    std::cout << "\t   PATIENT ADMISSION CLERK SYSTEM\n";
    std::cout << "\t   Queue-Based Management System\n";
    std::cout << "\t========================================\n";
    std::cout << "\t1. Add Patient (Enqueue)\n";
    std::cout << "\t2. Process Next Patient (Dequeue)\n";
    std::cout << "\t3. View Front Patient\n";
    std::cout << "\t4. Display All Patients in Queue\n";
    std::cout << "\t5. Exit\n";
    std::cout << "\t========================================\n";
    std::cout << "\tEnter your choice: ";
}

