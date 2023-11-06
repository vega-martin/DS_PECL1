#include "Queue.hpp"
#include "Package.hpp"
#include <iostream>
#include <random>
using namespace std;

/*Randomize::Randomize(int n, Queue queue){
	for(int i = 0; i < n; i++){
		Package p;
		bool isOnQueue = verify(p, queue);
		while(isOnQueue){
			p = Package();
		}
		//if(verify(p, queue)){Package p;}
		queue.insert(p);
		cout << queue.getFront().getLabel().coordinates.hub << ", " << queue.getFront().getLabel().packageId << ", " << queue.getFront().getLabel().clientId << endl;
	}
}
*/
bool verify(Package package, Queue &queue){
	Node *current = queue.front;
	
	while(current != nullptr){
		if((current->element.getLabel().packageId == package.getLabel().packageId) &&
        (current->element.getLabel().coordinates.latitude == package.getLabel().coordinates.latitude) &&
		(current->element.getLabel().coordinates.longitude == package.getLabel().coordinates.longitude) &&
        (current->element.getLabel().clientId == package.getLabel().clientId)){
			cout << "package id in the queue" << endl;
			return true;
		}
		cout << "package id is not in the queue" << endl;
		current = current->next;
	}
	return false;
}
void randomize(int n, Queue queue) {
    if (queue.isEmpty()) {
      queue.insert(Package());
    }
    for (int i = 0; i < n; i++) {
      Package p = Package();
      while (verify(p, queue)) {
        p = Package();
		queue.insert(p);
      }
      queue.insert(p);
      cout << queue.getFront().getLabel().coordinates.hub << ", " << queue.getFront().getLabel().packageId << ", " << queue.getFront().getLabel().clientId << endl;
    }
  }
/*
Randomize::Randomize(int n, Queue queue) {
    for (int i = 0; i < n; i++) {
      Package p = Package();
      while (p.getLabel().packageId == queue.getFront().getLabel().packageId) {
        p = Package();
      }
      queue.insert(p);
      cout << queue.getFront().getLabel().coordinates.hub << ", " << queue.getFront().getLabel().packageId << ", " << queue.getFront().getLabel().clientId << endl;
    }
  }
void randomize(int n, Queue queue) {
    if (queue.isEmpty()) {
		
		queue.insert(Package());
		cout << "hola1" << endl;
		cout << queue.getFront().getLabel().coordinates.hub << ", " << queue.getFront().getLabel().packageId << ", " << queue.getFront().getLabel().clientId << endl;
    
    }
    for (int i = 0; i < n; i++) {
		Package p = Package();
		cout << "hola" << endl;
		while (p.getLabel().packageId == queue.getFront().getLabel().packageId) {
			cout << "its in the queue" << endl;
			p = Package();
		}
		cout << "adiose" << endl;
		queue.insert(p);
		cout << queue.getFront().getLabel().coordinates.hub << ", " << queue.getFront().getLabel().packageId << ", " << queue.getFront().getLabel().clientId << endl;
	}
}*/
thread_local std::mt19937 gen(std::random_device{}());

char randNumber(){
	uniform_int_distribution<int> distribution(0, 8);
	int randomIndex = distribution(gen);
	char numbers[] = {'0','1','2','3','4','5','6','7','8','9'};
	char number = numbers[randomIndex];
	return number;
}

char randLetter(){
	uniform_int_distribution<int> distribution(0, 25);
	int randomIndex = distribution(gen);
	char alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char letter = alphabet[randomIndex];
	return letter;
}