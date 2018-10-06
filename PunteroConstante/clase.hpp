#include <iostream>

using namespace std;



class Rectangulo
{
public:
    Rectangulo();
    ~Rectangulo();

    void setLargo(int suLargo)
    {
        largo = suLargo;
    }

    int getLargo() const
    {
        return largo;

    }

    void setAncho (int suAncho)
    {
        ancho = suAncho;
    }

    int getAncho() const
    {
        return ancho;
    }

private:
    int largo;
    int ancho;

};

