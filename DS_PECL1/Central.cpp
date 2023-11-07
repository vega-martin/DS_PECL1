#include "Central.hpp"
#include "Package.hpp"

//#define N1 3500

Central::Central(){
	for(int i = 0; i<3500; i++){
		Package p;
		centralQueue.insert(p);
	}
}

Package Central::sendToHub(){
	centralQueue.front->element.setStatus(Hub);
	return centralQueue.extract();
}