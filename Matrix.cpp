#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Matrix
{
private:
   int m_rowSize;
   int m_colSize;
   float **matrix;
   void escolhe_pivo(int k, int *pivo, int *r)
   {
      *pivo = abs(matrix[k][k]);
      *r = k;
      for (int i = k + 1; i <= m_rowSize - 1; i++)
      {
         if (abs(matrix[i][k]) > *pivo)
         {
            *pivo = abs(matrix[i][k]);
            *r = i;
         }
      }
   }
   void permuta(int *p, int k, int r)
   {
      int aux = p[k];
      p[k] = p[r];
      p[r] = aux;
      for (int j = 0; j <= m_rowSize - 1; j++)
      {
         aux = matrix[k][j];
         matrix[k][j] = matrix[r][j];
         matrix[r][j] = aux;
      }
   }
   int *subst_suscessivas_mod(int m_rowSize, float *b)
   {
      float x[m_rowSize], soma;
      for (int i = 0; i <= m_rowSize - 1; i++)
      {
         soma = 0;
         for (int j = 0; j <= i - 1; j++)
         {
            soma = soma + matrix[i][j] * x[j];
         }
         x[i] = b[i] - soma;
      }
   }

   int *subst_retroativa(int m_rowSize, float *y)
   {
      float x[m_rowSize], soma;
      x[m_rowSize -1] = y[m_rowSize - 1] / matrix[m_rowSize - 1][m_rowSize - 1];
      for (int i = m_rowSize - 2; i <= 0; i--)
      {
         soma = 0;
         for (int j = i + 1; j = m_rowSize - 1; j++ )
         {
            soma = soma + matrix[i][j] * x[j];
         }
         x[i] = (y[i] - soma) / matrix[i][i];
      }
   }

public:
   Matrix(int rowSize,
                  int colSize)
   {
      m_rowSize = rowSize;
      m_colSize = colSize;
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
   void opRow(int row, int baseRow, float value)
   {
      for (int i = 0; i < m_rowSize; ++i)
      {
         matrix[row][i] = matrix[row][i] - (matrix[baseRow][i] * value);
      }
   }
   void pivot(int col)
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
      for (int i = 0; i < m_rowSize; ++i)
      {
         aux = matrix[row_max][i];
         matrix[row_max][i] = matrix[col][i];
         matrix[col][i] = aux;
      }
   }
   void escalonarGauss(int *p, int *pivo, int *r)
   {
      for (int k = 0; k <= m_rowSize - 2; ++k)
      {
         escolhe_pivo(k, pivo, r);
         if (pivo == 0)
         {
            throw "A matriz e singular";
         }
         if (*r != k)
         {
            permuta(p, k, *r);
         }
         for (int i = k + 1; i <= m_rowSize - 1; ++i)
         {
            int m = matrix[i][k] / matrix[k][k];
            matrix[i][k] = m;
            for (int j = k + 1; j <= m_rowSize - 1; ++j)
            {
               matrix[i][j] = matrix[i][j] - m * matrix[k][j];
            }
         }
      }
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
