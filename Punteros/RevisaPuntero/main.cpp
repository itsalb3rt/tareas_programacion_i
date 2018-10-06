#include <iostream>
#include <iomanip>


using namespace std;

int main()
{
    int resultado;
    unsigned short int miEdad = 5, tuEdad = 10;
    unsigned short int *pEdad = &miEdad; //Un puntero

    cout << setw (15) << "miEdad: " << setw (15) << miEdad;
    cout << setw (15) << "tuEdad: " << setw (15) << tuEdad << endl;
    cout << setw (15) << "&miEdad: " << setw (15) <<&miEdad;
    cout << setw (15) << "&tuEdad: " << setw (15) << &tuEdad << endl;

    cout << setw (15) << "pEdad: " <<setw (15) << pEdad <<endl;
    cout << setw (15) << "*pEdad: " <<setw (15) << *pEdad << endl << endl;

    pEdad = &tuEdad; //Reasigna el puntero

    cout << setw (15) << "miEdad: " << setw (15) << miEdad;
    cout << setw (15) << "tuEdad: " << setw (15) << tuEdad << endl;
    cout << setw (15) << "&miEdad: " << setw (15) <<&miEdad;
    cout << setw (15) << "&tuEdad: " << setw (15) << &tuEdad << endl;

    cout << setw (15) << "pEdad: " <<setw (15) << pEdad <<endl;
    cout << setw (15) << "*pEdad: " <<setw (15) << *pEdad << endl << endl;

    cout << setw (15) << "&pEdad: " <<setw (15) << &pEdad <<endl;


    resultado =tuEdad * *pEdad;

    cout << "La multiplicacion de tuEdad y *Pedad es: " <<resultado <<endl;

    miEdad = 20; //Asigna nueva edad a miEdad
    pEdad = &miEdad;       //Indica que pEdad sera igual a la


    cout <<"mi nueva edad es *pEdad : " <<*pEdad <<endl <<endl;

    cout << setw (15) << "miEdad: " << setw (15) << miEdad;
    cout << setw (15) << "tuEdad: " << setw (15) << tuEdad << endl;
    cout << setw (15) << "&miEdad: " << setw (15) <<&miEdad;
    cout << setw (15) << "&tuEdad: " << setw (15) << &tuEdad << endl;

    cout << setw (15) << "pEdad: " <<setw (15) << pEdad <<endl;
    cout << setw (15) << "*pEdad: " <<setw (15) << *pEdad << endl << endl;



    return 0;
}
