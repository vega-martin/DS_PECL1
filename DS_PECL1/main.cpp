#include <iostream>
#include <ctime>
#include <random>
#include "Stack.hpp"
#include "Package.hpp"
//#include "Queue.hpp"

int main(){
    
	std::cout << "Yeah, it compiled!\n"<<std::endl;
    
    std::cout << "Package class tester\n"<<std::endl;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    
    Package p1;
    
    std::cout << "P1 status: ";
    switch (p1.getStatus()) {
        case Status::CentralStation:
            std::cout << "At Central Station";
            break;
        case Status::Hub:
            std::cout << "At the Hub";
            break;
        case Status::OnItsWay:
            std::cout << "On Its Way";
            break;
        case Status::Delivered:
            std::cout << "Delivered";
            break;
    }
    std::cout << std::endl;
    std::cout << "P1 client id: " << p1.getLabel().clientId << std::endl;
    std::cout << "P1 coordinates: " << p1.getLabel().coordinates.latitude << ", " << p1.getLabel().coordinates.longitude << ", " << p1.getLabel().coordinates.hub << std::endl;
    std::cout << "P1 client id: " << p1.getLabel().packageId << std::endl;
    
    
    Package p2;
    
    std::cout << "P2 status: ";
    switch (p2.getStatus()) {
        case Status::CentralStation:
            std::cout << "At Central Station";
            break;
        case Status::Hub:
            std::cout << "At the Hub";
            break;
        case Status::OnItsWay:
            std::cout << "On Its Way";
            break;
        case Status::Delivered:
            std::cout << "Delivered";
            break;
    }
    std::cout << std::endl;
    std::cout << "P2 client id: " << p2.getLabel().clientId << std::endl;
    std::cout << "P2 coordinates: " << p2.getLabel().coordinates.latitude << ", " << p2.getLabel().coordinates.longitude << ", " << p2.getLabel().coordinates.hub << std::endl;
    std::cout << "P2 client id: " << p2.getLabel().packageId << std::endl;
    
    std::cout << "Stack class tester\n"<<std::endl;
    
    
    
	return 0;
}
