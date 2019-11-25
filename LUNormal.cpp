#include "./Matrix.cpp"

class LUNormal {
    public:
        void solveLinearSystem(Matrix system, float f[]) {
        //  Retorna o vetor d de valores resultantes de resolver o sistema
            int size = system.getSize();
            float k;
            Matrix L(size, size);
            Matrix U(size, size);
            for (int i = 0; i < size; ++i){
                for (int j = 0; j < size; ++j){
                    U.addMatrix(i, j, system.getMatrix(i, j));
                    if (i==j){
                        L.addMatrix(i, j, 1);
                    }
                    else{
                        L.addMatrix(i, j, 0);
                    }
                }
            }
            for (int i = 0; i < size; ++i){
                L.pivot(i);
                for (int j = i+1; j < size; ++j){
                    k = L.getMatrix(j, i)/L.getMatrix(i, i);
                    U.opRow(j, i, k);
                    L.addMatrix(j, i, k);
                }
            }
            float y[size];
            float auxy = 0;
            for (int i = size-1; i >= 0; --i){
                for (int j = i+1; j < size; ++j){
                    auxy = auxy + (U.getMatrix(i, j) * y[j]);
                }
                y[i] = (f[i] - auxy) / U.getMatrix(i, i);
            }
            float d[size];
            float auxd = 0;
            for (int i = 0; i < size; ++i){
                for (int j = i-1; j > 0; --j){
                    auxd = auxd + (L.getMatrix(i, j) * d[j]);
                }
                d[i] = y[i] - auxd;
            }
            for (int i = 0; i < size; i++){
              std::cout << d[i] << endl;
            }
        }
};
