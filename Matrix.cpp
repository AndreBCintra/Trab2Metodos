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
      Matrix(int rowSize, int colSize) {
         construct(m_rowSize, colSize);
      }
      Matrix determinant();
      void deleteMatrix(void) {
         for (int i = 0; i < m_rowSize; ++i)
            delete [] matrix[i];
         delete [] matrix;
      }
      int getSize(){
         return m_rowSize;
      }
      void addMatrix(int row, int col, float value){
         matrix[row][col] = value;
      }
      float getMatrix(int row, int col){
         return matrix[row][col];
      }
      void opRow(int row, int baseRow, float value){
         for (int i = 0; i < m_rowSize; ++i){
            matrix[row][i] = matrix[row][i] - (matrix[baseRow][i]*value);
         }
      }
      void pivot(int col){
         int row_max = col;
         for (int i = col + 1; i < m_colSize; ++i){
            if (abs(matrix[i][col]) > abs(matrix[row_max][col])){
               row_max = i;
            }
         }
         float aux;
         for (int i = 0; i < m_rowSize; ++i){
            aux = matrix[row_max][i];
            matrix[row_max][i] = matrix[col][i];
            matrix[col][i] = aux;
         }
      }
};
