#include <iostream>
#include <stdexcept>
#include "Stack.hpp"

template <typename T> // Explained in header

Stack::Stack(int capaity){
    this->capacity = capacity;
    element = new T[capacity];
    top = -1; 
}

// Function to insert elements in the Stack
void Stack::insert(const T &value){ // access the value by reference and make it read only with "const"
    if (top < capacity - 1){
        top++;
        element[top] = value;
    } else {
        throw std::overflow_error("Stack is full!!!");
    }
}

// Function to pop an element from the Stack (LIFO)
T Stack::extract(){
    if(top >= 0){
        return data[top--]; //devuelve data[top] y luego top--
    } else {
        throw std::underflow_error("Stack is empty!!!");
    }
}

// Function to determinte if the Stack is empty
bool Stack::isEmpty(){
    return top == -1;
}

bool Stack::isFull(){
    return top == capacity - 1;
}

void Stack::makeNull(){
    top = -1;
}