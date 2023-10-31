#include <iostream>
#include <stdexcept>
#include <ctime>
#include "Package.hpp"

Package::Label::Coords Package::generateCoordenates(){
    srand(time(NULL));
    float lat = 40.854057 + rand() % 41.070999;
    int latD = (int)lat;
    int latM = (int) ((lat - (float)latD) * 60f);
    int latS = (int) (((lat - (float)latD) * 60f - (float)latM) * 60f);
    
    float lon = -5.837731 + rand() % -5.483050;
    int lonD = (int)lon;
    int lonM = (int) ((lon - (float)lonD) * 60f);
    int lonS = (int) (((lon - (float)lonD) * 60f - (float)lonM) * 60f);
    
    //falta por calcular el hub y poner las coordenadas en el formato especificado en el enunciado
    
    
    
}

char generateCoords(){
    //latidud entre 41.070998 y 40.854057
    //longitud entre -5.837731 y -5.483051
    
}

Package::Package()
{
}

