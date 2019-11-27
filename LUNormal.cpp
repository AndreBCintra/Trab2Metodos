#include "./Matrix.cpp"
class LUNormal {
    public:
        void solveLinearSystem(Matrix system) {
                 
            int* lu_pivotacao_parcial(int m_rowSize, Matrix A, float* b){
            	int p[m_rowSize], b[m_rowSize], blin[m_rowSize], x[m_rowSize], y[m_rowSize], r, pivo, i;
	      	 	for(int i=0; i<=m_rowSize-2;){
	      	 		p[i] = i;
			    }
            	A.escalonarGauss(p, pivo, r);
            	for(i=0; i<=m_rowSize-1;)
					r = p[i];
					blin[i] = b[r];
			}
			y = subst_sucessivas_mod(m_rowSize, blin);
			x = substituicoes_retroativas(m_rowSize, y);
            	
			
        }
};
