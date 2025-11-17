#include <iostream>
#include "./AmbulanceDispatcher.hpp"

AmbulanceDispatcher::AmbulanceDispatcher() {
  front = -1;
  rear = -1;
  itemCount = 0;
  capacity = MAX_AMBULANCES;
}

bool AmbulanceDispatcher::isEmpty() {
  return itemCount == 0;
}

bool AmbulanceDispatcher::isFull() {
  return itemCount == capacity;
}

void AmbulanceDispatcher::enqueue(Ambulance newAmbulance) {
  if (isEmpty()) {
    front = 0;
  }

  rear = (rear + 1) % capacity;
  queue[rear] = newAmbulance;
  itemCount++;
}

Ambulance AmbulanceDispatcher::dequeue() {
  Ambulance frontAmbulance = queue[front];
  front = (front + 1) % capacity;
  itemCount--;

  if (isEmpty()) {
    front = -1;
    rear = -1;
  }

  return frontAmbulance;
}

void AmbulanceDispatcher::registerAmbulance(std::string driver) {
  if (isFull()) {
    std::cerr << "Hanger is full" << std::endl;
    return;
  }

  std::string id = "AMB-";
  if (nextIdCounter < 10) {
      id += "00" + std::to_string(nextIdCounter); // AMB-001
  } else if (nextIdCounter < 100) {
      id += "0" + std::to_string(nextIdCounter); // AMB-010
  } else {
      id += std::to_string(nextIdCounter); // AMB-100
  }
  nextIdCounter++;

  Ambulance newAmbulance(id, driver, "On-Duty");
  enqueue(newAmbulance);
  
  std::cout << "Ambulance " << id << " registered" << std::endl;
}

void AmbulanceDispatcher::rotateAmbulanceShift() {
  if (isEmpty()) {
    std::cerr << "No ambulances to rotate" << std::endl;
    return;
  }

  if (itemCount == 1) {
    std::cout << "Only one ambulance in shift; no rotation needed." << std::endl;
    return;
  }

  Ambulance rotatedAmbulance = dequeue();
  enqueue(rotatedAmbulance);

  std::cout << "Ambulance " << rotatedAmbulance.id << " dispatched and moved to end of queue." << std::endl;
}

void AmbulanceDispatcher::displayAmbulanceSchedule() {
  if (isEmpty()) {
    std::cout << "No ambulances in schedule." << std::endl;
    return;
  }

  int current = front;
  for (int i = 0; i < itemCount; ++i) {
    std::cout << queue[current].id;
    if (!queue[current].driverName.empty()) {
      std::cout << " - " << queue[current].driverName;
    }
    std::cout << std::endl;

    current = (current + 1) % capacity;
  }
}
