//#include "Queue.hpp"
//#include "Package.hpp"
//#include <iostream>
#include <random>
using namespace std;
/*
bool verify(Package package, Queue &queue){
	Node *current = queue.front;
	
	while(current != nullptr){
		if((current->element.getLabel().packageId == package.getLabel().packageId) &&
        (current->element.getLabel().coordinates.latitude == package.getLabel().coordinates.latitude) &&
		(current->element.getLabel().coordinates.longitude == package.getLabel().coordinates.longitude) &&
        (current->element.getLabel().clientId == package.getLabel().clientId)){
			//cout << "package id in the queue" << endl;
			return true;
		}
		//cout << "package id is not in the queue" << endl;
		current = current->next;
	}
	return false;
}

void randomize(int n, Queue queue) {
	if (queue.isEmpty()) {
		Package p = Package();
		queue.insert(p);
	}
	for (int i = 0; i < n; i++) {
		Package p = Package();
		while (verify(p, queue)) {
			p = Package();
		}
		queue.insert(p);
		cout << queue.getFront().getLabel().coordinates.hub << ", " << queue.getFront().getLabel().packageId << ", " << queue.getFront().getLabel().clientId << endl;
	}
}*/

thread_local std::mt19937 gen(std::random_device{}());

int randNumber(){
    uniform_int_distribution<int> distribution(0, 9);
    int randomNumber = distribution(gen);
    return randomNumber;
}

char randLetter(){
	uniform_int_distribution<int> distribution(0, 25);
	int randomIndex = distribution(gen);
	char alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char letter = alphabet[randomIndex];
	return letter;
}