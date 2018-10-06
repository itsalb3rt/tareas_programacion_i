
#include <iostream>
#include <fstream>
#include "esconu.h"


using namespace std;

int menu();
void listarLibros();
void agregarLirbo();
void eliminarLibro();


int main()
{


    int opcion;

    //Esto inicia un cliclo el cual entra enseguida inicia el programa para mostrar el menu.
    do
    {
        opcion = menu();

        if (opcion == 1)
            listarLibros();

        if (opcion == 2)
            agregarLirbo();

        if (opcion == 3)
            eliminarLibro();

    }
    while (opcion !=4 );

    cout <<"Presione una tecla para salir.";
    ColorTexto(NEGRO);

    return 0;
}

int menu ()
{
    int opcion;
    BorraPantalla();

    CoordenadaXY(8,1);
    cout <<"----------------------------------------------------------------" << endl;
    CoordenadaXY(8,5);
    cout <<"----------------------------------------------------------------" << endl;
    CoordenadaXY(8,13);
    cout <<"----------------------------------------------------------------" << endl;

    ColorTexto(VERDE);
    CoordenadaXY(27, 1);
    cout << "Biblioteca Don Churumusco!";
    ColorTexto(PREESTABLECIDO);
    cout << endl;
    cout << endl;
    CoordenadaXY(31, 4);
    cout <<"Menu de Opciones";
    cout << endl;
    cout << endl;
    ColorTexto(AZUL);
    CoordenadaXY(31, 7);
    cout << "1.- Listar libros" <<endl;
    ColorTexto(PREESTABLECIDO);
    CoordenadaXY(31, 8);
    cout << "2.- Agregar libro" <<endl;
    ColorTexto(ROJO);
    CoordenadaXY(31, 9);
    cout << "3.- Eliminar libro" <<endl;
    ColorTexto(PREESTABLECIDO);
    CoordenadaXY(31, 10);
    cout << "--------------" <<endl;
    CoordenadaXY(31, 11);
    cout << "4.- Salir" <<endl;
    CoordenadaXY(31, 12);
    cout << "Elija una opcion: ";
    cin >>  opcion;
    cout << endl;
    cout << endl;
    return opcion;
}

void listarLibros()
{
    /*Aqui muestra todos los datos que hay en el archivo de texto, no necesariamente con la misma organizacion del archivo*/


    BorraPantalla();



    string codigo[50];    //Arreglo para guardar todo lo de el archivo en memoria
    string nombre[50];
    string titulo[50];
    string fecha[50];
    string editora[50];

    int posicion,x, c;      //Viables para el flujo de control.
    ifstream datosDeEntrada;
    ofstream datosDeSalida;



    //Esto es por si hay algo en la memoria, limpia el arreglo.
    for (x = 0; x <= 49; x++)
    {
        codigo[x] = "";
        nombre[x] = "";
        titulo[x] = "";
        fecha[x] = "";
        editora[x] = "";
    }



    //Esto prueba si el archivo existe, de ser asi asigan todos los datos a el arreglo.
    datosDeEntrada.open("librosguardados.txt");
    posicion = 0;
    if (datosDeEntrada)
        while (datosDeEntrada)
        {
            datosDeEntrada >> codigo[posicion];
            datosDeEntrada >> nombre[posicion];
            datosDeEntrada >> titulo[posicion];     //Cada uno de estos arreglos se le asigna el valor indicado por el nombre cuando el for pasa por el
            datosDeEntrada >> fecha[posicion];      //osea que cada repeticion le asigna un valor a cada arreglo
            datosDeEntrada >> editora[posicion];

            posicion++;
        }
    datosDeEntrada.close();
    //Esto coloca el cuadro donde se mostraran los datos del archivo.
    posicion --;
    CoordenadaXY(26,1);
    cout <<"Biblioteca Don Churumusco" << endl;
    CoordenadaXY(22,2);
    cout <<"Listado de libros en existencia: " << endl;
    CoordenadaXY(3, 3);
    cout <<"------------------------------------------------------------------" << endl;
    CoordenadaXY(1, 4);
    cout <<"codigo";
    CoordenadaXY(10, 4);
    cout <<"Titulo";
    CoordenadaXY(30, 4);
    cout <<"Autor";
    CoordenadaXY(45, 4);
    cout <<"Fecha";
    CoordenadaXY(60, 4);
    cout <<"Editora";
    CoordenadaXY(3,5);
    cout <<"------------------------------------------------------------------" << endl;
    for (x = 0; x <= posicion; x++)
    {
        CoordenadaXY(1, (x+6));                 //La condicion de la coordernadaXY (segun yo) es relativa ose dependiendo del valor de X es que colocara
        cout << codigo[x] <<endl;               //Cada valor del arreglo segun corresponda a la posicion del titulo.
        CoordenadaXY(10, (x+6));
        cout << nombre[x] <<endl;
        CoordenadaXY(30, (x+6));
        cout << titulo[x] <<endl;
        CoordenadaXY(45, (x+6));
        cout << fecha[x] <<endl;
        CoordenadaXY(60, (x+6));
        cout << editora[x] <<endl;
    }

    CoordenadaXY(3,x+6);
    cout <<"------------------------------------------------------------------" << endl;
    TeclaPresionada("Presione una tecla para volver al menu.");     //Esta funcion espera que se presione cualquier tecla para volver al menu.


}

