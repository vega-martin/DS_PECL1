#ifndef STACK_HPP
#define STACK_HPP

template <typename T> //this way it works with any data type (just in case)

class Stack {

private:
    T *element;
    int capacity; // max capacity of the stack
    int top; // Inde of the top element of the stack

public:

    Stack(int capacity);
    
    void insert(T);
    T extract();
    bool isEmpty();
    bool isFull();
    void makeNull();

};

#endif // STACK_HPP
