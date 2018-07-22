#include "matrix.hpp"
#include <iostream>

int main(void)
{
    Matrix * A = new Matrix(-1.0, 1.0, 2.0, 3.0);
    Matrix * B = new Matrix(2.0, 2.0, 2.0, 2.0);

    std::cout << "A: " << std::endl;
    A->output();
    std::cout << "B: " << std::endl;
    B->output();

    // // +=
    // std::cout << "A:\t += " << std::endl;
    // *A += *B;
    // A->output();
    // *=
    // std::cout << "A:\t *= " << std::endl;
    // *A *= *B;
    // A->output();
    // // =
    // std::cout << "A:\t = " << std::endl;
    // *A = *B;
    // A->output();
    // -=
    // std::cout << "A:\t -= " << std::endl;
    // *A -= *B;
    // A->output();
    // // == 
    // std::cout << "Bool == :  " << (B == A) << std::endl;
    
    // //setAllValues
    // A->setAll(1.0, 1.0, 2.0, 3.0);

    // //setByIndex 11 entspricht erste zeile erste spalte
    // A->setByIndex(11,-1.0);

    //Determinante von B
    std::cout << "determinante von B: " << B->determinante() << std::endl;
    std::cout << "determinante von A: " << A->determinante() << std::endl;

    // //B^7
    B->pow(7);
    std::cout << "B ^ 7 : " << std::endl;
    B->output();
    
    // //B * A
    // std::cout << "B * A : " << std::endl;
    // B->setAll(5.0, -8.0, 13.0, -21.0);
    // B->mult(*A);
    // B->output();
}