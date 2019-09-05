#ifndef MATRIZ_DISPERSA_MATRIZ_H
#define MATRIZ_DISPERSA_MATRIZ_H


class Matriz {

private:
    int** matriz;
    int filas;
    int columnas;

public:
    Matriz(); // Cambian los datos que eran basura a cero o NULL
    Matriz( int, int); // Crear la matriz
    ~Matriz()= default; // Destructor
    void llenar();   // 1. Necesitamos llenar la matriz
    void imprimir(); // 2. Necesitamos imprimir la matriz
    void escalar(const Matriz&, int);
    void transposicion(const Matriz&);
    Matriz operator +(const Matriz&);
    Matriz operator *(const Matriz&);
    Matriz operator =(const Matriz&);

};



#endif //MATRIZ_DISPERSA_MATRIZ_H
