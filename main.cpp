#include <iostream>
#include "Matriz.cpp"
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr));

    cout<< "OPERACIONES CON MATRICES CUADRADAS"<<endl;
    int filas, columnas;
    cout<<"Ingresa las filas: ";
    cin>>filas;
    cout<<"Ingresa las columnas: ";
    cin >> columnas;



        auto M1=new PROYECTO_1::Matriz(filas,columnas);
        auto M2=new PROYECTO_1::Matriz(filas,columnas);
        auto M3=new PROYECTO_1::Matriz(filas,columnas);
        auto M4=new PROYECTO_1::Matriz(filas,columnas);
        auto M5 = new PROYECTO_1::Matriz(filas,columnas);

        M1->llenar();
        cout << "Matriz 1: " << '\n';
        M1->imprimir();
        cout << endl;


        M2->llenar();
        cout << "Matriz 2:" << '\n';
        M2->imprimir();
        cout << endl;

        *M3 = *M1 + *M2;

        cout << "La suma de M1 y M2 es: " << '\n';
        M3->imprimir();
        cout << endl;


        M4->escalar(*M1, 5);

        cout << "La mult escalar M1 es: " << '\n';
        M4->imprimir();


        M5->transposicion(*M1);

        cout << "La transpuesta de M1 es: " << '\n';
        M5->imprimir();
        cout << endl;


        auto M6 = new PROYECTO_1::Matriz(filas, columnas);
        auto M7 = new PROYECTO_1::Matriz(filas, columnas);


        M6->llenar();

        cout << "Matriz x: " << '\n';
        M6->imprimir();
        cout << endl;

        M7->llenar();
        cout << "Matriz y:" << '\n';
        M7->imprimir();

        cout << endl;


        auto M8 = new PROYECTO_1::Matriz(filas, columnas);

        *M8 = *M6 * *M7; //Sobrecarga operador *

        cout << "La multiplicacion de Mx y My es: " << '\n';
        M8->imprimir();
        cout << endl;

        delete M1;
        delete M2;
        delete M3;
        delete M4;
        delete M5;
        delete M6;
        delete M7;
        delete M8;



        cout << "ERROR: No es una matriz cuadrada";

    return 0;

}

