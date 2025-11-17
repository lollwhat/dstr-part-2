#include "../../Header/queue/PatientQueue.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PatientQueue::PatientQueue() {
    front = 0;
    rear = -1;
    count = 0;
}

// Check if queue is empty
bool PatientQueue::isEmpty() const {
    return count == 0;
}

// Check if queue is full
bool PatientQueue::isFull() const {
    return rear == MAX_SIZE - 1;
}

// Get current size of queue
int PatientQueue::size() const {
    return count;
}

// Add patient to the rear of queue (Enqueue operation)
bool PatientQueue::enqueue(const Patient& patient) {
    if (isFull()) {
        return false;
    }

    rear++;
    queue[rear] = patient;
    count++;
    return true;
}

// Remove and return patient from front of queue (Dequeue operation)
bool PatientQueue::dequeue(Patient& patient) {
    if (isEmpty()) {
        return false;
    }

    // Get front patient
    patient = queue[front];

    // Shift all elements to the left by 1
    for (int i = 0; i < rear; i++) {
        queue[i] = queue[i + 1];
    }

    // Update rear and count
    rear--;
    count--;

    return true;
}

// View front patient without removing (Peek operation)
bool PatientQueue::peek(Patient& patient) const {
    if (isEmpty()) {
        return false;
    }

    patient = queue[front];
    return true;
}

// Display all patients currently in queue
void PatientQueue::display() const {
    if (isEmpty()) {
        std::cout << "\n\tQueue is empty. No patients waiting.\n";
        return;
    }
    
    std::cout << "\n\t========================================\n";
    std::cout << "\t   PATIENTS IN QUEUE (Total: " << count << ")\n";
    std::cout << "\t========================================\n";
    std::cout << std::left << std::setw(12) << "Position" 
              << std::setw(15) << "Patient ID" 
              << std::setw(25) << "Name" 
              << std::setw(20) << "Condition"
              << std::setw(20) << "Admission Time" << std::endl;
    std::cout << "----------------------------------------------------------------------------\n";
    
    int index = front;
    int position = 1;
    
    for (int i = 0; i < count; i++) {
        std::cout << std::left << std::setw(12) << ("#" + std::to_string(position))
                  << std::setw(15) << queue[index].patientID
                  << std::setw(25) << queue[index].name
                  << std::setw(20) << queue[index].condition
                  << std::setw(20) << queue[index].admissionTime << std::endl;
        
        index = (index + 1) % MAX_SIZE;
        position++;
    }
    std::cout << "----------------------------------------------------------------------------\n";
}

