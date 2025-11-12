#pragma once

template <typename T>
class CustomStack{
public:
    CustomStack();
    ~CustomStack();

    void push(const T& item);
    T pop();
    T top() const;
    void view() const;
    bool isEmpty() const;
    int size() const;
private:
    T* data;
    int topIndex;
    int capacity;

    void resize();
};

template <typename T>
CustomStack<T>::CustomStack() {
    data = nullptr;
    topIndex = 0;
    capacity = 0;
}

template <typename T>
CustomStack<T>::~CustomStack(){
    delete[] data;
}

template <typename T>
void CustomStack<T>::push(const T& item) {
    if(topIndex >= capacity){
        resize();
    }
    data[topIndex++] = item;
}

template <typename T>
T CustomStack<T>::pop() {
    return data[--topIndex];
}

template <typename T>
T CustomStack<T>::top() const {
    if(isEmpty()){
        throw std::out_of_range("Stack is empty");
    }
    return data[topIndex-1]; //Zero-based index
}

template <typename T>
void CustomStack<T>::view() const {
    for(int i = topIndex - 1; i >= 0; --i){
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
bool CustomStack<T>::isEmpty() const {
    return topIndex == 0;
}

template<typename T>
int CustomStack<T>::size() const {
    return topIndex;
}

template <typename T>
void CustomStack<T>::resize(){
    int newCapacity = (capacity == 0) ? 1 : capacity * 2;
    T* newData = new T[newCapacity];

    for(int i = 0; i < topIndex; ++i){
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}