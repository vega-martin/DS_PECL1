#include "Show.hpp"
#include "Central.hpp"
#include "Stack.hpp"
#include <iostream>
#include <iomanip>

void showCentralStation(Central central){
	Node *current = central.centralQueue.front;
	
	while(current != nullptr){
		std::cout << std::setw(13) << "Package id:" << std::setw(17) << current->element.getLabel().packageId <<
		std::setw(20) << "Package latitude:" << std::setw(12) << current->element.getLabel().coordinates.latitude <<
		std::setw(22) << "Package longitude:" << std::setw(12) << current->element.getLabel().coordinates.longitude <<
		std::setw(16) << "Package hub:" << std::setw(6) << current->element.getLabel().coordinates.hub[0] << current->element.getLabel().coordinates.hub[1] <<
		std::setw(14) << "Client ID:" << std::setw(13) << current->element.getLabel().clientId <<
		std::endl;
		current = current->next;
	}
}

void showHub(Stack hub){
	
}

void showPackage(){
	
}
