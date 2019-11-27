#include "./Matrix.cpp"

class LUNormal {
    public:
        void solveLinearSystem(Matrix system) {
            int* subst_suscessivas_mod(int m_rowSize, float** matrix, float* b){
                float x[m_rowSize]=0, soma;
                for(int i=0; i<=m_rowSize-1; i++){
                    soma = 0;
                    for(int j=0; j<=i-1; j++){
                        soma = soma + matrix[i][j]*x[j];
                    }
                    x[i] = b[i] - soma;
                }
            }

            int* subst_retroativa(int m_rowSize, float** matrix, float* y){
                float x[m_rowSize] = y[m_rowSize]/matrix[m_rowSize][m_rowSize], soma; 
                for(i=m_rowSize-2; i<=0; i--){
                    soma = 0;
                    for(j=i+1; j=m_rowSize-1){
                        soma = soma + matrix[i][j]*x[j];
                    }
                x[i] = (y[i] - soma)/matrix[i][i];
                }
            }
        }
};
