#include <iostream>

class Punto
{
    // No se especificó un construtor, se utilizar el default
public:

    void setX(int nuevoX) { x = nuevoX; }
    void setY(int nuevoY) { y = nuevoY; }
    int getX() const { return x;}
    int getY() const { return y;}

private:

    int x;
    int y;
};

class Linea
{
public:
    Linea (int nuevoArriba, int nuevoIzquierda, int nuevoAbajo, int nuevoDerecha);
    ~Linea() {}

    void setArriba(int nuevoArriba);
    void setIzquierda (int nuevoIzquierda);
    void setAbajo (int nuevoAbajo);
    void setDerecha (int nuevoDerecha);

    int getArea() const;
    void despliegaRectangulo();
    void perimetro();
    void colorLinea(int colorrectangulo);
    void nombrerectangulo(std::string nombre);

private:

    Punto arribaIzquierda;
    Punto arribaDerecha;
    Punto abajoIzquierda;
    Punto abajoDerecha;
    int arriba;
    int izquierda;
    int abajo;
    int derecha;
};
