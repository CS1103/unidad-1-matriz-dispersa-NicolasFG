#ifndef MATRIZ_DISPERSA_MATRIZ_H
#define MATRIZ_DISPERSA_MATRIZ_H


class Matriz {

private:
    int** matriz;
    int filas;
    int columnas;

public:
    Matriz();
    Matriz( int, int);

    void sumar(const Matriz&);
    void multiplicar(const Matriz&, const Matriz&);
    void escalar(const Matriz&, const Matriz&);
    void transposicion(const Matriz&);





    virtual ~Matriz();


};



#endif //MATRIZ_DISPERSA_MATRIZ_H
