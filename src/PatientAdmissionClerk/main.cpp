#include <iostream>
#include <string>
#include "Header/models/Patient.hpp"
#include "Header/queue/PatientQueue.hpp"
#include "Header/utils/utils.hpp"

// Individual compile command (directory must be in root folder): g++ -std=c++11 -Wall -Wextra -Isrc/PatientAdmissionClerk/Header src/PatientAdmissionClerk/core/models/Patient.cpp src/PatientAdmissionClerk/core/queue/PatientQueue.cpp src/PatientAdmissionClerk/core/utils/utils.cpp src/PatientAdmissionClerk/main.cpp -o main.exe
int main() {
    PatientQueue queue;
    int choice;
    bool running = true;
    
    std::cout << "\n\t========================================\n";
    std::cout << "\t   WELCOME TO PATIENT ADMISSION SYSTEM\n";
    std::cout << "\t   Using Queue Data Structure\n";
    std::cout << "\t========================================\n";
    
    // Main program loop
    while (running) {
        displayMenu();
        
        if (!validateMenuChoice(choice, 1, 5)) {
            std::cout << "\n\t[ERROR] Invalid input! Please enter a number between 1-5.\n";
            continue;
        }
        
        clearInputBuffer();  // Clear remaining input
        
        switch (choice) {
            case 1: {  // Add Patient (Enqueue)
                if (queue.isFull()) {
                    std::cout << "\n\t[ERROR] Queue is full! Cannot add more patients.\n";
                    break;
                }
                
                Patient newPatient;
                std::cout << "\n\t--- Add New Patient ---\n";
                std::cout << "\tEnter Patient ID: ";
                std::getline(std::cin, newPatient.patientID);
                
                std::cout << "\tEnter Patient Name: ";
                std::getline(std::cin, newPatient.name);
                
                std::cout << "\tEnter Medical Condition: ";
                std::getline(std::cin, newPatient.condition);
                
                newPatient.admissionTime = getCurrentTimestamp();
                
                if (queue.enqueue(newPatient)) {
                    std::cout << "\n\t[SUCCESS] Patient " << newPatient.name 
                              << " (ID: " << newPatient.patientID 
                              << ") added to queue successfully!\n";
                    std::cout << "\tAdmission Time: " << newPatient.admissionTime << "\n";
                } else {
                    std::cout << "\n\t[ERROR] Failed to add patient. Queue is full.\n";
                }
                break;
            }
            
            case 2: {  // Process Next Patient (Dequeue)
                if (queue.isEmpty()) {
                    std::cout << "\n\t[ERROR] Queue is empty! No patients to process.\n";
                    break;
                }
                
                Patient processedPatient;
                if (queue.dequeue(processedPatient)) {
                    std::cout << "\n\t========================================\n";
                    std::cout << "\t   PATIENT PROCESSED SUCCESSFULLY\n";
                    std::cout << "\t========================================\n";
                    std::cout << "\tPatient ID:     " << processedPatient.patientID << "\n";
                    std::cout << "\tName:           " << processedPatient.name << "\n";
                    std::cout << "\tCondition:      " << processedPatient.condition << "\n";
                    std::cout << "\tAdmission Time: " << processedPatient.admissionTime << "\n";
                    std::cout << "\t========================================\n";
                } else {
                    std::cout << "\n\t[ERROR] Failed to process patient.\n";
                }
                break;
            }
            
            case 3: {  // View Front Patient
                if (queue.isEmpty()) {
                    std::cout << "\n\t[ERROR] Queue is empty! No front patient to view.\n";
                    break;
                }
                
                Patient frontPatient;
                if (queue.peek(frontPatient)) {
                    std::cout << "\n\t========================================\n";
                    std::cout << "\t   FRONT PATIENT IN QUEUE\n";
                    std::cout << "\t========================================\n";
                    std::cout << "\tPatient ID:     " << frontPatient.patientID << "\n";
                    std::cout << "\tName:           " << frontPatient.name << "\n";
                    std::cout << "\tCondition:      " << frontPatient.condition << "\n";
                    std::cout << "\tAdmission Time: " << frontPatient.admissionTime << "\n";
                    std::cout << "\t========================================\n";
                } else {
                    std::cout << "\n\t[ERROR] Failed to retrieve front patient.\n";
                }
                break;
            }
            
            case 4: {  // Display All Patients
                queue.display();
                break;
            }
            
            case 5: {  // Exit
                std::cout << "\n\t========================================\n";
                std::cout << "\t   THANK YOU FOR USING THE SYSTEM\n";
                std::cout << "\t========================================\n";
                std::cout << "\n\tExiting system...\n";
                running = false;
                break;
            }
            
            default: {
                std::cout << "\n\t[ERROR] Invalid choice! Please try again.\n";
                break;
            }
        }
        
        // Adding a pause before showing menu again
        if (running) {
            std::cout << "\n\tPress Enter to continue...";
            std::cin.get();
        }
    }
    
    return 0;
}
