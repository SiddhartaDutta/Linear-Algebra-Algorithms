#include "matrix.h"

void Matrix::printCLI(){

    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            cout << matrix[x][y] << "\t";
        }
        cout << endl;
    }
    
}