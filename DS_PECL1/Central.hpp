#ifndef CENTRAL_HPP
#define CENTRAL_HPP
#include "Queue.hpp"
#include "Package.hpp"
#include "Stack.hpp"

#define N1 3500
#define N2 73

class Central{
public:
	Queue centralQueue;
	Central();
	Package sendToHub();
    
    void packageExtraction(Stack& nw, Stack& ne, Stack& sw, Stack& se, Queue& nwq, Queue& neq, Queue& swq, Queue& seq);

};

#endif // CENTRAL_HPP
