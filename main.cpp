#include <iostream>
#include "./LUNormal.cpp"
#include "./Matrix.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    /*  Recebe uma matrix A e um vetor f
    e qual método deve ser usado para resolver o
    sistema (Fatoração LU normal ou Fatoração LU descrito)*/
    std::cout << "<Deslocamentos> <a11 a12 ... a1n a21 a22 ... ann> <f11 ... fn1>" << endl;
    std::cout << "Exemplo:" << endl << "A entrada" << endl << "3 3 -2 1 1 -3 4 9 4 -5 8 6 11" << endl << "Representa as matrizes" << endl << "    |3 -2 1|      |8 |" << endl << "A = |1 -3 4|  f = |6 |" << endl << "    |9 4 -5|      |11|" << endl << endl;

    int N;
    cin >> N;
    Matrix A(N);
    float aux;
    for (int i = 0; i < N; i++){
      for (int j = 0; j < N; j++){
        cin >> aux;
        A.addMatrix(i, j, aux);
      }
    }
    float f[N];
    for (int i = 0; i < N; i++){
      cin >> f[i];
    }
    // LUNormal LU;
    // LU.solveLinearSystem(A);
    // LUDescrito LDP;
    // LDP.solveLinearSystem(A);
    return 0;
}
