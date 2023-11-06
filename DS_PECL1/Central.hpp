#ifndef CENTRAL_HPP
#define CENTRAL_HPP
#include "Queue.hpp"
#include "Package.hpp"

class Central{
public:
	Queue centralQueue;
	Central();
	Package sendToHub();

};

#endif // CENTRAL_HPP
