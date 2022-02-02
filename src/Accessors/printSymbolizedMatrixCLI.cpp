#include "matrix.h"

void Matrix::printSymbolizedMatrixCLI(){

    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            cout << char(matrix[x][y]) << "\t";
        }
        cout << endl;
    }
    
}