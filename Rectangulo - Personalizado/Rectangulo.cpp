#include "linea.hpp"
#include "esconu.h"
#include <fstream>
#include <string>

Linea::Linea(int nuevoArriba, int nuevoIzquierda, int nuevoAbajo, int nuevoDerecha)
{
    arriba = nuevoArriba;
    izquierda = nuevoIzquierda;
    abajo = nuevoAbajo;
    derecha = nuevoDerecha;

    arribaIzquierda.setX(izquierda);
    arribaIzquierda.setY(arriba);

    arribaDerecha.setX(derecha);
    arribaDerecha.setY(arriba);

    abajoIzquierda.setX(izquierda);
    abajoIzquierda.setY(abajo);

    abajoDerecha.setX(derecha);
    abajoDerecha.setY(abajo);
}

void Linea::setArriba(int nuevoArriba)
{
    arriba = nuevoArriba;
    arribaIzquierda.setY(arriba);
    arribaDerecha.setY(arriba);
}

void Linea::setIzquierda(int nuevoIzquierda)
{
    izquierda = nuevoIzquierda;
    arribaIzquierda.setX(izquierda);
    abajoIzquierda.setX(izquierda);
}

void Linea::setAbajo(int nuevoAbajo)
{
    abajo = nuevoAbajo;
    abajoIzquierda.setY(abajo);
    abajoDerecha.setY(abajo);
}

void Linea::setDerecha(int nuevoDerecha)
{
    derecha = nuevoDerecha;
    arribaDerecha.setX(derecha);
    abajoDerecha.setX(derecha);
}

void Linea::despliegaRectangulo()
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

    for (int a=arriba; a <= abajo; a++)
    {
        CoordenadaXY(izquierda,a);  //izquierda es el je X y a es el eje Y
        cout << simbolo;
        CoordenadaXY(derecha, a);   //derecha es el je X y a es el eje Y
        cout << simbolo;
    }

}


int Linea::getArea() const
{
    int ancho = derecha - izquierda;
    int alto = abajo - arriba;
    return (ancho * alto);
}

void Linea::perimetro()
{
    int resultado;
    resultado = arriba + derecha + abajo + izquierda;
    cout <<endl;
    CoordenadaXY(derecha/3, arriba+1);
    cout <<"Perimeto:" <<resultado;
    cout <<endl;
}

void Linea::colorLinea(int colorrectangulo)
{
    ColorTexto(colorrectangulo);
}

void Linea::nombrerectangulo(std::string nombre)
{
    CoordenadaXY(derecha/2, arriba);
    cout << nombre;
}


// Calcular el área de un rectángulo al
// encontrar sus esquinas y determinar
// sus coordenadas.

int main()
{

    ifstream archivoentrada;
    archivoentrada.open("rectangulo.txt");

    int x,primercolor,segundocolor;
    std::string nombre1,nombre2;
    std::string encabezado[5000];
    void coloresdelrectangulo();

    for (x = 0; x <= 4999; x++)
    {
        encabezado[x] = "";

    }

    while(archivoentrada)
    {
        getline(archivoentrada,encabezado[5000]);
        cout<<endl;
        cout << encabezado[5000];
    }

    archivoentrada.close();
    cout << endl;
    CoordenadaXY(1,10);
    cout <<"Como desea nombrar el primer rectangulo: ";
    CoordenadaXY(1,11);
    ColorTexto(PREESTABLECIDO);
    cin >> nombre1;
    CoordenadaXY(1,12);
    cout <<"Escriba numero del color de " <<nombre1 <<": ";
    coloresdelrectangulo();
    CoordenadaXY(1,13);
    ColorTexto(PREESTABLECIDO);
    cin >> primercolor;
    CoordenadaXY(1,14);
    ColorTexto(PREESTABLECIDO);
    cout <<"Como desea nombrar el segundo rectangulo: ";
    CoordenadaXY(1,15);
    ColorTexto(PREESTABLECIDO);
    cin >> nombre2;
    CoordenadaXY(1,16);
    ColorTexto(PREESTABLECIDO);
    cout <<"Escriba el numero del color de " <<nombre2 <<": ";
    CoordenadaXY(1,17);
    ColorTexto(PREESTABLECIDO);
    cin >> segundocolor;
    cout <<endl;

    // Instanciar e inicializar una un objeto local de tipo Rectangulo.
    BorraPantalla();
    //Rectangulo 1
    Linea rectanguloUno(3, 4, 20, 55 );
    rectanguloUno.colorLinea(primercolor);
    rectanguloUno.despliegaRectangulo();
    rectanguloUno.perimetro();
    rectanguloUno.nombrerectangulo(nombre1);
    //La manera en que estan organizados los objetos afectan el funcionamiento.
    //Rectangulo 2

    Linea rectanguloDos(8, 8, 13, 30 );
    rectanguloDos.colorLinea(segundocolor);
    rectanguloDos.despliegaRectangulo();
    rectanguloDos.perimetro();
    rectanguloDos.nombrerectangulo(nombre2);



    CoordenadaXY(80,20);
    ColorTexto(PREESTABLECIDO);



    return 0;
}

void coloresdelrectangulo()
{

    int x;
    CoordenadaXY(50,10);
    cout << "0 --> NEGRO";
    CoordenadaXY(50,11);
    ColorTexto(1);
    cout << "1 --> ROJO";
    CoordenadaXY(50,12);
    ColorTexto(2);
    cout << "2 --> VERDE";
    CoordenadaXY(50,13);
    ColorTexto(3);
    cout << "3 --> AMARILLO";
    CoordenadaXY(50,14);
    ColorTexto(4);
    cout << "4 --> AZUL";
    CoordenadaXY(50,15);
    ColorTexto(5);
    cout << "5 --> MAGENTA";
    CoordenadaXY(50,16);
    ColorTexto(6);
    cout << "6 --> CIAN";


    CoordenadaXY(50,9);
    cout << "_______________";
    CoordenadaXY(49,17);
    cout << "________________";

    for (x = 0; x <= 7; x++ )
    {
        CoordenadaXY(49,10+x);
        cout << "|";
        CoordenadaXY(65,10+x);
        cout << "|";
    }

}
