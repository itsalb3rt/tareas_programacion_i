#include <iostream>
#include <string>

using namespace std;

class Velocipedo
{
public:
    Velocipedo (int velocidadInicial);
    ~Velocipedo ();

    int getVelocidad ();
    void setVelocidad (int velocidad);

    int getRuedas ();
    void setRuedas (int cantidadRuedas);

    string getColor();
    void setColor (string colorVelocipedo);

    void pedalea();
    void frena();

private:
    int velocidad;
    int ruedas;
    string color;
};

// Constructor de objetos
Velocipedo::Velocipedo(int velocidadInicial)
{
    setVelocidad(velocidadInicial);
}


// Destructor de objetos
Velocipedo::~Velocipedo()
{
    // No hace nada
}

// Obtener la velocidad del velocípedo
int Velocipedo::getVelocidad()
{
    return velocidad;
}


// Ajustar la velocidad del velocípedo
void Velocipedo::setVelocidad(int nuevaVelocidad)
{
    if (nuevaVelocidad >= 0)
    {
        velocidad = nuevaVelocidad;
    }
}


// Obtener numero de ruedas del velocípedo
int Velocipedo::getRuedas()
{
    return ruedas;
}


// Ajustar la cantidad de ruedas del velocípedo
void Velocipedo::setRuedas(int cantidadRuedas)
{
    if (cantidadRuedas >= 0)
    {
        ruedas = cantidadRuedas;
    }
    cout <<"La cantidad de las ruedas es: " << getRuedas();
}


// Obtener el color del velocípedo
string Velocipedo::getColor()
{
    return color;
}


// Ajustar el color del velocípedo
void Velocipedo::setColor (string nuevoColor)
{

    color = nuevoColor;
    cout <<"El color del vehiculo es: " << getColor() << endl;
}



// Pedalear el velocípedo
void Velocipedo::pedalea()
{
    setVelocidad(velocidad + 1);
    std::cout << "\nPedaleando; velocidad del velocipedo "
    << getVelocidad() << " kph\n";
}


// frenar el velocípedo
void Velocipedo::frena()
{
    setVelocidad(velocidad - 1);
    std::cout << "\nFrenando; velocidad del velocipedo " <<
    getVelocidad() << " kph\n";
}


// Crear el velocípedo y montarlo



int main()
{
    void datosDelVehiculo();
    int opcion;




   do
   {
        cout <<"Presione 1 Para ver los datos del vehiculo" <<endl;
        cout <<"Presione 0 para salir del programa" <<endl;
        cin >>opcion;
        cout << endl;

       if (opcion == 1)
       {
           datosDelVehiculo();
       }

   }
    while ( opcion != 0);

    return 0;
}

void datosDelVehiculo()
{
     Velocipedo toyota(5);

    toyota.setColor ("Rojo"); //El color se asigna en esta parte para que lo muestre con un cout que esta ubicado en el setcolor
    toyota.setRuedas (3);   //La cantidad se asigna en esta parte para que lo muestre con un cout que esta ubicado en el setcolor

    toyota.pedalea();
    //toyota.pedalea();
    //toyota.frena();
    cout <<endl;
}





//crear una funcion para que despliegue los datos del velocipedo, velocidad, color, ruedas etc....
