#include <iostream>

using namespace std;

class Rectangulo
{
public:
    Rectangulo();
    ~Rectangulo() {};

    void setLargo(int suLargo)
    {
        this->largo = suLargo;

    }

    int getLargo() const
    {
        return this->largo;
    }

    void setAncho(int suAncho)
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

Rectangulo::Rectangulo()
{
    ancho = 5;
    largo = 10;
}



int main()
{
    Rectangulo elRectangulo;
    cout <<"elRectangulo mide " << elRectangulo.getLargo() <<" pies de largo" << endl;

    cout << "elRectangulo mide " <<elRectangulo.getAncho() << " pies de ancho" <<endl << endl;

    elRectangulo.setLargo(20);
    elRectangulo.setAncho(10);

    cout <<"elRectangulo mide " << elRectangulo.getLargo() <<" pies de largo" << endl;

    cout << "elRectangulo mide " <<elRectangulo.getAncho() << " pies de ancho" <<endl << endl;


    return 0;
}

