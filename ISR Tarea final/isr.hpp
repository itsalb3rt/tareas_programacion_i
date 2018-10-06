#include <iostream>
#include <fstream>



/* ################################################################# */
//Programa para calcular el impuesto sobre la renta (ISR)      /
//                                                                    /
//   de un grupo de datos contenidos en el archivo â€œdatos.txtâ€     /
//                       Albert E. Hidalgo Taveras                    /
/* ################################################################# */

using namespace std;

class Isr
{
public:

    Isr(float nuevoSalario);
    ~Isr () {};
    void setSalario ( float nuevoSalario); //setter para el salario
    void getSalario () const;   //Obtener salario
    float determinaExcedente();
    float DeterminaPago();      //Determina el pago del impuesto


    private:
        float salario; //guardan el salrio
        float excedente; //guarda el excedente
        float baseImponible; //BaseImponible
};
