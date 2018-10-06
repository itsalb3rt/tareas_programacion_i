#include <iostream>

using namespace std;



int main()
{

    char* nombre;   //Char de tipo puntero

    char  _nombre[10]; //Arreglo de tipo char
    cout << "Escriba nombre: ";
    cin>>_nombre;       //variable que guarda brevemente el dato del usuario
    cout << endl;


    //asigna el contenido de del arreglo a la variable puntero.
    nombre = _nombre;

    //muestra lo que tiene el puntero
    cout <<nombre;

    delete nombre;

    return 0;
}
