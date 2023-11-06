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

void mainMenu(Central c, Stack nw, Stack ne, Stack sw, Stack se, Queue nwq, Queue neq, Queue swq, Queue seq){
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
		
		switch(action){
			case 1:
				//falta codigo codigo para esta parte
				break;
                
            case 2:
                showMenu(c, nw, ne, sw, se, nwq, neq, swq, seq);
                break;
                
            case 3:
				//no lo he pensado muy bn xddd
				/*supongo q aqui puedo llamar al metodo/s para distribuir los
				 * paquetes desde la central. y si algun hub tiene 24 paquetes
				 * q los envie (cambiar status)*/
				 /*creo q lo mejor es hacerlo de la siguiente manera:
				  * 1º evaluar si hay lgun hub lleno (así la 1ª estan todos vacios)
				  * 2º vaciar el hub q este lleno (así la 1ª no hace nada)
				  * 3º sacar lo 73 paquetes de la central y llevarlos  los hubs correspondientes
				  * creo q es una buena lógica no?...ahora solo falta implementarla xd*/
                  
                if (nw.isFull())
                    emptyFilledHub(nw, nwq);
                
				break;
			case 4:
				cout << "Good bye!" << endl;
				break;
			default:
                system("cls");
				cout << "Invalid choice"<< endl;
				break;
		}
	} while (action != 4);
}



void showMenu(Central c, Stack nw, Stack ne, Stack sw, Stack se, Queue nwq, Queue neq, Queue swq, Queue seq){
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



void showCentralStation(Central central){
	if(!central.centralQueue.isEmpty()){
		Node *current = central.centralQueue.front;
		
		while(current != nullptr){
			cout << std::setw(11) << "Package id:" << setw(17) << current->element.getLabel().packageId <<
			setw(20) << "Package latitude:" << setw(12) << current->element.getLabel().coordinates.latitude <<
			setw(22) << "Package longitude:" << setw(12) << current->element.getLabel().coordinates.longitude <<
			setw(16) << "Package hub:" << setw(6) << current->element.getLabel().coordinates.hub[0] << current->element.getLabel().coordinates.hub[1] <<
			setw(14) << "Client ID:" << setw(13) << current->element.getLabel().clientId <<
			endl;
			current = current->next;
		}
	} else {
		cout << "UPPS! There's nothing to show over here." << endl;
	}
}



void showHub(Stack hub){
	if(!hub.isEmpty()){
		for(int i = hub.top ; i < 24 + 1; i++){
			cout << std::setw(11) << "Package id:" << setw(17) << hub.elements[i].getLabel().packageId <<
			setw(20) << "Package latitude:" << setw(12) << hub.elements[i].getLabel().coordinates.latitude <<
			setw(22) << "Package longitude:" << setw(12) << hub.elements[i].getLabel().coordinates.longitude <<
			setw(16) << "Package hub:" << setw(6) << hub.elements[i].getLabel().coordinates.hub[0] << hub.elements[i].getLabel().coordinates.hub[1] <<
			setw(14) << "Client ID:" << setw(13) << hub.elements[i].getLabel().clientId <<
			endl;
		}
	}  else {
		cout << "UPPS! There's nothing to show over here." << endl;
	}
}



void showPackage(){
	
}




