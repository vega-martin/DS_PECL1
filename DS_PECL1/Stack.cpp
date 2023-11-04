#include <stdexcept>
#include "Stack.hpp"

Stack::Stack() {
    top = MAX_CAPACITY; // Initialize top to the maximum capacity
}

// Method to insert elements in the stack = PUSH
void Stack::insert(const Package &package) {
    if (top > 0) {
        elements[--top] = package;
    } else {
        throw std::overflow_error("Stack is full!!!");
    }
}

// Method to remove an element from the Stack = POP
Package Stack::extract() {
    if (top < MAX_CAPACITY) {
        return elements[top++];
    } else {
        throw std::underflow_error("Stack is empty!!!");
    }
}

//Method that checks whether a stack is empty:
bool Stack::isEmpty() const {
    return (top == MAX_CAPACITY);
}

// Method that checks whether a stack is full:
bool Stack::isFull() const {
    return (top == 0);
}

// Method that empties a stack:
void Stack::makeNull() {
    top = MAX_CAPACITY;
}