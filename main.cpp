#include <iostream>
#include "Matriz.cpp"
using namespace std;



int main() {


    int filas, columnas;
    cout<<"Ingresar filas: ";
    cin>>filas;
    cout<<"Ingrese columnas: ";
    cin>>columnas;

    PROYECTO_1::Matriz M1(filas,columnas);
    PROYECTO_1::Matriz M2(filas,columnas);
    PROYECTO_1::Matriz M3(filas,columnas);
    PROYECTO_1::Matriz M4(filas,columnas);
    PROYECTO_1::Matriz M5(filas,columnas);


    M1.llenar();
   if(filas == columnas)
   {
       std::cout << "Matriz 1: " << '\n';
   }
    M1.imprimir();
    cout <<endl;


    M2.llenar();
    if (filas == columnas)
    {
        std::cout << "Matriz 2:" << '\n';

    }
    M2.imprimir();
    cout <<endl;

    M3 = M1 * M2; //Sobrecarga operador * y +
    if (filas == columnas)
    {
        cout << "La multiplicacion es: " << '\n';
    }
    M3.imprimir();
    cout <<endl;

    M4.transposicion(M3);
    if (filas == columnas)
    {
        cout << "La transpuesta es: " << '\n';
    }
    M4.imprimir();
    cout <<endl;

    M5.escalar(M1,5);
    if (filas == columnas)
    {
        cout << "La mult escalar es: " << '\n';
    }
    M5.imprimir();

    return 0;
}

