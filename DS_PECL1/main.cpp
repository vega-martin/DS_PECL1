#include <iostream>
//#include <ctime>
//#include <random>
#include "Stack.hpp"
#include "Package.hpp"
//#include "Queue.hpp"
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
        case Status::OnItsWay:
			cout << "On Its Way";
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
    
	p2.setStatus(OnItsWay);
    cout << "P2 status: ";
    switch (p2.getStatus()) {
        case Status::CentralStation:
            cout << "At Central Station";
            break;
        case Status::Hub:
            cout << "At the Hub";
            break;
        case Status::OnItsWay:
            cout << "On Its Way";
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
    
	return 0;
}