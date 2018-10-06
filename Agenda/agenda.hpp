#include <iostream>
#include <fstream>

using namespace std;

class Fecha
{
public:
    Fecha();
    Fecha (int _dia, int _mes, int _anio);
    ~Fecha () {}

    void setDia (int _dia);
    void setMes (int _mes);
    void setAnio (int _anio);

    int getDia() const { return dia; }
    int getMes() const { return mes; }
    int getAnio() const { return anio; }

    string fecha();



private:

    int dia;
    int mes;
    int anio;

};

class Persona
{
public:
    Persona (); //Constructor por defecto, lo utilice para iniciar funciones desde el main sin tener que pasar valores
    Persona(string _nombre, string _apellido, string _direccion, string _telefono, string _celular, string _fechaNacimiento);
    ~Persona() {}

    //Setters
    string setNombre (string _nombre);
    string setApellido (string _apellido);
    string setDireccion (string _direccion);
    string setTelefono (string _telefono);
    string setCelular (string _celular);
    string setFechaNacimiento (string _fechaNacimiento);
    //Getters
    string getNombre() const { return nombre; }
    string getApellido() const { return apellido; }
    string getDireccion() const { return direccion; }
    string getTelefono() const { return telefono; }
    string getCelular() const { return celular; }
    string getFechaNacimiento() const { return fechaNacimiento; }

    void crear();
    void ver();
    void eliminar();
    string edad(string _diaDeNacimiento, string _mesDeNacimiento, string _anioDeNacimiento, string _fechaActual);


    private:

    string nombre;
    string apellido;
    string direccion;
    string telefono;
    string celular;
    string fechaNacimiento;
    string todasLasPersonas [50];
    ifstream datosDeEntrada;
    ofstream datosDeSalida;
    int contador, x;

};

