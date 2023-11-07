#include <ctime>
#include <random>
#include "Package.hpp"
#include "Randomize.hpp"
using namespace std;

// An object to randomize is created here:
thread_local mt19937 Package::gen(random_device{}());

Label::Coords Package::generateCoordinates(){
    //Generates a random latidude:
    uniform_real_distribution<double> distributionLat(40.854057, 41.070999);
    double lat = distributionLat(gen); 
    int latD = (int)lat;
    int latM = (int) ((lat - (double)latD) * 60.f);
    int latS = (int) (((lat - (double)latD) * 60.f - (double)latM) * 60.f);
        
    //Generates a random longitude:
    uniform_real_distribution<double> distributionLon(-5.837731, -5.483050);
    double lon = distributionLon(gen);
    int lonD = (int)lon;
    int lonM = (int) ((lon - (double)lonD) * 60.f);
    int lonS = (int) (((lon - (double)lonD) * 60.f - (double)lonM) * 60.f);
    
    Label::Coords coordinates;
    
    //Associates a package with its hub:
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
    /* We created a three-element array because it is considered a string when printed,
    so it needs a closing character */
	coordinates.hub[2] = '\0';
    
    // formatted coordinates:
    coordinates.latitude = to_string(latD) + " " + to_string(latM) + " " + to_string(latS);
    coordinates.longitude = to_string(lonD) + " " + to_string(lonM) + " " + to_string(lonS);
    
    return coordinates;
    
}


string Package::generateLabelId(const Label::Coords &coordinates) {
    char letter = randLetter();

    // date
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

    // hub
    string hub = coordinates.hub;

    // Final label id
    string threeRandNumbers = to_string(randNumber()) + to_string(randNumber()) + to_string(randNumber());
    string labelId = threeRandNumbers + letter + date + hub;

    return labelId;
}




string Package::generateClientId(){
    uniform_int_distribution<int> distribution(10000000, 99999999);
    int idNum = distribution(gen);
    
    // Spanish IDs have a letter assigned to them, following this method:
    char letter[23] = {'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
    int mod = idNum % 23;
    char idLetter = letter[mod];
    
    string clientId = to_string(idNum) + idLetter;
    
    return clientId;
}


Package::Package(){
    //All packages start at the Central Station, so its status must be fixed:
    status = Status::CentralStation;
    
    //Label generation: 
    label.clientId = Package::generateClientId();
    label.coordinates = Package::generateCoordinates();
    label.packageId = Package::generateLabelId(label.coordinates);
    
}

// A few required setter and getter methods:

Status Package::getStatus(){
    return status;
}

void Package::setStatus(Status newStatus){
    status = newStatus;
}

Label Package::getLabel(){
    return label;
}

void Package::setClientId(string id){
    Package::getLabel().clientId = id;
}