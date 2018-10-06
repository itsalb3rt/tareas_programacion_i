#include <iostream>

using namespace std;

int main()
{
    int miEdad; //una variable
    int *pEdad; // un puntero

    miEdad = 27;
    pEdad = &miEdad; //asigna la direccion de miEdad a pEdad
    cout <<"miEdad: " << miEdad <<endl;
    cout <<"*pEdad: " <<*pEdad <<endl << endl;

    cout <<"*pedad = 19" <<endl;
    *pEdad = 19; //cambia el valor a miEdad a 19
    cout <<"*pEdad: " << *pEdad <<endl;
    cout <<"miEdad: " << miEdad <<endl <<endl;

    cout << "miEdad=33" << endl;
    miEdad = 33;
    cout << "miEdad: " << miEdad <<endl;
    cout << "*pEdad:  " << *pEdad << endl;

    return 0;
}
