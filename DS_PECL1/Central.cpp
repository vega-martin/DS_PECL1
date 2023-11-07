#include "Central.hpp"
#include "Package.hpp"
#include "Stack.hpp"
#include "Show.hpp"
#include <iostream>
using namespace std;

Central::Central(){
    
    // **  THIS CONSTRUCTOR TAKES CARE OF THE CENTRAL STATION'S PACKAGE GENERATION **
    
    // We were asked to fix the first two packages with our personal IDs:
    Package vega;
    Package adri;
   
    // Using a simple setter method:
    vega.setClientId("05955285X");
    adri.setClientId("03247820J");
    
    // We push these two packages into the Central Station Queue:
    centralQueue.insert(vega);
    centralQueue.insert(adri);
    
    // Now all random packages must be included after these two:
	for(int i = 0; i < N1 - 2; i++){
		Package p;
		centralQueue.insert(p);
	}
}

// The following method changes a package's status once it's sent to its corresponding hub:
Package Central::sendToHub(){
	centralQueue.front->element.setStatus(Hub);
	return centralQueue.extract();
}

bool Central::search(string labelID) {    
    bool b;
	if(!Central::centralQueue.isEmpty()){
		Node *current = Central::centralQueue.front;
		
		while(current != nullptr){
			
			if(current->element.getLabel().packageId ==labelID){
				b = true;
			}
			
			current = current->next;
		}
	} else {
		b = false;
	}
    return b;
}


void Central::packageExtraction(Stack& nw, Stack& ne, Stack& sw, Stack& se, Queue& nwq, Queue& neq, Queue& swq, Queue& seq){
    
    for (int i = 0; i < N2; i++) {
        
        if (!Central::centralQueue.isEmpty()){
            
            isAnyHubFull(nw, ne, sw, se, nwq, neq, swq, seq);

            Package packageToDeliver = Central::sendToHub();
            
            Label label = packageToDeliver.getLabel();
            
            string packageID = label.packageId;
            
            string zone = packageID.substr(packageID.length() - 2);
            
            if (zone == "NW"){
                nw.insert(packageToDeliver);
                continue;
            }
               
            else if (zone == "NE"){
                ne.insert(packageToDeliver);
                continue;    
            }
            
            else if (zone == "SW"){
                sw.insert(packageToDeliver);
                continue;    
            }
            
            else if (zone == "SE"){
                se.insert(packageToDeliver);
                continue;    
            }
        } 
        
        else {
            cout << "The Central Station has been emptied out!! There are no more packages to be delivered" << endl;
            return;
        }
    }
}
