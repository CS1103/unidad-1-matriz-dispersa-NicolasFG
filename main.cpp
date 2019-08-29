#include <iostream>
#include <cassert>
#include "Matriz.cpp"
using namespace std;




int main() {


    Matriz M1;
    Matriz M2;
    Matriz M3;


    int M4 [3][3] = { {1, 2 ,3}, {4,5,6} };
    int M5 [3][3] = { {15,23,31}, {14,17,18}, {41,63,65} };
    int M6 = ;
    int M7 [4][4] = { {1, 2,3,4}, {4,5,6,7} };



    assert(M3.sumar(M1, M2) == M4);
    assert(M3.multiplicar(M1, M2) == M5);
    assert(M3.escalar(M1, M2) == M6);
    assert(M3.transposicion(M1, M2) == M7);








    return 0;
}