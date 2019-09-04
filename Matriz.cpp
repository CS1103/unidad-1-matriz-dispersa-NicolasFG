#include "Matriz.h"

using namespace std;

// Todos los valores a 0.
Matriz::Matriz(): matriz{nullptr}, filas {0}, columnas{0} {

}

// Crear matriz
Matriz::Matriz(int f, int c): filas {f}, columnas{c} {


    matriz = new int*[filas];
    for (int i= 0 ; i < filas; i++)
    {
        matriz[i] = new int[columnas];
    }
}

// Destructor
Matriz::~Matriz() {

}

// Llenar matriz (por ahora se va a llenar sin dispersion para probar si funciona)
void Matriz::llenar(){

  for ( int i = 0; i < filas; i++) {
      for (int j = 0; j < columnas; j++) {
          std::cout << "["<<i<<"]"<<"["<<j<<"]";
          std::cin >> matriz[i][j];
    }
  }

}

// Imprimir matriz
void Matriz::imprimir(){

  for ( int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      cout<<matriz[i][j]<<" ";
    }
    cout << endl;
  }

}

// Multiplicar matrices
void Matriz::multiplicar(const Matriz &, const Matriz &) {



}

// Producto Punto
void Matriz::escalar(const Matriz& M1, int num) {

    Matriz temporal(M1);
    for (int i = 0; i < M1.filas; i++) {
        for (int j = 0; j < M1.columnas; j++) {
            matriz[i][j] = temporal.matriz[i][j] * num;
        }
    }
}

Matriz::Matriz(int i) {

}

// Trasposición de matriz
void Matriz::transposicion(const Matriz & M1) {

    Matriz temporal(M1);
    for (int i = 0; i < M1.filas; i++) {
        for (int j = 0; j < M1.columnas; j++) {
            matriz[i][j]=temporal.matriz[j][i];
        }
    }
}

// Sobrecarga de operador +
Matriz Matriz::operator+(const Matriz& M1){

    Matriz temporal(M1);
      for(int i = 0; i < M1.filas; i++){
        for (int j = 0; j < M1.columnas; j++) {
          temporal.matriz[i][j] += this->matriz[i][j];
        }
      }

      return temporal;
}

// Sobrecarga operador *
Matriz Matriz::operator*(const Matriz& M1){

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

Matriz& Matriz::operator=(const Matriz & M1) {

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