void agregarLirbo()
{

    /*Esta funcion agrega los libros, y te muestra los que ya hay en existencia */

    BorraPantalla();

    string codigo[50];    //Arreglo para guardar todo lo de el archivo en memoria
    string nombre[50];
    string titulo[50];
    string fecha[50];
    string editora[50];

    int posicion,x;      //Viables para el flujo de control.
    string agregarMasLibros;
    ifstream datosDeEntrada;
    ofstream datosDeSalida;



    //Esto es por si hay algo en la memoria, se limpie el arreglo.
    for (x = 0; x <= 49; x++)
    {
        codigo[x] = "";
        nombre[x] = "";
        titulo[x] = "";
        fecha[x] = "";
        editora[x] = "";
    }



    //Esto prueba si el archivo existe, de ser asi asigan todos los datos a el arreglo.
    datosDeEntrada.open("librosguardados.txt");
    posicion = 0;
    if (datosDeEntrada)
        while (datosDeEntrada)
        {
            datosDeEntrada >> codigo[posicion];
            datosDeEntrada >> nombre[posicion];
            datosDeEntrada >> titulo[posicion];     //Cada uno de estos arreglos se le asigna el valor indicado por el nombre cuando el for pasa por el
            datosDeEntrada >> fecha[posicion];      //osea que cada repeticion le asigna un valor a cada arreglo
            datosDeEntrada >> editora[posicion];

            posicion++;
        }
    datosDeEntrada.close();

    posicion --;

    //Esto coloca el cuadro donde se mostraran los datos del archivo.

    CoordenadaXY(26,1);
    cout <<"Biblioteca Don Churumusco" << endl;
    CoordenadaXY(22,2);
    cout <<"Listado de libros en existencia: " << endl;
    CoordenadaXY(3, 3);
    cout <<"------------------------------------------------------------------" << endl;
    CoordenadaXY(1, 4);
    cout <<"codigo";
    CoordenadaXY(10, 4);
    cout <<"Titulo";
    CoordenadaXY(30, 4);
    cout <<"Autor";
    CoordenadaXY(45, 4);
    cout <<"Fecha";
    CoordenadaXY(60, 4);
    cout <<"Editora";
    CoordenadaXY(3,5);
    cout <<"------------------------------------------------------------------" << endl;
    for (x = 0; x <= posicion; x++)
    {
        CoordenadaXY(1, (x+6));                 //La condicion de la coordernadaXY (segun yo) es relativa ose dependiendo del valor de X es que colocara
        cout << codigo[x] <<endl;               //Cada valor del arreglo segun corresponda a la posicion del titulo.
        CoordenadaXY(10, (x+6));
        cout << nombre[x] <<endl;
        CoordenadaXY(30, (x+6));
        cout << titulo[x] <<endl;
        CoordenadaXY(45, (x+6));
        cout << fecha[x] <<endl;
        CoordenadaXY(60, (x+6));
        cout << editora[x] <<endl;
    }

    CoordenadaXY(3,x+6);
    cout <<"------------------------------------------------------------------" << endl;
    cout <<"Ingrese los datos requeridos a continuacion para agregar un nuevo libro" <<endl;
    cout <<"Digite el codigo:";
    cin >> codigo[posicion];
    cout <<"Digite el nombre del autor: ";
    cin >> nombre[posicion];
    cout <<"Digite el titulo del libro: ";
    cin >> titulo[posicion];
    cout << "Digite la fecha de salida del libro: ";
    cin >> fecha[posicion];
    cout << "Digite la editora: ";
    cin >> editora[posicion];
    cout << endl;
    posicion++;

    BorraPantalla();

    //Esto coloca el cuadro donde se mostraran los datos del archivo.
    posicion --;
    CoordenadaXY(26,1);
    cout <<"Biblioteca Don Churumusco" << endl;
    CoordenadaXY(22,2);
    cout <<"Listado de libros en existencia: " << endl;
    CoordenadaXY(3, 3);
    cout <<"------------------------------------------------------------------" << endl;
    CoordenadaXY(1, 4);
    cout <<"codigo";
    CoordenadaXY(10, 4);
    cout <<"Titulo";
    CoordenadaXY(30, 4);
    cout <<"Autor";
    CoordenadaXY(45, 4);
    cout <<"Fecha";
    CoordenadaXY(60, 4);
    cout <<"Editora";
    CoordenadaXY(3,5);
    cout <<"------------------------------------------------------------------" << endl;
    for (x = 0; x <= posicion; x++)
    {
        CoordenadaXY(1, (x+6));                 //La condicion de la coordernadaXY (segun yo) es relativa ose dependiendo del valor de X es que colocara
        cout << codigo[x] <<endl;               //Cada valor del arreglo segun corresponda a la posicion del titulo.
        CoordenadaXY(10, (x+6));
        cout << nombre[x] <<endl;
        CoordenadaXY(30, (x+6));
        cout << titulo[x] <<endl;
        CoordenadaXY(45, (x+6));
        cout << fecha[x] <<endl;
        CoordenadaXY(60, (x+6));
        cout << editora[x] <<endl;
    }

    CoordenadaXY(3,x+6);
    cout <<"------------------------------------------------------------------" << endl;


    //guarda el archivo
    datosDeSalida.open("librosguardados.txt");

    for (x = 0; x <= posicion; x++) //Esta condicion inidica que mientras allan datos en el arreglos que los guarde segun el lugar de X(comienza en 0)
    {
        //Guardando todo
        datosDeSalida << codigo[x] <<endl;
        datosDeSalida << nombre[x] <<endl;
        datosDeSalida << titulo[x] <<endl;
        datosDeSalida << fecha[x] <<endl;
        datosDeSalida << editora[x] <<endl;

    }
    datosDeSalida.close();




}

