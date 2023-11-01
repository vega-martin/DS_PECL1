#ifndef PACKAGE_HPP
#define PACKAGE_HPP
#include <string>

class Package {
private:

    Status status;
    Label label;
    
    //no se muy bn por que pero al precer esto va aqui
    //creo q es porque así solo se usan dentro del constructor y no en el main()
    std::string generateClientId();
    Label::Coords generateCoordinates();
    std::string generateLabelId(const Label::Coords &coordinates);

public:

    Package();
    
    Status getStatus();
    Label getLabel(); //no se si lo vamos a necesitar
    
    enum Status {CentralStation, Hub, OnItsWay, Delivered}; // los diferentes estados en el q puede estar un paquete
    
    struct Label {
        std::string packageId;
        std::string clienteId;
        // struct de coordenadas dfeinido en e struct de label
        struct Coords {
            std::string latitud; // latitud formato __ __ __
            std::string longitude; // longitud formato __ __ __
            char hub[2]; // zona de las coordenadas (SW,SE,NW,NE)
        } coordinates;
    };

};

#endif // PACKAGE_HPP
