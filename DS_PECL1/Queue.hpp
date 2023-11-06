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


    
public:

	Node *front;

    Queue();
    
    void insert(const Package &newPackage);
    Package extract();
    bool isEmpty() const;
    void makeNull();
    Package getFront() const;
private:
    
    Node *rear;
};

#endif // QUEUE_HPP
