#include "Matriz.h"

using namespace std;


Matriz::Matriz(): matriz{nullptr}, filas {0}, columnas{0} {

}

Matriz::Matriz(int f, int c): filas {f}, columnas{c}
{
    matriz = new int*[filas];
    for (int i= 0 ; i < filas; i++)
    {
        matriz[i] = new int[columnas];
    }

}


void Matriz::sumar(const Matriz& Matriz1) {

    int matriz_re[filas][columnas];
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; ++j) {
            matriz_re[i][j] = Matriz1[i][j]


        }


    }

    }

    void Matriz::multiplicar(const Matriz &, const Matriz &) {

    }

    void Matriz::escalar(const Matriz &, const Matriz &) {

    }

    void Matriz::transposicion(const Matriz &) {

    }

    Matriz::~Matriz()
    {

    }






