#include <iostream>
#include <algorithm>

#include "matrix.h"

using namespace std;

void Matrix::displayMatrixPivots(){

    // New temporary symbolic matrix to display location of pivots.
    Matrix* retSymbolizedMatrix = new Matrix(n, m);

    // "Create" vector of pivot locations.
    vector<matrixCoord> pivotLocs = locateMatrixPivots();

    // Temporary MatrixCoord object to compare pivot locations with current location.
    matrixCoord currPivotLoc;

    // Visit each row.
    for(int r = 0; r < n; r++){

        // Go thru each row.
        for(int c = 0; c < m; c++){

            // Update MatrixCoord object with current location.
            currPivotLoc.row = r;
            currPivotLoc.col = c;

            // Attempt to find current location in vector of pivots.
                // If found, insert asterisk ('*') into symbolic matrix.
            if(find(pivotLocs.begin(), pivotLocs.end(), currPivotLoc) != pivotLocs.end()){

                retSymbolizedMatrix->modifyMatrix(r, c, '*');
                
                // If not found, insert dash ('*') into symbolic matrix.
            } else {

                retSymbolizedMatrix->modifyMatrix(r, c, '-');

            }   

        }

    }

    // Print original (now reduced) matrix.
    printCLI();

    // Print temporary symbolic matrix.
    retSymbolizedMatrix->printSymbolizedMatrixCLI();

    // Free memory - delete temporary symbolic matrix.
    delete retSymbolizedMatrix;

}