#include <ctime>
#include <random>
#include <stdlib.h>
#include <iostream>
#include "Package.hpp"
#include "Randomize.hpp"
using namespace std;

//std::random_device global_rd;

//thread_local std::random_device Package::rd;
thread_local std::mt19937 Package::gen(std::random_device{}());

Label::Coords Package::generateCoordinates(){
    // Generate random coordinates:
    //mt19937 gen(global_rd());
    //latidud entre 41.070998 y 40.854057
    uniform_real_distribution<double> distributionLat(40.854057, 41.070999);
    double lat = distributionLat(gen); 
    int latD = (int)lat;
    int latM = (int) ((lat - (double)latD) * 60.f);
    int latS = (int) (((lat - (double)latD) * 60.f - (double)latM) * 60.f);
        
    //longitud entre -5.837731 y -5.483051
    uniform_real_distribution<double> distributionLon(-5.837731, -5.483050);
    double lon = distributionLon(gen);
    int lonD = (int)lon;
    int lonM = (int) ((lon - (double)lonD) * 60.f);
    int lonS = (int) (((lon - (double)lonD) * 60.f - (double)lonM) * 60.f);
    
    Label::Coords coordinates;
    
    // determinar hub
    if (lat >= ((40.854057 + 41.070999)/2)){
        if (lon >= ((-5.837731 + (-5.483050))/2)){
            coordinates.hub[0] = 'N';
            coordinates.hub[1] = 'E';
        } else {
            coordinates.hub[0] = 'N';
            coordinates.hub[1] = 'W';
        }
    } else {
        if (lon >= ((-5.837731 + (-5.483050))/2)){
            coordinates.hub[0] = 'S';
            coordinates.hub[1] = 'E';
        } else {
            coordinates.hub[0] = 'S';
            coordinates.hub[1] = 'W';
        }
    }
	coordinates.hub[2] = '\0'; //apparently this char is considered a string when printed so it needs a closing character
    // poner formato a las coordenadas
    coordinates.latitude = to_string(latD) + " " + to_string(latM) + " " + to_string(latS);
    coordinates.longitude = to_string(lonD) + " " + to_string(lonM) + " " + to_string(lonS);
    
    return coordinates;
    
}


string Package::generateLabelId(const Label::Coords &coordinates) {
    /*//mt19937 gen(global_rd());
    uniform_int_distribution<int> distribution(0, 25); // 26 letters in the array

    // Get the random index from the distribution
    int randomIndex = distribution(gen);

    // Array of English alphabet letters (capitalized)
    char alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    // Get the random letter from the array
    char randLetter = alphabet[randomIndex];*/
	char letter = randLetter();
    //obtener fecha
    time_t time = std::time(nullptr);
    tm *now = localtime(&time);
	string day = to_string(now->tm_mday);
	while(day.length() < 2){
		day = "0" + day;
	}
	string month = to_string(now->tm_mon + 1);
	while(month.length() < 2){
		month = "0" + month;
	}
    string date = day + month + to_string(now->tm_year + 1900);
    
    //obtener hub
    string hub = coordinates.hub;

    // Ensure randNum has 3 digits
    /*uniform_int_distribution<int> randNumDistribution(0, 999);
    int randNum = randNumDistribution(gen);
    string formattedNumber = to_string(randNum);
    while (formattedNumber.length() < 3) {
        formattedNumber = "0" + formattedNumber;
    }*/
	
	string number = to_string(randNumber()) + to_string(randNumber());
	number.erase(number.size()-1, 1);
	
    // Final label id
    string labelId = number + letter + date + hub;

    return labelId;
}



string Package::generateClientId(){
    //mt19937 gen(global_rd());
    uniform_int_distribution<int> distribution(10000000, 99999999); //8cifras
    int idNum = distribution(gen);
    char letter[23] = {'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
    int mod = idNum % 23;
    char idLetter = letter[mod];
    string clientId = to_string(idNum) + idLetter;
    
    return clientId;
}


Package::Package(){
	
    //mt19937 gen(global_rd());
    //first status recorded ?
    status = Status::CentralStation;
    
    //generate label 
    label.clientId = Package::generateClientId();
    label.coordinates = Package::generateCoordinates();
    label.packageId = Package::generateLabelId(label.coordinates);
    
}


Status Package::getStatus(){
    return status;
}

void Package::setStatus(Status newStatus){
    status = newStatus;
}

Label Package::getLabel(){
    return label;
}