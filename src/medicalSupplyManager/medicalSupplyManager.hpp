#pragma once
#include <stdexcept>

template <typename T>
class MedicalSupplyManager {
public:
    MedicalSupplyManager();
    ~MedicalSupplyManager();

    // Pushes a new item onto the top of the stack
    void push(const T& item);
    // Removes and returns the top item from the stack
    // Throws std::out_of_range if the stack is empty
    T pop();
    T top() const;
    bool isEmpty() const;
    int size() const;
private:
    T* data;
    int topIndex;
    int capacity;

    void resize();
};

template <typename T>
MedicalSupplyManager<T>::MedicalSupplyManager() {
    data = nullptr;
    topIndex = 0;
    capacity = 0;
}

template <typename T>
MedicalSupplyManager<T>::~MedicalSupplyManager(){
    delete[] data;
}

template <typename T>
void MedicalSupplyManager<T>::push(const T& item) {
    if(topIndex >= capacity){
        resize();
    }
    data[topIndex++] = item;
}

template <typename T>
T MedicalSupplyManager<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return data[--topIndex];
}

template <typename T>
T MedicalSupplyManager<T>::top() const {
    if(isEmpty()){
        throw std::out_of_range("Stack is empty");
    }
    return data[topIndex-1];
}

template <typename T>
bool MedicalSupplyManager<T>::isEmpty() const {
    return topIndex == 0;
}

template<typename T>
int MedicalSupplyManager<T>::size() const {
    return topIndex;
}

template <typename T>
void MedicalSupplyManager<T>::resize(){
    int newCapacity = (capacity == 0) ? 1 : capacity * 2;
    T* newData = new T[newCapacity];

    for(int i = 0; i < topIndex; ++i){
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}