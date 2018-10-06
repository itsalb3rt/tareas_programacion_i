#include <iostream>
#include <time.h>
#include "agenda.hpp"
#include <sstream>
#include "esconu.h"
#include <iomanip>

using namespace std;


Fecha::Fecha(int _dia, int _mes, int _anio)
{
    dia = _dia;
    mes = _mes;
    anio = _anio;
}
Fecha::Fecha()
{

}

Persona::Persona(string _nombre,string _apellido,string _direccion,string _telefono,string _celular,string _fechaNacimiento)
{
    nombre = _nombre;
    apellido = _apellido;
    direccion = _direccion;
    telefono = _telefono;
    celular = _celular;
    fechaNacimiento = _fechaNacimiento;
}

Persona::Persona() //Constructor por defecto, lo utilice para iniciar funciones desde el main sin tener que pasar valores
{

}

void Fecha::setDia(int _dia)
{
    dia = _dia;

}


void Fecha::setMes(int _mes)
{
    mes = _mes;

}

void Fecha::setAnio(int _anio)
{
    anio = _anio;

}

string Persona::setNombre(string _nombre)
{
    nombre = _nombre;
}

string Persona::setApellido(string _apellido)
{
    apellido = _apellido;
}

string Persona::setDireccion(string _direccion)
{
    direccion = _direccion;
}

string Persona::setTelefono(string _telefono)
{
    telefono = _telefono;
}

string Persona::setCelular(string _celular)
{
    celular = _celular;
}

string Persona::setFechaNacimiento(string _fechaNacimiento)
{
    fechaNacimiento = _fechaNacimiento;
}
string Fecha::fecha()
{

// fecha/hora actual basado en el sistema actual


// Objeto de una estructura tm con fecha/hora local
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    /*cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << endl;
         */

    // << now->tm_mday  << (now->tm_mon + 1) << (now->tm_year + 1900);
    string _diaActual;
    string _mesActual;
    string _anioActual;
    string x = "-";
    //String es la variable que toma el valor de lo que querramos convertir
    string String = static_cast<ostringstream*>( &(ostringstream() <<  now->tm_mday ) )->str(); //pasar de entero a string
    _diaActual=String;
    string String2 = static_cast<ostringstream*>( &(ostringstream() <<  (now->tm_mon + 1)  ) )->str(); //pasar de entero a string
    _mesActual=String2;
    string String3 = static_cast<ostringstream*>( &(ostringstream() <<  (now->tm_year + 1900)  ) )->str(); //pasar de entero a string
    _anioActual=String3;



    return  _diaActual + _mesActual + _anioActual;
}
void Persona::ver()
{
    BorraPantalla();

    string _nombre[50];    //Arreglo para guardar todo lo de el archivo en memoria
    string _apellido[50];
    string _direccion[50];
    string _telefono[50];
    string _celular[50];
    string _edad[50];


    for (x = 0; x <= 49; x++)
    {
        _nombre[x] = "";
        _apellido[x] = "";
        _direccion[x] = "";
        _telefono[x] = "";
        _celular[x] = "";
        _edad[x] = "";
    }

    datosDeEntrada.open("agenda.txt");
    contador = 0;
    if (datosDeEntrada)
        while (datosDeEntrada)
        {
            datosDeEntrada >> _nombre[contador];
            datosDeEntrada >> _apellido[contador];
            datosDeEntrada >> _direccion[contador];     //Cada uno de estos arreglos se le asigna el valor indicado por el nombre cuando el for pasa por el
            datosDeEntrada >> _telefono[contador];      //osea que cada repeticion le asigna un valor a cada arreglo
            datosDeEntrada >> _celular[contador];
            datosDeEntrada >> _edad[contador];
            contador++;
        }
    datosDeEntrada.close();
    contador --;
    //Imprime los datos de los contactos respecto al cuadro que esta mas abajo
    for (x = 0; x <= contador; x++)
    {
        CoordenadaXY(1, (x+6));                 //La condicion de la coordernadaXY (segun yo) es relativa ose dependiendo del valor de X es que colocara
        cout << _nombre[x] <<endl;               //Cada valor del arreglo segun corresponda a la posicion del titulo.
        CoordenadaXY(14, (x+6));
        cout << _apellido[x] <<endl;
        CoordenadaXY(30, (x+6));
        cout << _direccion[x] <<endl;
        CoordenadaXY(45, (x+6));
        cout << _telefono[x] <<endl;
        CoordenadaXY(60, (x+6));
        cout << _celular[x] <<endl;
        CoordenadaXY(74, (x+6));
        cout << _edad[x] <<endl;
    }

    //Muestra el cuadro bonito de los contactos
    CoordenadaXY(26,1);
    cout <<"Estas son las personas agregadas hasta ahora.";
    CoordenadaXY(22,2);
    cout <<"Listado ordenado de personas en agenda." << endl;
    CoordenadaXY(6, 3);
    cout <<"-------------------------------------------------------------------" << endl;
    CoordenadaXY(1, 4);
    cout <<"Nombre";
    CoordenadaXY(14, 4);
    cout <<"Apellido";
    CoordenadaXY(30, 4);
    cout <<"Direccion";
    CoordenadaXY(45, 4);
    cout <<"Telefono";
    CoordenadaXY(60, 4);
    cout <<"Celular";
    CoordenadaXY(73, 4);
    cout <<"Edad";
    CoordenadaXY(6,5);
    cout <<"-------------------------------------------------------------------" << endl;
    CoordenadaXY(10,contador+8);
    TeclaPresionada("Presione una tecla para volver al menu.");

}

