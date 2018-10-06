#include "linea.hpp"
#include "esconu.h"

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

void Linea::dibuja()
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
    //Lineas verticales
    for (int a=arriba; a <= abajo; a++)
    {
        CoordenadaXY(izquierda,a);  //izquierda es el je X y a es el eje Y
        cout << simbolo;
        CoordenadaXY(derecha, a);   //derecha es el je X y a es el eje Y
        cout << simbolo;
    }

}


void Linea::perimetro()
{
    int resultado;
    resultado = arriba + derecha + abajo + izquierda;
    cout <<endl;
    CoordenadaXY(derecha/3, arriba+1);
    cout <<"El perimetro es:" <<resultado;
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

void Linea::areaRectangulo()
{
    int ancho = derecha - izquierda;
    int alto = abajo - arriba;
    int resultado = ancho * alto;
    CoordenadaXY(derecha/3, arriba+2);
    cout <<"El area es: " <<resultado <<" cm2";
}


// Calcular el área de un rectángulo al
// encontrar sus esquinas y determinar
// sus coordenadas.

int main()
{
    // Instanciar e inicializar una un objeto local de tipo Rectangulo.
    BorraPantalla();
    //Rectangulo 1
    Linea rectanguloUno(3, 4, 20, 55 ); //Valores del rectangulo
    rectanguloUno.colorLinea(1);    //Color del rectangulo
    rectanguloUno.dibuja();    //Dibuja el rectangulo
    rectanguloUno.perimetro();  //Calcula el perimetro
    rectanguloUno.nombrerectangulo("Albert");   //Nombra el rectangulo
    rectanguloUno.areaRectangulo(); //Calcula el area del rectangulo multiplicando la base por altura
    //Las notas anteriores son validas para los siguientes objetos.

    //La manera en que estan organizados los objetos afectan el funcionamiento.

    //Rectangulo 2
    Linea rectanguloDos(8, 15, 13, 40 );
    rectanguloDos.colorLinea(2);
    rectanguloDos.dibuja();
    rectanguloDos.perimetro();
    rectanguloDos.nombrerectangulo("Eduardo");
    rectanguloDos.areaRectangulo();


    CoordenadaXY(80,20);
    ColorTexto(PREESTABLECIDO);

    return 0;
}
