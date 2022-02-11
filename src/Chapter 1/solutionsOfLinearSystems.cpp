#include "matrix.h"

#include <queue>

/**
 * Displays solutions of a linear system.
 **/
void Matrix::solutionsOfLinearSystems(){
    
    // "Create" vector of pivot locations.
    vector<matrixCoord> pivotLocs = locateMatrixPivots();

    // Create vector of equation strings
    queue<string> outputEquations;

    // Queue of possible/usable ascii values
    queue<int> asciiVals;

    for(int n = 97; n < 123; n++){
        asciiVals.push(n);
    }

    for(int n = 65; n < 91; n++){
        asciiVals.push(n);
    }

    // Increment vector holding pivot
    for(int n = 0; n < pivotLocs.size(); n++){

        // Template string
        string equation = "";

        // Queue copy
        queue<int> asciiValsCopy = asciiVals;

        // Increment thru the row
        for(int col = pivotLocs.at(n).col; col < m; col++){

            if(matrix[n][col] != 0){

                // Add to string
                if(col < adjustedM){
                    equation += to_string(matrix[n][col]) + char(asciiValsCopy.front()) + " ";
                } else {
                    equation += "= " + to_string(matrix[n][col]) + "\n"; 
                }

            }

            asciiValsCopy.pop();

        }

        // Push string into equations vector
        outputEquations.push(equation);

    }

    // Output formatted equations
    while(outputEquations.size()){
        cout << outputEquations.front();
        outputEquations.pop();
    }

    // Output number of solutions
    

}

/* ASCII Values

a-z
97-122
A-Z
65-90

*/