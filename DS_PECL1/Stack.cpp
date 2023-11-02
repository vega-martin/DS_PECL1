#include <iostream>
#include <stdexcept>
#include "Stack.hpp"

//template <typename T> // Explained in header

Stack::Stack(int capacity){
    this->capacity = capacity;
    elements = new Package[capacity];
    top = capacity + 1; 
}

// Function to insert elements in the Stack
void Stack::insert(const Package &value){ // access the value by reference and make it read only with "const"
    if (top > 1){
        top--;
        elements[top] = value;
    } else {
        throw std::overflow_error("Stack is full!!!");
    }
}

// Function to pop an element from the Stack (LIFO)
Package Stack::extract(){
    if(top <= capacity){
        return elements[top++]; //devuelve data[top] y luego top++
    } else {
        throw std::underflow_error("Stack is empty!!!");
    }
}

// Function to determinte if the Stack is empty
bool Stack::isEmpty() const {
    return (top >= capacity) ? true : false; // if top equal o greater than capacity retuns true else return false
}

bool Stack::isFull() const {
    return (top == 1) ? true : false; // if top equals to 1 retuns true (it is full) else return false
}

void Stack::makeNull(){
    top = capacity + 1;
}