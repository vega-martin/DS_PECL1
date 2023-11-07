#include <stdexcept>
#include "Stack.hpp"
using namespace std;

Stack::Stack() {
    top = MAX_CAPACITY; // Initialize top to the maximum capacity
}

// Method to insert elements in the stack = PUSH
void Stack::insert(const Package &package) {
    if (top > 0) {
        elements[--top] = package;
    } else {
        throw overflow_error("Stack is full!!!");
    }
}

// Method to remove an element from the Stack = POP
Package Stack::extract() {
    if (top < MAX_CAPACITY) {
        return elements[top++];
    } else {
        throw underflow_error("Stack is empty!!!");
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

// THE FOLLOWING METHOD IS OUTSIDE OF OUR STANDARD STACK IMPLEMENTATION: REQUIRED BY THE PROGRAM'S SPECS
// AND OUR OWN NEEDS:

bool Stack::search(string labelId){
    bool b;
    if(!Stack::isEmpty()){  
        for(int i = Stack::top ; i < N3 + 1; i++){
            if(Stack::elements[i].getLabel().packageId == labelId){
                b = true;
            }
        }
    }  
    else {
        b = false;
    }
    return b;
}