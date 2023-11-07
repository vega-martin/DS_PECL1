#include "Stack.hpp"
#include "Central.hpp"
#include "Show.hpp"
using namespace std;

int main(){
    
    // Creation of the Central Station is done to begin with:
	Central central;
    
    // Creation of all four hubs is happening here:
	Stack NWHub;
	Stack NEHub;
	Stack SWHub;
	Stack SEHub;
    
    // Not including the following commands will result in some errors:
    NWHub.makeNull();
    NEHub.makeNull();
    SWHub.makeNull();
    SEHub.makeNull();
    
    // Every hub requires an extra queue to store all delivered packages:
    Queue NWHubQueue;
    Queue NEHubQueue;
    Queue SWHubQueue;
    Queue SEHubQueue;
    
    // Main menu is executed here, therefore the program begins:
	mainMenu(central, NWHub, NEHub, SWHub, SEHub, NWHubQueue, NEHubQueue, SWHubQueue, SEHubQueue); 
    // (in Show.hpp and Show.cpp)
    
    // As always, on any program we must include:
	return 0;
}