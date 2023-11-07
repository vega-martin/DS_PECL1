#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "Package.hpp"

// As queues are implemented dynamically, we create celltypes:
struct Node {
    Package element;
    Node *next;
    /* Structs are no-method classes, but DO have a constructor.
     * We access values by reference and use "const" to make them read only */
     
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
    
    bool search(string labelId);
    
private: 
    Node *rear;
};

#endif // QUEUE_HPP