void eliminarLibro()
{
    /* Esta funcion elimina 1 libro que el usuario dese, por el codigo unicamente...por ahora.*/

    BorraPantalla();

    string codigo[50];    //Arreglo para guardar todo lo de el archivo en memoria
    string nombre[50];
    string titulo[50];
    string fecha[50];
    string editora[50];

    int posicion,x, c;      //Viables para el flujo de control.
    string agregarMasLibros;
    string eliminarLibro;
    string confirmarEliminar;
    ifstream datosDeEntrada;
    ofstream datosDeSalida;



    //Esto es por si hay algo en la memoria, limpia el arreglo.
    for (x = 0; x <= 49; x++)
    {
        codigo[x] = "";
        nombre[x] = "";
        titulo[x] = "";
        fecha[x] = "";
        editora[x] = "";
    }



    //Esto prueba si el archivo existe, de ser asi asigan todos los datos a el arreglo.
    datosDeEntrada.open("librosguardados.txt");
    posicion = 0;
    if (datosDeEntrada)
        while (datosDeEntrada)
        {
            datosDeEntrada >> codigo[posicion];
            datosDeEntrada >> nombre[posicion];
            datosDeEntrada >> titulo[posicion];     //Cada uno de estos arreglos se le asigna el valor indicado por el nombre cuando el for pasa por el
            datosDeEntrada >> fecha[posicion];      //osea que cada repeticion le asigna un valor a cada arreglo
            datosDeEntrada >> editora[posicion];

            posicion++;
        }
    datosDeEntrada.close();
    //Esto coloca el cuadro donde se mostraran los datos del archivo.
    posicion --;
    CoordenadaXY(26,1);
    cout <<"Biblioteca Don Churumusco" << endl;
    CoordenadaXY(22,2);
    cout <<"Listado de libros en existencia: " << endl;
    CoordenadaXY(3, 3);
    cout <<"------------------------------------------------------------------" << endl;
    CoordenadaXY(1, 4);
    cout <<"codigo";
    CoordenadaXY(10, 4);
    cout <<"Titulo";
    CoordenadaXY(30, 4);
    cout <<"Autor";
    CoordenadaXY(45, 4);
    cout <<"Fecha";
    CoordenadaXY(60, 4);
    cout <<"Editora";
    CoordenadaXY(3,5);
    cout <<"------------------------------------------------------------------" << endl;
    for (x = 0; x <= posicion; x++)
    {
        CoordenadaXY(1, (x+6));                 //La condicion de la coordernadaXY (segun yo) es relativa ose dependiendo del valor de X es que colocara
        cout << codigo[x] <<endl;               //Cada valor del arreglo segun corresponda a la posicion del titulo.
        CoordenadaXY(10, (x+6));
        cout << nombre[x] <<endl;
        CoordenadaXY(30, (x+6));
        cout << titulo[x] <<endl;
        CoordenadaXY(45, (x+6));
        cout << fecha[x] <<endl;
        CoordenadaXY(60, (x+6));
        cout << editora[x] <<endl;
    }

    CoordenadaXY(3,x+6);
    cout <<"------------------------------------------------------------------" << endl;


    cout <<"Escriba el codigo del libro que desea eliminar: ";
    cin >> eliminarLibro;
    ColorTexto(ROJO);
    cout <<"Esta seguro que desea eliminarlo ? escriba Si, de lo contrario escriba no: ";
    cin >>confirmarEliminar;
    ColorTexto(PREESTABLECIDO);
    if (confirmarEliminar =="si" || confirmarEliminar == "SI" || confirmarEliminar == "Si")
    {
        //Esto reemplaza un valor almacenado en una posicion con el valor de la posicion anterior.
        x = 0;
        while ((x < posicion) && (eliminarLibro != codigo[x]))
            x++;

        if (x != posicion)
        {
            for (c = x; c <= posicion - 1; c++) //donde X es la posicion en el arreglo donde esta lo buscado, C es una variable nueva para conteo.
                codigo[c] = codigo[c+1];            //-1 es para preveer el fin de archivo colocado por el sistema.
            codigo[posicion] = "";              //en el arreglo mencionado en la posicion se colocara nada.
            posicion = c;                       //la posicion sera igual a el valor de C que a su vez es igual a la cantidad de datos que tiene al final el arreglo

        }

        if (x != posicion)
        {
            for (c = x; c <= posicion - 1; c++)
                nombre[c] = nombre[c+1];
            nombre[posicion] = "";
            posicion = c;

        }
        if (x != posicion)
        {
            for (c = x; c <= posicion - 1; c++)
                titulo[c] = titulo[c+1];
            titulo[posicion] = "";
            posicion = c;

        }
        if (x != posicion)
        {
            for (c = x; c <= posicion - 1; c++)
                fecha[c] = fecha[c+1];
            fecha[posicion] = "";
            posicion = c;

        }
        if (x != posicion)
        {
            for (c = x; c <= posicion - 1; c++)
                editora[c] = editora[c+1];
            editora[posicion] = "";
            posicion = c;

        }
        else
        {
            BorraPantalla();
            while ((x < posicion) && (eliminarLibro != codigo[x]))
                x++;
            ColorTexto(ROJO);
            cout << "Ese codigo no esta en la lista." << endl << endl;
            ColorTexto(PREESTABLECIDO);
            cout <<endl;
            TeclaPresionada("Presione una tecla para continuar.");
        }
        BorraPantalla();
//Esto coloca el cuadro donde se mostraran los datos del archivo.
        posicion --;
        CoordenadaXY(26,1);
        cout <<"Biblioteca Don Churumusco" << endl;
        CoordenadaXY(22,2);
        cout <<"Listado de libros en existencia: " << endl;
        CoordenadaXY(3, 3);
        cout <<"------------------------------------------------------------------" << endl;
        CoordenadaXY(1, 4);
        cout <<"codigo";
        CoordenadaXY(10, 4);
        cout <<"Titulo";
        CoordenadaXY(30, 4);
        cout <<"Autor";
        CoordenadaXY(45, 4);
        cout <<"Fecha";
        CoordenadaXY(60, 4);
        cout <<"Editora";
        CoordenadaXY(3,5);
        cout <<"------------------------------------------------------------------" << endl;
        for (x = 0; x <= posicion; x++)
        {
            CoordenadaXY(1, (x+6));                 //La condicion de la coordernadaXY (segun yo) es relativa ose dependiendo del valor de X es que colocara
            cout << codigo[x] <<endl;               //Cada valor del arreglo segun corresponda a la posicion del titulo.
            CoordenadaXY(10, (x+6));
            cout << nombre[x] <<endl;
            CoordenadaXY(30, (x+6));
            cout << titulo[x] <<endl;
            CoordenadaXY(45, (x+6));
            cout << fecha[x] <<endl;
            CoordenadaXY(60, (x+6));
            cout << editora[x] <<endl;
        }

        CoordenadaXY(3,x+6);
        cout <<"------------------------------------------------------------------" << endl;

        //guarda el archivo
        datosDeSalida.open("librosguardados.txt");
        for (x = 0; x <= posicion; x++) //Esta condicion inidica que mientras allan datos en el arreglos que los guarde segun el lugar de X(comienza en 0)
        {
            //Guardando todo
            datosDeSalida << codigo[x] <<endl;
            datosDeSalida << nombre[x] <<endl;
            datosDeSalida << titulo[x] <<endl;
            datosDeSalida << fecha[x] <<endl;
            datosDeSalida << editora[x] <<endl;

        }
        datosDeSalida.close();


    }

    TeclaPresionada("Presione una tecla para volver al menu.");


}
