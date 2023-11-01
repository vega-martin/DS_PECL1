#include <iostream>
#include <ctime>
#include <random>
#include "Package.hpp"


Package::Label::Coords Package::generateCoordenates(){
    srand(time(NULL));
    //latidud entre 41.070998 y 40.854057
    float lat = 40.854057 + rand() % 41.070999;
    int latD = (int)lat;
    int latM = (int) ((lat - (float)latD) * 60f);
    int latS = (int) (((lat - (float)latD) * 60f - (float)latM) * 60f);
    
    //longitud entre -5.837731 y -5.483051
    float lon = -5.837731 + rand() % -5.483050;
    int lonD = (int)lon;
    int lonM = (int) ((lon - (float)lonD) * 60f);
    int lonS = (int) (((lon - (float)lonD) * 60f - (float)lonM) * 60f);
    
    Label::Coords coordinates;
    
    // determinar hub
    if (lat >= ((40.854057 + 41.070999)/2)){
        if (lon >= ((-5.837731 + (-5.483050))/2)){
            coordinates.hub = "NE";
        } else {
            coordinates.hub = "NW";
        }
    } else {
        if (lon >= ((-5.837731 + (-5.483050))/2)){
            coordinates.hub = "SE";
        } else {
            coordinates.hub = "SW";
        }
    }
    // poner formato a las coordenadas
    coordinates.latitude = std::to_string(latD) + " " + std::to_string(latM) + " " + std::to_string(latS);
    coordinates.longitude = std::to_string(lonD) + " " + std::to_string(lonM) + " " + std::to_string(lonS);
    
    return coordinates;
    
}


std::string generateLabelId(const Label::Coords &coordinates){
    srand(time(NULL));
    int randNum = rand() % 1000;
    // asegurrse de que tiene 3 cifras si o si
    std::string formattedNumber = std::to_string(randomNumber);
    while (formattedNumber.length() < 3) {
        formattedNumber = "0" + formattedNumber;
    }
    char randLetter = 65 + rand() % 91;
    //obtener fecha
    std::time_t time = std::time(nullptr);
    std::tm *now = std::localtime(&time);
    std::string date = std::to_string(now->tm_mday) + std::to_string(now->tm_mon + 1) + std::to_string(now->tm_year + 1900);
    //obtener hub
    std::string hub = coordinates.hub;
    // final label id
    std::string labelId = formattedNumber + randLetter + date + hub;
    
    return labelId;
}


std::string generateClientId(){
    //como necesitamos 8 cifras no podemos usar srand y rand. tenemos que usar otra cosa
    std::random_device rn; //rn = random number...it's just a name
    std::mt19937 gen(rn()); // genera la semilla por asi decirlo
    std::uniform_int_distribution<int> distribution(10000000, 99999999); //8cifras
    int idNum = distribution(gen);
    char letter[23] = {'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 'X', 'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 'C', 'K', 'E'};
    int mod = idNum % 23;
    char idLetter = letter[mod];
    std::string clientId = std::to_string(idNum) + idLetter;
}


Package::Package()
{
}