void Persona::crear()
{
    BorraPantalla();
    string _nombre;
    string _apellido;
    string _direccion;
    string _telefono;
    string _celular;
    string _fechaNacimiento;
    ColorTexto(VERDE);
    CoordenadaXY(6,1);
    cout <<"Agregar una nueva persona a la agenda." <<endl <<endl;
    ColorTexto(PREESTABLECIDO);
    CoordenadaXY(12,4);
    cout <<"Escriba el nombre: ";
    cin >> _nombre;
    CoordenadaXY(12,5);
    cout << "Escriba el Apellido: ";
    cin >> _apellido;
    CoordenadaXY(12,6);
    cout << "Escriba la direccion: ";
    cin >> _direccion;
    CoordenadaXY(12,7);
    cout << "Escriba el telefono: ";
    cin >> _telefono;
    CoordenadaXY(12,8);
    cout << "Escriba el celular: ";
    cin >> _celular;
    CoordenadaXY(12,9);
    cout << "Escriba fecha nacimiento dd/mm/aa: ";
    cin >> _fechaNacimiento;

    //Extrae el dia, mes y anio en una variable independiente para luego determinar la edad
    string _diaNacimiento = _fechaNacimiento.substr (0,2);
    string _mesDeNacimiento = _fechaNacimiento.substr (3,2);
    string _anioNacimiento = _fechaNacimiento.substr (6);

    Fecha despliegaFecha;
    string _fechaActual = despliegaFecha.fecha(); //Obtiene la fecha del sistema con la clase fecha.


    string _edadActual = Persona::edad(_diaNacimiento,_mesDeNacimiento, _anioNacimiento, _fechaActual); //Pasa las fechas a la funcion edad y la edad retorna la edad lol.

    for (x = 0; x <= 49; x++)
    {
        todasLasPersonas[x] = ""; //Este ciclo limpia el arreglo

    }

    datosDeEntrada.open("agenda.txt");
    contador = 0;
    if (datosDeEntrada)
        while (datosDeEntrada)
        {
            datosDeEntrada >> todasLasPersonas[contador];
            contador++;
        }
    datosDeEntrada.close();
    contador --;

    datosDeSalida.open("agenda.txt");

    datosDeSalida << _nombre <<endl;
    datosDeSalida << _apellido <<endl;
    datosDeSalida << _direccion <<endl;
    datosDeSalida << _telefono <<endl;
    datosDeSalida << _celular <<endl;
    datosDeSalida << _edadActual <<endl;

    for (x = 0; x <= contador; x++)
    {
        //Este siclo solo sirve para contar cuantos datos hay en el archivo para que no me destruya los que existen
    }

    for (x = 0; x <= contador; x++) //Esta condicion inidica que mientras allan datos en el arreglos que los guarde segun el lugar de X(comienza en 0)
    {
        //Guardando todo
        datosDeSalida << todasLasPersonas[x] <<endl;

    }
    datosDeSalida.close();
    cout <<endl;
    cout <<endl;
    cout <<nombre;
    ColorTexto(VERDE);
    TeclaPresionada("La persona fue agregada, presione una tecla para volver al menu");
    ColorTexto(PREESTABLECIDO);

}

