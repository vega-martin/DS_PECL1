#ifndef STACK_HPP
#define STACK_HPP
#include "Package.hpp"

//template <typename T> //this way it works with any data type (just in case)

class Stack {

private:
    Package *elements;
    int capacity; // max capacity of the stack
    int top; // Inde of the top element of the stack

public:

    Stack(int capacity);
    
    void insert(const Package &package);
    Package extract();
    bool isEmpty() const;
    bool isFull() const;
    void makeNull();

};

#endif // STACK_HPP
