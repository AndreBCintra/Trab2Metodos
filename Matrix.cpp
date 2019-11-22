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
   public:
      Matrix determinant();
      void deleteMatrix(void) {
         for (int i = 0; i < m_rowSize; ++i)
            delete [] matrix[i];
         delete [] matrix;
      }
};