#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "Package.hpp"

//template <typename T> //this way it works with any data type (just in case)

// this is the celltype
struct Node {
    Package element;
    Node *next;
    /* Constructor del struct.
     * we access value by reference and use "const" to make it read only
     */
    Node(const Package &value) : element(value), next(nullptr) {}
};

class Queue {

private:
    Node *front;
    Node *rear;
    
public:

    Queue();
    
    void insert(Package);
    Package extract();
    bool isEmpty();
    void makeNull();
    Package getFront();

};

#endif // QUEUE_HPP