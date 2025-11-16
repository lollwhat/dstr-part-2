#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <string>

struct Case {
    std::string name;
    std::string emergencyType;
    int priority;
};

struct Node {
    Case data;
    Node *next;
};

class EmergencyPriorityQueue {
    private: 
    Node *head;

    public:
    EmergencyPriorityQueue() {
        head = nullptr;
    }

    ~EmergencyPriorityQueue() {
        while (head != nullptr) {
            processCriticalCase();
        }
    }

    void logEmergencyCase(std::string name, std::string emergencyType, int priority);

    void processCriticalCase();

    void viewPendingCase();

    bool isEmpty() {
        return head == nullptr;
    }
};

#endif