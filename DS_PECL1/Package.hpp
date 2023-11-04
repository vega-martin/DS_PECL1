#ifndef PACKAGE_HPP
#define PACKAGE_HPP
#include <string>
using namespace std;

// An enumeration data type is used for the package's status:
enum Status {CentralStation, Hub, OnItsWay, Delivered};
    
struct Label {
    string packageId;
    string clientId;
	// Coordinates struct defined inside Label struct:
    struct Coords {
        string latitude; // __ __ __ format
        string longitude; // __ __ __ format
        char hub[2]; // Coords' geographical zone (SW, SE, NW, NE)
    } coordinates;
};

class Package {
private:
    
    Status status;
    Label label;
    
    //no se muy bn por que pero al precer esto va aqui
    //creo q es porque así solo se usan dentro del constructor y no en el main()
    
    /* EFECTIVAMENTE, LAS SIGUIENTES FUNCIONES VAN AQUÍ PORQUE SON PRIVADAS PARA ESTA CLASE, NO LAS 
     * QUEREMOS USAR EN NINGÚN OTRO SITIO FUERA, YA QUE SON GENERADORAS DE INFORMACIÓN (DE DATOS) */
     
    string generateClientId();
    Label::Coords generateCoordinates();
    string generateLabelId(const Label::Coords &coordinates);
    

public:

    Package();
    
    Status getStatus();
    void setStatus(Status newStatus);
    Label getLabel(); // May not be needed  

};

#endif // PACKAGE_HPP
