#include "Stack.hpp"

template <typename T> // Explained in header

/* --> I think we don't need this
Stack::Stack()
{
}

Stack::~Stack()
{
}
*/

// Function to insert elements in the Stack
void Stack::insert(T value){
    Node *newElement = new Node(value);
    (*newElement).next = theTop;
    /* apparently this is the way to access a member of a struct
     * when referended. The way newElement.next is valid only for objects
     * another way would be newElement->next=theTop;
     * */
    theTop = newElement;
}

// Function to pop an element from the Stack (LIFO)
T Stack::extract(){
    if(isEmpty){
        std::cout << "Watch it! Empty Stack." << std:endl;
    } else {
        Node auxPointer; // Declare an auxiliary pointer
        T auxVar; // Declare an auxiliary variable
        auxPointer = theTop; // auxPointer now point to the top of the Stack
        theTop = (*auxPointer).next; // theTop moves to the next element
        auxVar = (*auxPointer).element; // Store the element we are poping into auxVar
        delete auxPointer; // Delete the auxiliary pointer
        return auxVar;
    }
}

/* --> IDK if we are going to need this or not
// Function to show the elements od the stack
void Stack::show(){
    
}*/

// Function to determinte if the Stack is empty
bool Stack::isEmpty(){
    return theTop == nullptr; //theTop is a null pointer (pointing to a null value)?
}
