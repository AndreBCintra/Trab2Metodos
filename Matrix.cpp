#include <iostream>
#include <vector>

using namespace std;

class Matrix {
   private:
      unsigned m_rowSize;
      unsigned m_colSize;
      float** matrix;
      void construct(unsigned rowSize,
      unsigned colSize) {
         m_rowSize = rowSize;
         m_colSize = colSize;
         matrix = new float*[m_rowSize];
         for (int i = 0; i < m_rowSize; ++i)
            matrix[i] = new float[m_colSize];
      }
      void escolhe_pivo(int k, int *pivo, int *r) {
         pv ← abs(A[k][k]);
         r ← k;
         for(int i=k+1;i<=m_rowSize-1;i++){
            if(abs(A[i][k]) > pv){
               pv ← abs(A[i][k]);
               r ← i;
            }
         }
      }
   public:
      Matrix escalonarGauss() {
         for (int k = 1; k <= m_rowSize - 1; ++k ) {
            int *pivo, *r;
            escolhe_pivo(k, &pivo, &r);
            if (pivo == 0) {
               throw "A matriz e singular";
            }
            if (r != k) {
               permuta(pivo, k, r);
            }
            for (int i = k + 1; i <= m_rowSize; ++i) {
               int m = matrix[i][k]/matrix[k][k];
               matrix[i][k] = m;
               for (int j = k+1; j <= m_rowSize; ++j) {
                  matrix[i][j] = matrix[i][j] - m*matrix[k][j];
               }
            }
         }
      }
      Matrix determinante() { // Recebe uma matriz triangular
         int det = 1;
         for (int i = 0; i < m_rowSize) {
            det = det * matrix[i][i];
         }
         return det;
      }
      void deleteMatrix(void) {
         for (int i = 0; i < m_rowSize; ++i)
            delete [] matrix[i];
         delete [] matrix;
      }
};