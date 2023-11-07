#include "Show.hpp"
#include "Central.hpp"
#include "Stack.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

void emptyFilledHub(Stack& hub, Queue& hubQueue) {
    while (!hub.isEmpty()) {
        hub.elements[hub.top].setStatus(Delivered);
        hubQueue.insert(hub.extract());  
    }
}

void packageExtraction(Central& c, Stack& nw, Stack& ne, Stack& sw, Stack& se, Queue& nwq, Queue& neq, Queue& swq, Queue& seq){
    
    for (int i = 0; i < 73; i++) {
        
        if (!c.centralQueue.isEmpty()){
            
            isAnyHubFull(nw, ne, sw, se, nwq, neq, swq, seq);

            Package packageToDeliver = c.sendToHub();
            
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


void mainMenu(Central& c, Stack& nw, Stack& ne, Stack& sw, Stack& se, Queue& nwq, Queue& neq, Queue& swq, Queue& seq){
	int action;
	
	cout << std::setw(100) << "-------------------------------------   WELCOME TO THE PARCEL SERVICE SIMULATOR   -------------------------------------" << endl;
	
	do{
		cout << endl;
		cout << "MENU (enter a number to choose an action):" << endl;
		cout << " 1. Locate a package" << endl;
		cout << " 2. Visualize packages" << endl;
		cout << " 3. Advance one step" << endl;
		cout << " 4. Exit\n" << endl;
		cout << "Enter a number: " << endl;
		cin >> action;
		cout << endl;
		
		string label;
		switch(action){
			case 1:
				cout << "Introduce the label of the package you are looking for:" << endl;
				getline(cin >> ws, label);
				cout << endl;
				showPackage(label, c, nw, ne, sw, se, nwq, neq, swq, seq);
				break;
                
            case 2:
                showMenu(c, nw, ne, sw, se, nwq, neq, swq, seq);
                break;
                
            case 3:
                      
                // PACKAGE EXTRACTION SHOULD HAPPEN NOW:    
                packageExtraction(c, nw, ne, sw, se, nwq, neq, swq, seq);    
                cout << "73 packages have been extracted from the Central Station" << endl;
                break;
				
			case 4:
				cout << "Good bye!" << endl;
				return;
			default:
                system("cls");
				cout << "Invalid choice"<< endl;
				break;
		}
	} while (action != 4);
}



void showMenu(Central& c, Stack& nw, Stack& ne, Stack& sw, Stack& se, Queue& nwq, Queue& neq, Queue& swq, Queue& seq){
	int action;
	do{
		cout << "Where do you want to show the packages from?" << endl;
		cout << " 1. Show Packages at the Central Station" << endl;
		cout << " 2. Show Packages at the NW Hub" << endl;
		cout << " 3. Show Packages at the NE Hub" << endl;
		cout << " 4. Show Packages at the SW Hub" << endl;
		cout << " 5. Show Packages at the SE Hub" << endl;
		cout << " 6. Go back\n" << endl;
		cout << "Enter a number: " << endl;
		cin >> action;
		cout << endl;
		
		switch(action){
			case 1:
				showCentralStation(c);
				break;
			case 2:
				showHub(nw);
				break;
			case 3:
				showHub(ne);
				break;
			case 4:
				showHub(sw);
				break;
			case 5:
				showHub(se);
				break;
			case 6:
				break;
			default:
				cout << "Invalid choice"<< endl;
				break;
		}
		
	}while(action != 6);
	mainMenu(c, nw, ne, sw, se, nwq, neq, swq, seq);
}



void showCentralStation(Central& central){
	if(!central.centralQueue.isEmpty()){
		Node *current = central.centralQueue.front;
		
		while(current != nullptr){
			cout << std::setw(11) << "Package id:" << setw(17) << current->element.getLabel().packageId <<
			setw(20) << "Package latitude:" << setw(12) << current->element.getLabel().coordinates.latitude <<
			setw(22) << "Package longitude:" << setw(12) << current->element.getLabel().coordinates.longitude <<
			setw(16) << "Package hub:" << setw(6) << current->element.getLabel().coordinates.hub[0] << current->element.getLabel().coordinates.hub[1] <<
			setw(14) << "Client ID:" << setw(13) << current->element.getLabel().clientId <<
            "       status  " << current->element.getStatus() << endl;
			current = current->next;
		}
	} else {
		cout << "UPPS! There's nothing to show over here." << endl;
	}
}



void showHub(Stack hub){
	if(!hub.isEmpty()){
		for(int i = hub.top ; i < N3; i++){
			cout << std::setw(11) << "Package id:" << setw(17) << hub.elements[i].getLabel().packageId <<
			setw(20) << "Package latitude:" << setw(12) << hub.elements[i].getLabel().coordinates.latitude <<
			setw(22) << "Package longitude:" << setw(12) << hub.elements[i].getLabel().coordinates.longitude <<
			setw(16) << "Package hub:" << setw(6) << hub.elements[i].getLabel().coordinates.hub[0] << hub.elements[i].getLabel().coordinates.hub[1] <<
			setw(14) << "Client ID:" << setw(13) << hub.elements[i].getLabel().clientId <<
			endl;
		}
	}  else {
		cout << "OOPS! There's nothing to show over here." << endl;
	}
}



void showPackage(string labelID, Central c, Stack nw, Stack ne, Stack sw, Stack se, Queue nwq, Queue neq, Queue swq, Queue seq){
	
	bool found;
    found = searchInCentral(labelID, c); // Check if it is in the Central Station
	
	if (found){
		cout << "Your package is in the Central Station" << endl;
	} else {
		
		if((labelID.substr(labelID.length() - 2)) == "NW") { // Check hub from label
		
			found = searchInStack(labelID, nw);
			if (found){
				cout << "Your package is being processed at the Hub NW." << endl;
			} else {
				found = searchInQueue(labelID, nwq);
				if (found){
					cout << "Your package has been delivered" << endl;
                }
			}
		
		} else if ((labelID.substr(labelID.length() - 2)) == "NE") { // Check hub from label
		
			found = searchInStack(labelID, ne);
			if (found){
				cout << "Your package is being processed at the Hub NE" << endl;
			} else {
				found = searchInQueue(labelID, neq);
				if (found){
					cout << "Your package has been delivered" << endl;
				}
			}
		
		} else if ((labelID.substr(labelID.length() - 2)) == "SW") { // Check hub from label
		
			found = searchInStack(labelID, sw);
			if (found){
				cout << "Your package is being processed at the Hub SW" << endl;
			} else {
				found = searchInQueue(labelID, swq);
				if (found){
					cout << "Your package has been delivered" << endl;
				}
			}
		
		} else if ((labelID.substr(labelID.length() - 2)) == "SE") { // Check hub from label
		
			found = searchInStack(labelID, se);
			if (found){
				cout << "Your package is being processed at the Hub SE" << endl;
			} else {
				found = searchInQueue(labelID, seq);
				if (found){
					cout << "Your package has been delivered" << endl;
				}
			}
		
		} else {
            cout << "Your package has not been found. Check if there are any spelling errors." << endl;
        }
		
	}
}


bool searchInCentral(string labelID, Central c) {
    
    bool b;
	if(!c.centralQueue.isEmpty()){
		Node *current = c.centralQueue.front;
		
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


bool searchInQueue(string labelID, Queue q){
    bool b;
	if(!q.isEmpty()){
		Node *current = q.front;
		
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


bool searchInStack(string labelID, Stack s){
    bool b;
	if(!s.isEmpty()){
		for(int i = s.top ; i < N3 + 1; i++){
			if(s.elements[i].getLabel().packageId == labelID){
				b = true;
			}
		}
	}  else {
		b = false;
	}
    return b;
}

void isAnyHubFull(Stack& nw, Stack& ne, Stack& sw, Stack& se, Queue& nwq, Queue& neq, Queue& swq, Queue& seq){
    
                // THIS METHOD EVALUATES WHETHER ANY HUBS ARE FULL
                // IN THAT CASE, ALL OF THE PACKAGES WILL BE RE-STATUSED AS "DELIVERED" AND WILL LEAVE THE HUB
                  
                if (nw.isFull()){
                    emptyFilledHub(nw, nwq);
                    cout << "THE NW HUB HAS BEEN FILLED UP. ALL PACKAGES INSIDE WILL BE DELIVERED NOW" << endl;
                }
                
                if (ne.isFull()){
                    emptyFilledHub(ne, neq);
                    cout << "THE NE HUB HAS BEEN FILLED UP. ALL PACKAGES INSIDE WILL BE DELIVERED NOW" << endl;
                }
                    
                if (sw.isFull()){
                    emptyFilledHub(sw, swq);
                    cout << "THE SW HUB HAS BEEN FILLED UP. ALL PACKAGES INSIDE WILL BE DELIVERED NOW" << endl;
                }
                    
                if (se.isFull()){
                    emptyFilledHub(se, seq);
                    cout << "THE SE HUB HAS BEEN FILLED UP. ALL PACKAGES INSIDE WILL BE DELIVERED NOW" << endl;
                }
}

