#ifndef QUEUE_HPP
#define QUEUE_HPP

template <typename T> //this way it works with any data type (just in case)

// this is the celltype
struct Node {
    T element;
    Node *next;
    /* Constructor del struct.
     * we access value by reference and use "const" to make it read only
     */
    Node(const T &value) : element(value), next(nullptr) {}
}

class Queue {

private:
    Node *front;
    Node *rear;
    
public:

    Queue();
    
    void insert(T);
    T extract();
    bool isEmpty();
    void makeNull();
    T fornt();

};

#endif // QUEUE_HPP
