#ifndef PACKAGE_HPP
#define PACKAGE_HPP
#include <string>
using namespace std;

enum Status {CentralStation, Hub, OnItsWay, Delivered}; // los diferentes estados en el q puede estar un paquete
    
struct Label {
    string packageId;
    string clientId;
    // struct de coordenadas dfeinido en e struct de label
    struct Coords {
        string latitude; // latitud formato __ __ __
        string longitude; // longitud formato __ __ __
        char hub[2]; // zona de las coordenadas (SW,SE,NW,NE)
    } coordinates;
};

class Package {
private:

    Status status;
    Label label;
    
    //no se muy bn por que pero al precer esto va aqui
    //creo q es porque así solo se usan dentro del constructor y no en el main()
    string generateClientId();
    Label::Coords generateCoordinates();
    string generateLabelId(const Label::Coords &coordinates);

public:

    Package();
    
    Status getStatus();
	void setStatus(Status newStatus);
    Label getLabel(); //no se si lo vamos a necesitar
    
    

};

#endif // PACKAGE_HPP
