#include <iostream>
#include "clase.hpp"
using namespace std;

GatoSimple::GatoSimple()
    {
        edad = new int (2); //Cuando se llama al constructor la primera, asigna el primer valor a la segunda
        peso = new int (5); //se asigna el segundo.
    }

    GatoSimple::~GatoSimple()
    {
        delete edad;
        delete peso;
    }

int main()
{



    GatoSimple *Misulindo = new GatoSimple; //se declara el objeto de tipo puntero.

    cout << "Misulindo tiene " << Misulindo->getEdad() <<" anios." <<endl;

    Misulindo->setEdad(5);

    cout <<"Misulindo tiene " <<Misulindo->getEdad() << " anios." << endl;

    delete Misulindo;





    return 0;
};
