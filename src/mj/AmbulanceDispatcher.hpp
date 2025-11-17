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
  int nextIdCounter;
  void addNewAmbulance(std::string driverName);

public:
  AmbulanceDispatcher();
  bool isEmpty();
  bool isFull();
  void enqueue(Ambulance newAmbulance);
  Ambulance dequeue();
  
  void registerAmbulance_Manual(std::string driver);
  void registerAmbulance_Batch(int count);
  void rotateAmbulanceShift();
  void displayAmbulanceSchedule();
};