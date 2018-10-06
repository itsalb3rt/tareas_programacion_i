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

Rectangulo::Rectangulo(): ancho(5), largo(10) {}

Rectangulo::~Rectangulo() {}

int main ()
{
    Rectangulo* pRect = new Rectangulo;
    const Rectangulo *pRectanguloconstante = new Rectangulo;
    Rectangulo * const pPunteroconstante = new Rectangulo;

    cout <<"pRect ancho: " <<pRect->getAncho() << " pies" << endl;
    cout << "pRectanguloConstante ancho: " << pRectanguloconstante->getAncho() <<endl;
    cout <<"pRectanguloConstante ancho: " <<pRectanguloconstante->getAncho() <<" pies" <<endl;

    pRect->setAncho(10);
    //pRectanguloconstante->setAncho(10);

    pPunteroconstante->setAncho(10);

    cout <<"pRect ancho: " <<pRect->getAncho() << " pies" << endl;
    cout << "pRectanguloConstante ancho: " << pRectanguloconstante->getAncho() <<endl;
    cout << "pRectanguloConstante ancho: " <<pRectanguloconstante->getAncho() <<" pies" <<endl <<endl;

    return 0;
}
