#include <iostream>

#include "matrix.h"

using namespace std;

vector<Matrix::matrixCoord> Matrix::locateMatrixPivots(){

    // Initialize return vector.
    vector<matrixCoord> returnVector;

    // Row-reduce matrix to ensure pivots are accurately found - IRREVERSIBLE PROCESS!
    rowReduceMatrix();

    // Find pivots (and thus dependent vars).
    // Visit each row.
    for(int r = 0; r < n; r++){

        // Go thru each row looking for non-zero values (by checking each column).
        for(int c = 0; c < m; c++){

            // If non-zero value found, look thru all other rows same column for zeros.
            if(matrix[r][c] != 0){

                bool isPivot = true;

                // Re-search all rows (column to be checked already given from prev for loop).
                for(int r2 = 0; r2 < n; r2++){

                    // Ensure currRow != row potential pivot found in.
                    // Given case 1, then determine if not 0.
                    // If not 0, set [isPivot] to FALSE.
                    if(r2 != r && matrix[r2][c]){
                        isPivot = false;
                    }

                }

                // If location being checked is a pivot, save pivot location with
                // struct into return vector.
                if(isPivot){
                    matrixCoord pivotLoc;
                    pivotLoc.row = r;
                    pivotLoc.col = c;
                    returnVector.push_back(pivotLoc);
                }

            }

        }

    }

    // Print original (now reduced) matrix.
    printCLI();

    // Return vector.
    return returnVector;
}