#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;

class Matrix
{
private:
   int m_rowSize;
   int m_colSize;
   float **matrix;

public:
   Matrix(int Size)
   {
      m_rowSize = Size;
      m_colSize = Size;
      matrix = new float *[m_rowSize];
      for (int i = 0; i < m_rowSize; ++i)
         matrix[i] = new float[m_colSize];
   }
   void deleteMatrix(void)
   {
      for (int i = 0; i < m_rowSize; ++i)
         delete[] matrix[i];
      delete[] matrix;
   }
   int getSize()
   {
      return m_rowSize;
   }
   void addMatrix(int row, int col, float value)
   {
      matrix[row][col] = value;
   }
   float getMatrix(int row, int col)
   {
      return matrix[row][col];
   }
   void pivot(int col, float* b)
   {
      int row_max = col;
      for (int i = col + 1; i < m_colSize; ++i)
      {
         if (abs(matrix[i][col]) > abs(matrix[row_max][col]))
         {
            row_max = i;
         }
      }
      float aux;
      float baux;
      for (int i = 0; i < m_rowSize; ++i)
      {
         aux = matrix[row_max][i];
         matrix[row_max][i] = matrix[col][i];
         matrix[col][i] = aux;
         baux = b[row_max];
         b[row_max] = b[col];
         b[col] = baux;
      }
   }
   void escalonarGauss(Matrix *L, Matrix *U, float* b)
   {
      Matrix Laux(getSize());
      Matrix Uaux(getSize());
      for (int i = 0; i < getSize(); i++){
        for (int j = 0; j < getSize(); j++){
          Laux.addMatrix(i, j, 0);
          Uaux.addMatrix(i, j, getMatrix(i,j));
          if (i == j){
            Laux.addMatrix(i, j, 1);
          }
        }
      }
      for (int k = 0; k < m_rowSize; ++k)
      {
         Uaux.pivot(k,  b);
         for (int i = k + 1; i < m_rowSize; ++i)
         {
            float m = Uaux.getMatrix(i, k) / Uaux.getMatrix(k, k);
            Laux.addMatrix(i, k, m);
            for (int j = k; j < m_rowSize; ++j)
            {
               Uaux.addMatrix(i, j, Uaux.getMatrix(i, j)-(m*Uaux.getMatrix(k, j)));
            }
         }
      }
      *L = Laux;
      *U = Uaux;
   }
   int determinante()
   { // Recebe uma matriz triangular
      int det = 1;
      for (int i = 0; i < m_rowSize; i++)
      {
         det = det * matrix[i][i];
      }
      return det;
   }
};

class LUNormal {
    public:
        void solveLinearSystem(Matrix A, float* b) {
          Matrix L(A.getSize());
          Matrix U(A.getSize());
          A.escalonarGauss(&L, &U, b);
          float y[A.getSize()];
          float d[A.getSize()];
          for (int i = 0; i < A.getSize(); i++){ // calculando o vetor y
            y[i] = b[i];
            for (int j = i-1; j >= 0; j--){
              y[i] = y[i] - (y[j]*L.getMatrix(i, j));
            }
            y[i] = y[i]/L.getMatrix(i, i);
          }
          for (int i = A.getSize()-1; i >= 0; i--){ // calculando o vetor d
            d[i] = y[i];
            for (int j = A.getSize(); j > i; j--){
              d[i] = d[i] - (d[j]*U.getMatrix(i, j));
            }
            d[i] = d[i]/U.getMatrix(i, i);
          }
          for (int i = 0; i < A.getSize(); i++){
            std::cout << d[i] << endl;
          }
        }
};

/*class LUDescrito {
  public:
    void solveLinearSystem(Matrix A, float* b){
      Matrix L(A.getSize());
      Matrix U(A.getSize());
      A.escalonarGauss(&L, &U, b);
      Matrix
    }
}*/


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
    LUNormal LU;
    LU.solveLinearSystem(A, f);
    return 0;
}
