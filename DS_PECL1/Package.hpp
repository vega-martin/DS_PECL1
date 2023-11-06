#ifndef PACKAGE_HPP
#define PACKAGE_HPP
#include <string>
#include <random>
using namespace std;

// An enumeration data type is used for the package's status:
enum Status {CentralStation, Hub, Delivered};
    
struct Label {
    string packageId;
    string clientId;
	// Coordinates struct defined inside Label struct:
    struct Coords {
        string latitude; // __ __ __ format
        string longitude; // __ __ __ format
        char hub[3]; // Coords' geographical zone (SW, SE, NW, NE)
    } coordinates;
};

class Package {
private:
    
    Status status;
    Label label;
	//static thread_local std::random_device rd;
	static thread_local std::mt19937 gen;
    
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
