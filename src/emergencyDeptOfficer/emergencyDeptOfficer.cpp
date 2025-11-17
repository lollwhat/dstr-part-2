#include <iostream>
#include <string>

#include "emergencyPriorityQueue.hpp"
#include "emergencyDeptOfficer.hpp"

void showMenu() {  
    std::cout << "\n---------------------------------------------------" << std::endl;
    std::cout << "           EMERGENCY DEPARTMENT OFFICER MENU         " << std::endl;
    std::cout << " ---------------------------------------------------" << std::endl;
    std::cout << "1. Log Emergency Case\n";
    std::cout << "2. Process Most Critical Case\n";
    std::cout << "3. View Pending Emergency Cases\n";
    std::cout << "0. Exit\n";
    std::cout << "\nPlease Enter Your Choice (0~3): \n";
    

}

// Input data to LinkedList
void logNewCase(EmergencyPriorityQueue &queue) {
    std::string name, caseType, input;
    int priority;

    std::cout << "Enter Patient Name: " << std::endl;
    std::getline(std::cin, name);

    std::cout << "Enter Emergency Type ('Fracture', 'Cardiac'): " << std::endl;
    std::getline(std::cin, caseType);
    
    std::cout << "Enter Case Priority (0~5) (Higher Number = High Priority): " << std::endl;
    std::getline(std::cin, input);

    try{
        priority = std::stoi(input);

        if (priority < 0 || priority > 5) {
        std::cout << "Priority is out of range (0-5). Setting to 0." << std::endl;
        priority = 0;
    }
    }catch (const std::exception& e) {
        std::cout << "Invalid Priority, setting to 0." << std::endl;
        priority = 0; 
    }
    
    queue.logEmergencyCase(name, caseType, priority);
}

void emergencyOfficer() {
    EmergencyPriorityQueue EPQueue;

    int choice = -1 ;

    while (choice != 0) {
        showMenu();

        std::string input;
        std::getline(std::cin, input);

        try{
            choice = std::stoi(input);
        }
        catch(const std::exception& e)
        {
            std::cout << "Invalid input, enter a number." << std::endl;
            choice = -1;
        }
        
    
        switch (choice) {
            case 1:{
                logNewCase(EPQueue);
                break;
            }
            case 2:{
                EPQueue.processCriticalCase();
                break;
            }
            case 3:{
                EPQueue.viewPendingCase();
                break;
            }
        }
        std::cout << std::endl;
    }

}

EmergencyPriorityQueue::EmergencyPriorityQueue() {
    head = nullptr;
}

EmergencyPriorityQueue::~EmergencyPriorityQueue() {
    Node *temp = head;
    while (temp != nullptr) {
        head = head->next;
        delete temp;
        temp = head;
    }
    std::cout << "Emergency Queue Cleared" << std::endl;
}

void EmergencyPriorityQueue::logEmergencyCase(std::string name, std::string emergencyType, int priority) {
    Node *newNode = new Node;
    newNode->data.name = name;
    newNode->data.emergencyType = emergencyType;
    newNode->data.priority = priority;
    newNode->next = nullptr;

    // Empty Queue
    if (head == nullptr) {
        head = newNode;
        std::cout << "New case for " << name << " was added to empty queue." << std::endl;
        return;
    }

    // Priority Case
    if (priority > head->data.priority) {
        newNode->next = head;
        head = newNode;
        std::cout << "Critical Case of " << name << " added to front of queue" << std::endl; 
        return;
    }

    // Insert in Middle or End
    Node *current = head;
    Node *prev = nullptr;

    while (current != nullptr && current->data.priority >= priority) {
        prev = current;
        current = current->next;
    }

    newNode->next = current;
    prev->next = newNode; 

    std::cout << "Case for " << name << " added in priority order." << std::endl;
};

void EmergencyPriorityQueue::processCriticalCase() {
    if(isEmpty()) {
        std::cout << "No emergency case to process." << std::endl;
        return;
    }

    Node *temp = head;

    std::string processedName = temp->data.name;
    int processedPriority = temp->data.priority;

    head = head->next;

    delete temp;

    std::cout << "Processing most critical case: " << processedName << " (Priority: " << processedPriority << ")" << std::endl;
    std::cout << " --- Case Successfully Processed --- " << std::endl;
}

void EmergencyPriorityQueue::viewPendingCase() const {
    if (isEmpty()) {
        std::cout << "No pending emergency cases." << std::endl;
        return;
    }

    Node *current = head;
    int count = 1;

    std::cout << "\n --- Pending Emergency Cases by Priority ---" << std::endl;

    while (current != nullptr) {
        std::cout << count << ". " << "Priority: " << current->data.priority << "\n Name: " << current->data.name << "\n Case: " << current->data.emergencyType << std::endl;

        current = current->next;
        count++;
    }

    std::cout << "----------------------------------------------" << std::endl;

}

bool EmergencyPriorityQueue::isEmpty() const {
    return head == nullptr;
}