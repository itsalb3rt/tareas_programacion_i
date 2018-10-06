#include <iostream>
#include <fstream>
#include <iomanip>
#include "isr.hpp"
#include "esconu.h"

/* ############################################################################################ */
//Programa para calcular el impuesto sobre la renta (ISR)                                        /
//                                                                                               /
//   de un grupo de datos contenidos en el archivo                                               /
//          Albert E. Hidalgo Taveras   26/11/2016                                               /
//Calculo obtenido de http://www.dgii.gov.do/app/WebApps/Calculadoras/retenciones/js/reten.js    /
/* ############################################################################################ */
//Constructor
Isr::Isr (float nuevoSalario) //constructor que recibe un unico valor que es el salario
{
    setSalario ( nuevoSalario);

}
//Con esto obtengo el salario del archivo
void Isr::setSalario(float nuevoSalario)
{
    salario = nuevoSalario;
}
//Funcion para determinar el pago de impuesto
float Isr::DeterminaPago()
{
    salario= salario *12.00;
    if ( salario <= 409281.00) //Si el salario es menor a 409,281.00 no debe pagar impuesto sobre la renta
    {
        return 0.00;
    }

    if  (( salario >= 409281.01) && ( salario <= 613921.00))    //Si el salario es mayor a 409,281.01 y menor que 613,921.00paga un 15%
    {
        baseImponible = salario - 409281.01; //Para la base imponible se le resta el exedente inferior al salario anual
        determinaExcedente(); //esta funcion esta detallada mas abajo
        return excedente ;//Esto retorna el impuesto anunal
    }
    if ((salario >= 613921.01) && (salario <= 852667.00))   //Si el salario es mayor a 613,921.01 y menor que 852,667.00 paga un 20%
    {

        baseImponible = salario - 613921.01;
        determinaExcedente();
        return excedente ;
    }
    if ((salario >= 852667.01))
    {

        baseImponible = salario - 852667.01;
        determinaExcedente();
        return excedente ;
    }
}
//Determinar la Exencion
float Isr::determinaExcedente()
{
    if ((salario >= 409281.01) && (salario <= 613921.00))
    {
        excedente = (baseImponible * 0.15); //Se multiplica la baseimponible por 0.15 en este caso.
        return excedente;   //Retorna la multiplicacion a donde sea que se le lleme a esta funcion.

    }
    if ((salario >= 613921.01) && (salario <= 833171.00))
    {
        excedente = ((baseImponible * 0.20) + 30696.00);
        return excedente;
    }
    if (salario >= 852667.00)
    {
        excedente = (baseImponible * 0.25) + 78446.00;
        return excedente;
    }

}

using namespace std;

int main()

{
    BorraPantalla();
    ColorTexto(PREESTABLECIDO);

    //heap

    int maxArreglo = 50; // Tuve que declararlo asi para que en windows no me diera error la consola
    int contador = 0;     //Windows me da error si lo declaro en el heap y lo utilizo como valor de un arreglo
    float* salario = new float[maxArreglo];
    string* nombres = new string[maxArreglo];
    string* nombre = new string[maxArreglo];
    string* apellido = new string[maxArreglo];


    //Archivo
    ifstream* datosEntrada = new ifstream;          //Declaracion de archivo de entrada en el heap
    (*datosEntrada).open("Datos.txt");
    BorraPantalla();
    //Titulos
    cout <<setw (50) << "Asesoria de Impuestos Don Churumusco" <<endl;
    cout << setw(44) <<"Reporte de ISR" <<endl;
    cout  << setw(19) << "| Contribuyente |" << setw(50) << "| Monto a Pagar |" <<endl;
    cout <<"-----------------------------------------------------------------" <<endl;

    while (*datosEntrada)   //Carga todo lo que esta en el archivo a un arreglo llamado nombres mientras existan datos en le archivo
    {
        *datosEntrada >> nombres[contador] >> salario[contador]; //Carga los nombres y luego los salarios ya que tienen un espacio que los separa
        contador++;                                                 // haciendo mas facil la aginacion de los mismos a los arreglos
    }
    (*datosEntrada).close();

    contador--;         //Elimina el conteo del final de linea
    for (int x = 0; x < contador ; x++) //For para eliminar las arrobas
    {
        Isr *NuevoIsr =  new Isr (salario[x]);  //Objeto para pasar el salario al constructor

        for (int y = 0;  y < nombres[x].length ();  y++) //Este for quita las arrobas del arreglo previamente asignado para guardar los nombres
        {
            if (nombres[x][y] == '@')   //arreglo bidimencional que busca arrobas en columnas y filas de un arreglo normal
                nombres[x].replace(y,1, " ");
            //if (nombres[x][y] == *comas)
            // nombres[x].replace(y,1, *espacios);
        }

        nombre[x] = (nombres[x]).substr(0,(nombres[x]).find(","));  //va desde la linea 0 hasta la coma y copia en el puntero todo lo que este antes de la coma

        apellido[x] = (nombres[x]).substr((nombres[x]).find(",")+1);  //va desde la coma hasta el final y lo copia en el puntero

        cout  << left <<setw(2) << x+1 << ".- " << setw(46) << apellido[x] + ", " + nombre[x]  << right //Escribe los nombres en formado Apellido Nombre.
        << setw (10) << fixed << setprecision (2) <<"RD$" << (*NuevoIsr).DeterminaPago()  << endl; //El objeto NuevoIsr da el pago calculado por la funcion DeterminaPago

    }

    delete datosEntrada;
    delete nombres;
    delete salario;         //elimina todo lo que esta en el heap
    delete nombre;
    delete apellido;

    nombres = NULL;
    salario = NULL;         //Asigna valor nulo a los arreglos
    nombre = NULL;
    apellido = NULL;



    return 0;
}
