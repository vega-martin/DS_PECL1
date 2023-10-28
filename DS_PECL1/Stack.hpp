#ifndef STACK_HPP
#define STACK_HPP

template <typename T> //this way it works with any data type (just in case)

class Stack {
    
private:
    struct Node {
          T element;
          Node *next;
          /* Constructor (yes, I looked it up on the internet XD)
           * (pass the value by reference otherwise it won't work)
           * (we start setting the next pointer to null and then change it if needed)
           * */
          Node(const T &value) : element(value), next(nullptr) {}
    };
    
    Node *theTop;

public:
    /* Constructor
     * we only initialyze the theTop pointer to NULL,
     * so there's no need to add a body to the constructor
     * */
    Stack() : theTop(NULL){}
    //~Stack();  Destructor of the Strack --> we don't really need it
    
    void insert(T); //pushing elements in the stack
    T extract(); // pulling elements from the stack (i used T bcause I don't know the data type)
    void show(); // Show the elements of the stack --> Are we going to use this?
    bool isEmpty();
    //T top() IDK if this is going to be use TBH

};

#endif // STACK_HPP
