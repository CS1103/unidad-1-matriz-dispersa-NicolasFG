#include "Matriz.h"
#include "iostream"
#include "exception"

using namespace std;

// Todos los valores a 0.
PROYECTO_1::Matriz::Matriz(): matriz{nullptr}, filas {0}, columnas{0} {

}

// Crear matriz
PROYECTO_1::Matriz::Matriz(int f, int c): filas {f}, columnas{c} {
    try{
        if(filas != columnas)
        {
            throw  (std::exception());
        }
    }

    catch (exception e) {

        cout << "ERROR: " << e.what() <<endl;

    }
    matriz = new int*[filas];
    for (int i= 0 ; i < filas; i++){
        matriz[i] = new int[columnas];
    }
}

// Destructor por defecto

// Llenar matriz
void PROYECTO_1::Matriz::llenar() {

    try {
        if (filas != columnas) {
            throw (std::exception());
        } else {

            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                    matriz[i][j] = (rand() % 8) + 1;
                }
            }
        }}
    catch (exception
           e) {

        cout << "ERROR: " << e.what() << endl;
    }
}


// Imprimir matriz
void PROYECTO_1::Matriz::imprimir(){
    try{
        if(filas != columnas)
        {
            throw  (std::exception());
        }
    }

    catch (exception e) {
        cout << "ERROR: " << e.what()<<endl;
    }
    for ( int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout<<matriz[i][j]<<"  ";
        }
        cout << endl;
    }
}


// Producto Punto
void PROYECTO_1::Matriz::escalar(const Matriz& M1, int num) {

    Matriz temporal(M1);
    for (int i = 0; i < M1.filas; i++) {
        for (int j = 0; j < M1.columnas; j++) {
            matriz[i][j] = temporal.matriz[i][j] * num;
        }
    }
}


// Trasposición de matriz
void PROYECTO_1::Matriz::transposicion(const Matriz& M1) {

    Matriz temporal(M1);
    for (int i = 0; i < M1.filas; i++) {
        for (int j = 0; j < M1.columnas; j++) {
            matriz[i][j]=temporal.matriz[j][i];
        }
    }
}


// Sobrecarga de operador + (suma)
PROYECTO_1::Matriz PROYECTO_1::Matriz::operator+(const Matriz& M1){

    Matriz temporal(M1);
    for(int i = 0; i < M1.filas; i++){
        for (int j = 0; j < M1.columnas; j++) {
            temporal.matriz[i][j] += this->matriz[i][j];
        }
    }
    return temporal;
}

// Sobrecarga operador * (multiplicacion)
PROYECTO_1::Matriz PROYECTO_1::Matriz::operator*(const Matriz &M2){
    auto temp=new Matriz(filas,columnas);
    for(int i=0; i<filas; ++i)
        for(int j=0; j<columnas; ++j)
            for(int z=0; z<columnas; ++z)
                temp->matriz[i][j] += this->matriz[i][z] * M2.matriz[z][j];
    return *temp;
}

// Sobrecarga operador =
PROYECTO_1::Matriz PROYECTO_1::Matriz::operator=(const Matriz & M1) {

    if(this->filas !=0 && this->columnas!=0){
        delete [] this->matriz;
    }

    this->filas = M1.filas;
    this->columnas = M1.columnas;

    this->matriz = new int*[this->filas];

    for (int i = 0; i < this->filas; ++i) {
        this->matriz[i] = new int[this->columnas];
        for (int j = 0; j < this->columnas; ++j) {
            this->matriz[i][j] = M1.matriz[i][j];
        }
    }
    return *this;
}




