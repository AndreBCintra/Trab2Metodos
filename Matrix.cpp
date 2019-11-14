#include <iostream>
#include <vector>

using namespace std;

class Matrix {
   private:
      unsigned m_rowSize;
      unsigned m_colSize;
      vector<vector<int> > m_matrix;
   public:
      Matrix determinant();
};
