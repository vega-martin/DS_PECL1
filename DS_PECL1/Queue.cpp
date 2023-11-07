#include <stdexcept>
#include "Queue.hpp"
#include "Package.hpp"

Queue::Queue() : front(nullptr), rear(nullptr) {}

bool Queue::isEmpty() const {
	return front == nullptr;
}

void Queue::insert(const Package &newPackage) {
	Node *newNode = new Node(newPackage);
	if (rear == nullptr) {
		front = rear = newNode;
	} else {
		rear->next = newNode;
		rear = newNode;
	}
}

Package Queue::extract(){
	if (isEmpty()) {
		throw std::underflow_error("Empty queue");
	} else {
	
        Package value = front->element;
        Node *temp = front;
        front = front->next;
        delete temp;
        
        if (front == nullptr) {
            rear = nullptr;
        }
        
        return value;
        
    }
}

void Queue::makeNull(){
	while (!isEmpty()) {
		extract();
	}
}

Package Queue::getFront() const {
	if (isEmpty()) {
		throw std::underflow_error("Empty queue");
	}
	return front->element;
}
