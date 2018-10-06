//Albert Eduardo Hidalgo Taveras.

#include "Rectangulo.hpp"

#include <string>

using namespace std;

    Rectangulo::Rectangulo(int nuevoArriba, int nuevoIzquierda, int nuevoAbajo, int nuevoDerecha, string nuevoNombre, int nuevoColor)
{
    arriba = nuevoArriba;
    izquierda = nuevoIzquierda;
    abajo = nuevoAbajo;             //Esto indica que cada nuevo valor sera igual a una variable mas simple.
    derecha = nuevoDerecha;
    nombre = nuevoNombre;
    color = nuevoColor;

    arribaIzquierda.setX(izquierda);
    arribaIzquierda.setY(arriba);

    arribaDerecha.setX(derecha);
    arribaDerecha.setY(arriba);

    abajoIzquierda.setX(izquierda);
    abajoIzquierda.setY(abajo);

    abajoDerecha.setX(derecha);
    abajoDerecha.setY(abajo);
}

void Rectangulo::setArriba(int nuevoArriba)
{
    arriba = nuevoArriba;
    arribaIzquierda.setY(arriba);
    arribaDerecha.setY(arriba);
}

void Rectangulo::setIzquierda(int nuevoIzquierda)
{
    izquierda = nuevoIzquierda;
    arribaIzquierda.setX(izquierda);
    abajoIzquierda.setX(izquierda);
}

void Rectangulo::setAbajo(int nuevoAbajo)
{
    abajo = nuevoAbajo;
    abajoIzquierda.setY(abajo);
    abajoDerecha.setY(abajo);
}

void Rectangulo::setDerecha(int nuevoDerecha)
{
    derecha = nuevoDerecha;
    arribaDerecha.setX(derecha);
    abajoDerecha.setX(derecha);
}

void Rectangulo::dibuja()
{
    char simbolo = '*';


    //lineas horizontales
    for (int a=izquierda; a <= derecha; a++)    //A es igual a la porision inicial a la izquierda y entrara en ciclo mientras sea menor que la posicion derecha
    {
        CoordenadaXY(a,arriba); //a es el eje X y arriba el eje Y
        cout << simbolo;
        CoordenadaXY(a,abajo);  //A es el eje X y abajo el eje Y
        cout << simbolo;
    }

    CoordenadaXY(derecha/2,arriba);
    cout <<nombre;
        //Lineas verticales
    for (int a=arriba; a <= abajo; a++)
    {
        CoordenadaXY(izquierda,a);  //izquierda es el je X y a es el eje Y
        cout << simbolo;
        CoordenadaXY(derecha, a);   //derecha es el je X y a es el eje Y
        cout << simbolo;
    }

    cout <<"\n El area del rectangulo es: " << getArea();
    cout <<"\n";
    cout <<" El perimetro es: " << getPerimetro();
    cout <<"\n";
}
//Area del rectangulo
int Rectangulo::getArea() const
{
     int ancho = derecha - izquierda;
    int alto = abajo - arriba;
    return (ancho * alto);
}
//Perimetro del rectangulo
int Rectangulo::getPerimetro() const
{
    return (izquierda + derecha + arriba + abajo);
}
//Funcion para asignar el color al rectangulo. Este color sera propio de el por el prefijo set y su constructor
int Rectangulo::setColor(int nuevoColor)
{
    color = nuevoColor;
    return color;
}
//Funcion para asignar el nombre al rectangulo
void Rectangulo::setNombre(string nuevoNombre)
{
    nombre = nuevoNombre;
}


Linea::Linea ( int nuevaLineaPuntohv, int nuevaLineaPuntovh)
{
    lineahv = nuevaLineaPuntohv;
    lineavh = nuevaLineaPuntovh;    //Esto indica que cada nuevo valor sera igual a una variable mas simple.

    lineaPuntohv.setX(lineahv);
    lineaPuntohv.setY(lineavh);

    lineaPuntovh.setX(lineahv);
    lineaPuntovh.setY(lineavh);
}

void Linea::setArribaIzquierda( Punto zona )
{
    lineaPuntohv = zona;
    lineaPuntovh.setX(zona.getY());
    lineaPuntohv.setY(zona.getX());
    lineavh = zona.getY();
    lineahv = zona.getX();

}

void Linea::setAbajoIzquierda( Punto zona )
{
    lineaPuntovh = zona;
    lineaPuntohv.setX(zona.getY());
    lineaPuntovh.setY(zona.getX());
    lineahv = zona.getY();
    lineavh = zona.getX();
}

void Linea::setlineaInicial(int nuevaLineaInicial)
{
    lineahv = nuevaLineaInicial;
    lineaPuntohv.setX(lineahv);
    lineaPuntovh.setX(lineahv);

}

void Linea::setLineafinal(int nuevaLineaFinal)
{

    lineavh = nuevaLineaFinal;
    lineaPuntovh.setY(lineavh);
    lineaPuntohv.setY(lineavh);

}

void Linea::dibujaLinea()
{

    if (lineavh <=24) //Evalua si la longitud es mayor o igual 24 para construir la linea de manera horizontal, de lo contrario lo ara vertical.
    {
        cout <<"\n";
    for (int a = lineahv; a <= lineavh; a++ )
    {
        cout <<"-";
    }
    cout <<"\n";
    }
    else    //Si no se cumple la condicion anterior esto escribira una linea Vertical comenzando en la posicion del primer valor dado.
     {
        cout <<"\n";
    for (int a = lineahv; a <= lineavh; a++ )
    {
        cout <<"-" <<"\n";
    }
    cout <<"\n";
    }



}

int main()
{

    BorraPantalla();

    Rectangulo rectanguloUno(3, 4, 20, 55, "Albert", AZUL); //Atributos del rectangulo, donde comienza el eje x, donde comienza el eje Y
    rectanguloUno.dibuja();                                    //Cuantos debe dibujar en horizontal y cuanto debe dibujar en vertical
                                                            //Ademas se le pasa el nomnbre y color los cuales seran propios del rectangulo por sus constructores y setters.
    ColorTexto(PREESTABLECIDO);
    Linea liniecita (1,20);                           //Datos de la linea, indica desde que posicion comenzara y cuantos simbolos dibujara.
    liniecita.dibujaLinea();


    return 0;
}
