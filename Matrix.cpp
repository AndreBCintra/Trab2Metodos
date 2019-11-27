	#include <iostream>
	#include <vector>
	#include <cmath>
	
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
	         *pivo = abs(matrix[k][k]);
	         *r = k;
	         for(int i=k+1;i<=m_rowSize-1;i++){
	            if(abs(matrix[i][k]) > *pivo){
	               *pivo = abs(matrix[i][k]);
	               *r = i;
	            }
	         }
	      }
	      void permuta(int* p, int k, int r){
	         int aux = p[k];
	         p[k] = p[r];
	         p[r] = aux;
	         for(int j=0; j<=m_rowSize-1;j++){
	            aux = matrix[k][j];
	            matrix[k][j] = matrix[r][j];
	            matrix[r][j] = aux;
	         }
	      }
	      int* subst_suscessivas_mod(int m_rowSize, float* b){
	        float x[m_rowSize]=0, soma;
	                for(int i=0; i<=m_rowSize-1; i++){
	                    soma = 0;
	                    for(int j=0; j<=i-1; j++){
	                        soma = soma + matrix[i][j]*x[j];
	                    }
	                    x[i] = b[i] - soma;
	                }
	            }
	
	      int* subst_retroativa(int m_rowSize, float* y){
	                float x[m_rowSize] = y[m_rowSize]/matrix[m_rowSize][m_rowSize], soma; 
	                for(i=m_rowSize-2; i<=0; i--){
	                    soma = 0;
	                    for(j=i+1; j=m_rowSize-1){
	                        soma = soma + matrix[i][j]*x[j];
	                    }
	                x[i] = (y[i] - soma)/matrix[i][i];
	                }
	            }
	       
	      
	   public:
	      Matrix escalonarGauss(int* p, pivo, r) {
	      	 for (int k = 0; k <= m_rowSize - 2; ++k ) {
	            escolhe_pivo(k, &pivo, &r);
	            if (pivo == 0) {
	               throw "A matriz e singular";
	            }
	            if (r != k) {
	               permuta(p, k, r);
	            }
	            for (int i = k + 1; i <= m_rowSize-1; ++i) {
	               int m = matrix[i][k]/matrix[k][k];
	               matrix[i][k] = m;
	               for (int j = k+1; j <= m_rowSize-1; ++j) {
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
