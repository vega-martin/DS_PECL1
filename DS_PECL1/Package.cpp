#include <iostream>
#include <ctime>
#include <random>
#include "Package.hpp"
using namespace std;

Label::Coords Package::generateCoordinates(){
    // Generate random coordinates:
    random_device rn;
    mt19937 gen(rn());
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
    // poner formato a las coordenadas
    coordinates.latitude = to_string(latD) + " " + to_string(latM) + " " + to_string(latS);
    coordinates.longitude = to_string(lonD) + " " + to_string(lonM) + " " + to_string(lonS);
    
    return coordinates;
    
}


string Package::generateLabelId(const Label::Coords &coordinates){
    srand(time(0));
    int randNum = rand() % 1000;
    // asegurrse de que tiene 3 cifras si o si
    string formattedNumber = to_string(randNum);
    while (formattedNumber.length() < 3) {
        formattedNumber = "0" + formattedNumber;
    }
    char randLetter = 65 + rand() % 91;
    //obtener fecha
    time_t time = std::time(nullptr);
    tm *now = localtime(&time);
    string date = to_string(now->tm_mday) + to_string(now->tm_mon + 1) + to_string(now->tm_year + 1900);
    //obtener hub
    string hub = coordinates.hub;
    // final label id
    string labelId = formattedNumber + randLetter + date + hub;
    
    return labelId;
}


string Package::generateClientId(){
    random_device rn1; //rn = random number...it's just a name
    mt19937 gen(rn1()); // genera la semilla por asi decirlo
    uniform_int_distribution<int> distribution(10000000, 99999999); //8cifras
    int idNum = distribution(gen);
    char letter[23] = {'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
    int mod = idNum % 23;
    char idLetter = letter[mod];
    string clientId = to_string(idNum) + idLetter;
    
    return clientId;
}


Package::Package(){
    
    random_device rn2;
    mt19937 gen(rn2());
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