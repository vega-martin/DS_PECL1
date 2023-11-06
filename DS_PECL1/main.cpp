#include <iostream>
#include "Package.hpp"
#include "Queue.hpp"
#include "Randomize.hpp"
#include "Central.hpp"
#include "Show.hpp"
using namespace std;

int main(){
    
	cout << "Yeah, it compiled!\n"<< endl;
    
    cout << "Package class tester\n"<< endl;
    
    //std::random_device rd;
    //std::mt19937 gen(rd());
    
    Package p1;
    
	cout << "P1 status: ";
    switch (p1.getStatus()) {
        case Status::CentralStation:
			cout << "At Central Station";
            break;
        case Status::Hub:
			cout << "At the Hub";
            break;
        case Status::Delivered:
            cout << "Delivered";
            break;
    }
    cout << endl;
    cout << "P1 client id: " << p1.getLabel().clientId << endl;
    cout << "P1 coordinates: " << p1.getLabel().coordinates.latitude << ", " << p1.getLabel().coordinates.longitude << ", " << p1.getLabel().coordinates.hub << endl;
    cout << "P1 client id: " << p1.getLabel().packageId << endl;
    
    
    Package p2;
    
	p2.setStatus(Delivered);
    cout << "P2 status: ";
    switch (p2.getStatus()) {
        case Status::CentralStation:
            cout << "At Central Station";
            break;
        case Status::Hub:
            cout << "At the Hub";
            break;
        case Status::Delivered:
            cout << "Delivered";
            break;
    }
    cout << endl;
    cout << "P2 client id: " << p2.getLabel().clientId << endl;
    cout << "P2 coordinates: " << p2.getLabel().coordinates.latitude << ", " << 
	p2.getLabel().coordinates.longitude << ", " << p2.getLabel().coordinates.hub << endl;
    cout << "P2 client id: " << p2.getLabel().packageId << endl;
    
	Package p3;
	cout << "\nQueue class tester\n"<< endl;
	
	Queue hub;
	cout << "this shoul be 1: " << hub.isEmpty() << endl;
	hub.insert(p1);
	cout << "this shoul be 0: " << hub.isEmpty() << endl;
	hub.insert(p2);
	hub.insert(p3);
	cout << "this shoul be 0: " << hub.isEmpty() << endl;
	hub.makeNull();
	cout << "this shoul be 1: " << hub.isEmpty() << endl;
    
	
	
	//Queue central;
	//no consigo hacer q gereneren los valores distintos...
	//he cambiado cosas en la clase Package de lo del random por si queires mirarlo
	cout << "\ncreating loads of packages\n" << endl;
	//randomize(5,central);
	
	Central centralStation;
	//centralStation.sendToHub();
	showCentralStation(centralStation);
	/*central.insert(p1);
	central.insert(p2);
	central.insert(p3);
	for(int i = 0; i<350; i++){
		Package p;
		central.insert(p);
	}
	
	Node *current = central.front;
	
	while(current != nullptr){
		std::cout << "package id: " << current->element.getLabel().packageId << endl;
		current = current->next;
	}*/
	
	return 0;
}