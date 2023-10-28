#ifndef PACKAGE_HPP
#define PACKAGE_HPP

/*typedef struct Id(){
    char randint[3];
    char randchar;
    char date[8];
    char zone[2];
};*/

typedef struct Coords(){
    int degrees;
    int minutes;
    int seconds;
};

typedef struct Label(){
    Id id;
    Coords coords;
    char DNI[9];
};

class Package {
private:
    Label label;
    char status;
public:
    void createPackage();
    char generateId();
    char generateCoords();
    //void add();
    //Package(); --> constructor
    //~Package(); --> destructor

};

#endif // PACKAGE_HPP
