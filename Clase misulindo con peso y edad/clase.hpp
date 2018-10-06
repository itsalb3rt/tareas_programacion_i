#include <iostream>

using namespace std;


class GatoSimple
{
public:
    GatoSimple();
    ~GatoSimple();

    int getEdad() const {return *edad; }
    void setEdad( int suEdad){*edad = suEdad;}

    int getPeso() const {return *peso; }
    void setsuPeso (int suPeso) {*peso = suPeso;}



private:
    int *edad;
    int *peso;

    };

