#ifndef PATIENTQUEUE_HPP
#define PATIENTQUEUE_HPP

#include "../models/Patient.hpp"
#include <string>

class PatientQueue {
private:
    static const int MAX_SIZE = 100;  // Maximum queue capacity
    Patient queue[MAX_SIZE];          // Array to store patients
    int front;                        // Index of front element
    int rear;                         // Index of rear element
    int count;                        // Current number of elements

public:

    PatientQueue();
    bool isEmpty() const; // Check if queue is empty
    bool isFull() const; // Check if queue is full
    int size() const; // Get current size of queue

    bool enqueue(const Patient& patient); // Add patient to the rear of queue (Enqueue operation)
    bool dequeue(Patient& patient); // Remove and return patient from front of queue (Dequeue operation)
    bool peek(Patient& patient) const; // View front patient without removing (Peek operation)
    void display() const; // Display all patients currently in queue
};

#endif

