#include <iostream>
#include "esconu.h"`

using namespace std;

int main()
{
    char simbolo = '*';

    int x1, y1;

    x1 = 5;
    y1 = 9;

    //lineas horizontales
    for (int a=1; a <= x1; a++)
    {
        CoordenadaXY(a,y1); //Donde y1 es la cordenadas en Y osea el eje vertical
        cout << simbolo;

    }
    //lineas horizontales
    for (int a=1; a <= x1; a++)
    {
        CoordenadaXY(a,(y1-y1)+1);
        cout << simbolo;

    }

    //Lineas verticales
    for (int a=1; a <= y1; a++)
    {
        CoordenadaXY(x1,a); //Donde x1 es la cordenadas en X osea el eje horizontal
        cout << simbolo;

    }

    //Lineas verticales
    for (int a=1; a <= y1; a++)
    {
        CoordenadaXY((x1-x1)+1,a);
        cout << simbolo;

    }


    return 0;
}