string Persona::edad(string _diaDeNacimiento, string _mesDeNacimiento, string _anioDeNacimiento, string _fechaActual)
{


    int diaNacimiento;
    int mesNacimiento;
    int anioNacimiento;
    int diaActual;
    int mesActual;
    int anioActual;
    int edadActual;

    string _diaActual = _fechaActual.substr (0,2);
    string _mesActual = _fechaActual.substr (2,2);
    string _anioActual = _fechaActual.substr (4,4);

    if ( ! (istringstream(_diaDeNacimiento) >> diaNacimiento) ) diaNacimiento = 0; //Convierte de string a entero
    if ( ! (istringstream(_mesDeNacimiento) >> mesNacimiento) ) mesNacimiento = 0; //Convierte de string a entero
    if ( ! (istringstream(_anioDeNacimiento) >> anioNacimiento) ) anioNacimiento = 0; //Convierte de string a entero

    if ( ! (istringstream(_diaActual) >> diaActual) ) diaActual = 0; //Convierte de string a entero
    if ( ! (istringstream(_mesActual) >> mesActual) ) mesActual = 0; //Convierte de string a entero
    if ( ! (istringstream(_anioActual) >> anioActual) ) anioActual = 0; //Convierte de string a entero

    if ( mesNacimiento == mesActual)
    {
        if ( diaNacimiento > diaActual)
            edadActual = (anioActual - anioNacimiento);
        if ( diaNacimiento == diaActual)
            edadActual =  anioActual - anioNacimiento;
        if (diaNacimiento < diaActual )
            edadActual = (anioActual - anioNacimiento) -1;

    }
    if ( mesNacimiento < mesActual )
        edadActual = (anioActual - anioNacimiento );
    if ( mesNacimiento > mesActual )
        edadActual =  ( anioActual - anioNacimiento ) -1;

    string String = static_cast<ostringstream*>( &(ostringstream() <<  edadActual ) )->str(); //pasar de entero a string
    string _edadActual=String;

    return _edadActual;

    TeclaPresionada("Presione una tecla para volver al menu.");

}

