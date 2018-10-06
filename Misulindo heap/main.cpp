#include <iostream>
#include "esconu.h"

////agregar un gano nuevo

using namespace std;

class GatoSimple
{
public:
    GatoSimple()
    {
        edad = 2;
    }
    ~GatoSimple() {}
    int getEdad() const
    {
        return edad;
    }
    void setEdad (int SuEdad)
    {
        edad = SuEdad;
    }

private:
    int edad;
};


int main()
{

    BorraPantalla();

    GatoSimple *pMisulindo = new GatoSimple;  //Crear un objeto de tipo puntero

    cout <<"Misulindo tiene " << pMisulindo ->getEdad() << " anios" <<endl; //Manda a escribir la edad actual el misu

    pMisulindo->setEdad(5); //Se manda a cambiar la edad directo a la funcion miembro por el operardo ->
    cout <<"Misulindo tiene " << pMisulindo->getEdad() <<" anios" <<endl;

    delete pMisulindo;


    return 0;
}




