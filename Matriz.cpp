#include "Matriz.h"
#include "iostream"
#include <cstdlib>
#include <exception>
using namespace std;

// Todos los valores a 0.
PROYECTO_1::Matriz::Matriz(): matriz{nullptr}, filas {0}, columnas{0} {

}

// Crear matriz
PROYECTO_1::Matriz::Matriz(int f, int c): filas {f}, columnas{c} {
    matriz = new int*[filas];
    try
    {
        if (filas != columnas)
        {
            throw logic_error("8");
        }
    }
    catch (const exception& e){ cout << "ERROR: "<< e.what() <<endl;
    }

    if(filas==columnas){
        for (int i= 0 ; i < filas; i++)
        {
            matriz[i] = new int[columnas];
        }
    }

}

// Destructor
PROYECTO_1::Matriz::~Matriz() {
        delete[] matriz;
}

// Llenar matriz
void PROYECTO_1::Matriz::llenar() {

    try
    {
        if (filas != columnas){
            throw  logic_error("8");
        }
    }
    catch (const exception& e)
    {
        cout<<"ERROR: " <<e.what();
    }
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz[i][j] = (rand() % 8) + 1;
        }
    }
}

// Imprimir matriz
void PROYECTO_1::Matriz::imprimir(){
    try
    {
        if (filas != columnas){
            throw  logic_error("8");
        }
    }
    catch (const exception& e)
    {
        cout<<"ERROR: " <<e.what();
    }
    for ( int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++) {
            cout<<matriz[i][j]<<" ";
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
void PROYECTO_1::Matriz::transposicion(const Matriz & M1) {

    Matriz temporal(M1);
    for (int i = 0; i < M1.filas; i++) {
        for (int j = 0; j < M1.columnas; j++) {
            matriz[i][j]=temporal.matriz[j][i];
        }
    }
}

// Sobrecarga de operador +
PROYECTO_1::Matriz PROYECTO_1::Matriz::operator+(const Matriz& M1){

    Matriz temporal(M1);
      for(int i = 0; i < M1.filas; i++){
        for (int j = 0; j < M1.columnas; j++) {
          temporal.matriz[i][j] += this->matriz[i][j];
        }
      }

      return temporal;
}

// Sobrecarga operador *
PROYECTO_1::Matriz PROYECTO_1::Matriz::operator*(const Matriz& M1){

    Matriz temporal(M1);
    for(int i = 0; i < M1.filas; i++){
        for(int j = 0; j < M1.columnas; ++j){
            temporal.matriz[i][j]=0;
            for(int z=0; z < this->columnas; ++z){
                temporal.matriz[i][j] = temporal.matriz[i][j] + this->matriz[i][z] * this->matriz[z][j];
              }
            }
          }
    return temporal;
}

PROYECTO_1::Matriz& PROYECTO_1::Matriz::operator=(const Matriz & M1) {

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
