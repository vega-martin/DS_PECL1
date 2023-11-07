#include "Stack.hpp"
#include "Central.hpp"
#include "Show.hpp"
using namespace std;

int main(){
    
    // Creation of the Central Station is done to begin with:s
	Central central; // In Central.hpp and Central.cpp
    
    // Creation of all four hubs is happening here:
	Stack NWHub; // In Stack.hpp and Stack.cpp
	Stack NEHub;
	Stack SWHub;
	Stack SEHub;
    
    // Not including the following commands will result in some errors:
    NWHub.makeNull();
    NEHub.makeNull();
    SWHub.makeNull();
    SEHub.makeNull();
    
    
    //test:
    /*Package p1;
    Package p4;
    Package p3;
    Package p2;
    
    NWHub.insert(p1);
    NWHub.insert(p2);
    NWHub.insert(p3);
    NWHub.insert(p4);

    showHub(NWHub);*/ //esto va bien
    
    // Every hub requires an extra queue to store all delivered packages:
    Queue NWHubQueue;
    Queue NEHubQueue;
    Queue SWHubQueue;
    Queue SEHubQueue;
    
    /*NWHubQueue.insert(p1);
    NWHubQueue.insert(p2);
    NWHubQueue.insert(p3);
    NWHubQueue.insert(p4);
    
    Package extracted;
    extracted = NWHubQueue.extract();
    Label label = extracted.getLabel();
    
    
    cout << label.packageId << "\n";
    
    Package centralEstracted = central.sendToHub();
    cout << centralEstracted.getLabel().packageId << "\n";*/
    
    // Main menu is executed here, hence the program begins functioning:
	mainMenu(central, NWHub, NEHub, SWHub, SEHub, NWHubQueue, NEHubQueue, SWHubQueue, SEHubQueue); // In Show.hpp and Show.cpp
    
    // As always, on any program we must include:
	return 0;
}