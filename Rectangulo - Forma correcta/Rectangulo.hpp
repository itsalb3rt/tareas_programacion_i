#include <iostream>
#include <string>

using namespace std;

class Punto
{
    // No se especificó un construtor, se utilizar el default
public:

    void setX(int nuevoX)
    {
        x = nuevoX;
    }
    void setY(int nuevoY)
    {
        y = nuevoY;
    }
    int getX() const
    {
        return x;
    }
    int getY() const
    {
        return y;
    }

private:

    int x;
    int y;
};

class  Rectangulo
{
public:
    Rectangulo (int nuevoArriba, int nuevoIzquierda, int nuevoAbajo, int nuevoDerecha, string nuevoNombre, int nuevoColor);
    ~Rectangulo() {}

    int getArriba() const { return arriba; }
    int getIzquierda() const { return izquierda; }
    int getAbajo() const { return abajo; }
    int getDerecha() const { return derecha; }
    string getnombre() const { return nombre; }
    int getcolor() const { return color; }
    int getArea() const;

    Punto getArribaIzquierda() const { return arribaIzquierda; }
    Punto getAbajoIzquierda() const { return abajoIzquierda; }
    Punto getArribaDerecha() const { return arribaDerecha; }
    Punto getAbajoDerecha() const { return abajoDerecha; }


    void setArribaIzquierda(Punto lugar);
    void setAbajoIzquierda(Punto lugar);
    void setArribaDerecha(Punto lugar);
    void setAbajoDerecha(Punto lugar);

    void setArriba(int nuevoArriba);
    void setIzquierda (int nuevoIzquierda);
    void setAbajo (int nuevoAbajo);
    void setDerecha (int nuevoDerecha);
    void setNombre( string nuevoNombre);

    int setColor( int nuevoColor);
    int getPerimetro() const;

    void dibuja();



private:

    Punto arribaIzquierda;
    Punto arribaDerecha;
    Punto abajoIzquierda;
    Punto abajoDerecha;
    int arriba;
    int izquierda;
    int abajo;
    int derecha;
    int color;
    string nombre;
};


class Linea
{
public:
    Linea ( int nuevaLineaPuntohv, int nuevaLineaPuntovh);
    ~Linea () {};

    int getLineaPuntoInicialhv() const { return lineahv; }
    int getLineaPuntoInicialvh() const { return lineavh; }

    Punto getLineaPuntoInicial() const { return lineaPuntohv; }
    Punto getLineaPuntoFinal() const { return lineaPuntovh; }

    void setArribaIzquierda(Punto zona);
    void setAbajoIzquierda(Punto zona);

    void setlineaInicial (int nuevaLineaPuntohv );
    void setLineafinal (int nuevaLineaPuntovh );

    void dibujaLinea();



private:

    Punto lineaPuntohv;
    Punto lineaPuntovh;

    int lineahv;
    int lineavh;


};
