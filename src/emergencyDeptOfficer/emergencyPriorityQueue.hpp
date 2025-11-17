#ifndef EMERGENCY_PRIORITY_QUEUE_HPP
#define EMERGENCY_PRIORITY_QUEUE_HPP

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
    EmergencyPriorityQueue();

    ~EmergencyPriorityQueue();

    void logEmergencyCase(std::string name, std::string emergencyType, int priority);

    void processCriticalCase();

    void viewPendingCase() const;

    bool isEmpty() const;
};

#endif