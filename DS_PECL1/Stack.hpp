#ifndef STACK_HPP
#define STACK_HPP
#include "Package.hpp"

//#define N3 24

/* THINGS TO TAKE INTO CONSIDERATION ABOUT THIS STACK IMPLEMENTATION:
 * 
 * STATIC / ARRAY IMPLEMENTATION: STACK SIZE WILL BE FIXED
 * 
 * AS SEEN IN THE THEORY LESSONS' SLIDES,
 * 
 * THE BOTTOM OF THE STACK IS ANCHORED AT THE BOTTOM OF THE ARRAY (HIGH-INDEXED END  -> MAX_CAPACITY)
 * 
 * AND THE STACK GROWS TOWARDS THE TOP OF TE ARRAY (LOW-INDEXED END -> 0)
 */

class Stack {

private:

    static const int MAX_CAPACITY = 24; // Vans' max capacity, established by the PDF
    

public:

    Package elements[MAX_CAPACITY]; // Static array for storing elements (packages)
    int top; // Index of the top element of the stack

    Stack(); // No need to pass capacity as a parameter: its size is fixed

    void insert(const Package &package);
    Package extract();
    bool isEmpty() const;
    bool isFull() const;
    void makeNull();

};

#endif // STACK_HPP