void Persona::eliminar()
{
    cout <<"Estas dentro de eleminar:" <<endl;

    BorraPantalla();

    string _nombre[50];    //Arreglo para guardar todo lo de el archivo en memoria
    string _apellido[50];
    string _direccion[50];
    string _telefono[50];
    string _celular[50];
    string _edad[50];


    for (x = 0; x <= 49; x++)
    {
        _nombre[x] = "";
        _apellido[x] = "";
        _direccion[x] = "";
        _telefono[x] = "";
        _celular[x] = "";
        _edad[x] = "";
    }

    datosDeEntrada.open("agenda.txt");
    contador = 0;
    if (datosDeEntrada)
        while (datosDeEntrada)
        {
            datosDeEntrada >> _nombre[contador];
            datosDeEntrada >> _apellido[contador];
            datosDeEntrada >> _direccion[contador];     //Cada uno de estos arreglos se le asigna el valor indicado por el nombre cuando el for pasa por el
            datosDeEntrada >> _telefono[contador];      //osea que cada repeticion le asigna un valor a cada arreglo
            datosDeEntrada >> _celular[contador];
            datosDeEntrada >> _edad[contador];
            contador++;
        }
    datosDeEntrada.close();
    contador --;
    //Imprime los datos de los contactos respecto al cuadro que esta mas abajo
    for (x = 0; x <= contador; x++)
    {
        CoordenadaXY(1, (x+6));                 //La condicion de la coordernadaXY (segun yo) es relativa ose dependiendo del valor de X es que colocara
        cout << _nombre[x] <<endl;               //Cada valor del arreglo segun corresponda a la posicion del titulo.
        CoordenadaXY(14, (x+6));
        cout << _apellido[x] <<endl;
        CoordenadaXY(30, (x+6));
        cout << _direccion[x] <<endl;
        CoordenadaXY(45, (x+6));
        cout << _telefono[x] <<endl;
        CoordenadaXY(60, (x+6));
        cout << _celular[x] <<endl;
        CoordenadaXY(74, (x+6));
        cout << _edad[x] <<endl;
    }

    //Muestra el cuadro bonito de los contactos
    CoordenadaXY(26,1);
    cout <<"Estas son las personas agregadas hasta ahora.";
    CoordenadaXY(22,2);
    cout <<"Listado ordenado de personas en agenda." << endl;
    CoordenadaXY(6, 3);
    cout <<"-------------------------------------------------------------------" << endl;
    CoordenadaXY(1, 4);
    cout <<"Nombre";
    CoordenadaXY(14, 4);
    cout <<"Apellido";
    CoordenadaXY(30, 4);
    cout <<"Direccion";
    CoordenadaXY(45, 4);
    cout <<"Telefono";
    CoordenadaXY(60, 4);
    cout <<"Celular";
    CoordenadaXY(73, 4);
    cout <<"Edad";
    CoordenadaXY(6,5);
    cout <<"-------------------------------------------------------------------" << endl;

    //Eliminar

    string _eliminar, confirmarEliminar;
    int c;
    CoordenadaXY(10,contador+8);
    cout <<"digite nombre de la persona que desea borrar: ";
    cin >> _eliminar;
    ColorTexto(ROJO);
    CoordenadaXY(10,contador+10);
    cout <<"Esta seguro que desea eliminarlo ? escriba Si, de lo contrario escriba no: ";
    cin >>confirmarEliminar;
    ColorTexto(PREESTABLECIDO);
    if (confirmarEliminar =="si" || confirmarEliminar == "SI" || confirmarEliminar == "Si")
    {
        //Esto reemplaza un valor almacenado en una posicion con el valor de la posicion anterior.
        x = 0;
        while ((x < contador) && (_eliminar != _nombre[x]))
            x++;

        if (x != contador)
        {
            for (c = x; c <= contador - 1; c++) //donde X es la posicion en el arreglo donde esta lo buscado, C es una variable nueva para conteo.
                _nombre[c] = _nombre[c+1];            //-1 es para preveer el fin de archivo colocado por el sistema.
            _nombre[contador] = "";              //en el arreglo mencionado en la posicion se colocara nada.
            contador = c;                       //la posicion sera igual a el valor de C que a su vez es igual a la cantidad de datos que tiene al final el arreglo

        }

        if (x != contador)
        {
            for (c = x; c <= contador - 1; c++)
                _apellido[c] = _apellido[c+1];
            _apellido[contador] = "";
            contador = c;

        }
        if (x != contador)
        {
            for (c = x; c <= contador - 1; c++)
                _direccion[c] = _direccion[c+1];
            _direccion[contador] = "";
            contador = c;

        }
        if (x != contador)
        {
            for (c = x; c <= contador - 1; c++)
                _telefono[c] = _telefono[c+1];
            _telefono[contador] = "";
            contador = c;

        }
        if (x != contador)
        {
            for (c = x; c <= contador - 1; c++)
                _celular[c] = _celular[c+1];
            _celular[contador] = "";
            contador = c;

        }
        if (x != contador)
        {
            for (c = x; c <= contador - 1; c++)
                _edad[c] = _edad[c+1];
            _edad[contador] = "";
            contador = c;

        }
        else
        {
            BorraPantalla();
            while ((x < contador) && (_eliminar != _nombre[x]))
                x++;
            ColorTexto(ROJO);
            cout << "Ese nombre no esta en la lista." << endl << endl;
            ColorTexto(PREESTABLECIDO);
            cout <<endl;
            TeclaPresionada("Presione una tecla para continuar.");
        }
        BorraPantalla();

        //guarda el archivo
        datosDeSalida.open("agenda.txt");
        for (x = 0; x <= contador; x++) //Esta condicion inidica que mientras allan datos en el arreglos que los guarde segun el lugar de X(comienza en 0)
        {
            //Guardando todo
            datosDeSalida << _nombre[x] <<endl;
            datosDeSalida << _apellido[x] <<endl;
            datosDeSalida << _direccion[x] <<endl;
            datosDeSalida << _telefono[x] <<endl;
            datosDeSalida << _celular[x] <<endl;
            datosDeSalida << _edad[x] <<endl;

        }
        datosDeSalida.close();

        TeclaPresionada("La persona fue eliminada. Presione una tecla para volver al menu.");
    }
}

int main()
{

    int despliegaMenu();
    int opcion;

    BorraPantalla();

    Persona nuevapersona;

    do
    {

        opcion = despliegaMenu();
        if ( opcion == 1)
            nuevapersona.ver();

        if ( opcion == 2)
            nuevapersona.crear();

        if ( opcion == 3)
            nuevapersona.eliminar();

    }
    while (opcion  != 4);


    return 0;
}


int despliegaMenu()
{
    int opcion;

    BorraPantalla();

    cout <<setw (40) << "Don Churrusco Agenda 0.1" << endl;
    cout << endl;
    cout << endl;
    cout <<"Menu de Opciones";
    cout << endl;
    cout << endl;
    cout << "1.- Ver mis contactos" <<endl;
    cout << "2.- Agregar contacto" <<endl;
    cout << "3.- Eliminar contacto" <<endl;
    cout << "--------------" <<endl;
    cout << "4.- Salir" <<endl;
    cout << "Elija una opcion: ";
    cin >>  opcion;
    cout << endl;
    cout << endl;

    return opcion;


}
