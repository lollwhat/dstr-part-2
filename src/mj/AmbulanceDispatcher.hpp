#include <string>

#include "Ambulance.hpp"
#include <string>

#define MAX_AMBULANCES 10

class AmbulanceDispatcher {
private:
    Ambulance queue[MAX_AMBULANCES];
    int front;
    int rear;
    int itemCount;
    int capacity;

public:
    AmbulanceDispatcher();
    bool isEmpty();
    bool isFull();
    void enqueue(Ambulance newAmbulance);
    Ambulance dequeue();
    
    void registerAmbulance(std::string id, std::string driver);
    void rotateAmbulanceShift();
    void displayAmbulanceSchedule();
};