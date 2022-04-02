#include "matrix.h"

#include <cmath>
#include <queue>
#include <list>
#include <algorithm>

/**
 * Displays solutions of a linear system.
 **/
void Matrix::solutionsOfLinearSystems(){

    if(!augmented){
        cout << "Current matrix is not augmented. Operation failed.\n";
        return;
    }
    
    // "Create" vector of pivot locations.
    vector<matrixCoord> pivotLocs = locateMatrixPivots();

    // Create vector of equation strings
    queue<string> outputEquations;

    // Queue of possible/usable ascii values
    queue<int> asciiVals;

    // Queue of free variables in the system of equations
    list<char> freeVars;

    // Queue of dependent variables in the system of equations
    list<char> dependentVars;

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

        // Temporary MatrixCoord object to compare pivot locations with current location.
        matrixCoord currPivotLoc = pivotLocs.at(n);

        // Adjust asciiValsCopy to ensure start matches start of pivot
        for(int col = 0; col < currPivotLoc.col; col++){
            asciiValsCopy.pop();
        } 

        // Increment thru the row
        for(int col = currPivotLoc.col; col < m; col++){

            if(matrix[n][col] != 0 || col == adjustedM){

                // Add to string
                if(col < adjustedM){    // While column is not final augment

                    if(col != currPivotLoc.col){    // If value is not the pivot value, found free variable -> push into "freeVars" list
                        equation += "+ ";
                        
                        if( !(find(freeVars.begin(), freeVars.end(), asciiValsCopy.front()) != freeVars.end()) ){
                            freeVars.push_back(asciiValsCopy.front());
                        }
                    } else {                        // If value IS the pivot value, push into "dependentVars" list
                        dependentVars.push_back(asciiValsCopy.front());
                    }

                    equation += "(" + to_string(matrix[n][col]) + ")" + char(asciiValsCopy.front()) + " ";

                } else {                // Add final augment value to equation
                    cout << "size: " << outputEquations.size() - 1 << " | n: " << n << endl;
                    equation += "= " + to_string(matrix[n][col]) + "\n"; 
                }

            }

            asciiValsCopy.pop();

        }

        // Push string into equations vector
        outputEquations.push(equation);

    }

    cout << "size: " << outputEquations.size() << " | adjusted: " << adjustedM << endl;

    // Output number of solutions
    cout << "Possible number of solutions: ";

    if(outputEquations.size() != adjustedM){

        if(matrix[outputEquations.size()][m - 1]){
            cout << "None (The system is inconsistent [0 != " << matrix[outputEquations.size()][m - 1] << "]). The system is inconsistent.\n";
        } else {
            cout << "Infinite (Free variables exist). The system is consistent.\n";
        }

    } else {
        cout << "One (Each variable is dependent). The system is consistent.\n";
    }

    // Output variable classifications
    cout << "Dependent Variables: ";
    if(!dependentVars.size()){
        cout << "None";
    } else {
        while(dependentVars.size()){
            cout << dependentVars.front();
            dependentVars.pop_front();
            if(dependentVars.size()){ cout << ", "; }
        }
    }

    cout << endl;

    cout << "Free Variables: ";
    if(!freeVars.size()){
        cout << "None";
    } else {
        while(freeVars.size()){
            cout << freeVars.front();
            freeVars.pop_front();
            if(freeVars.size()){ cout << ", "; }
        }   
    }

    cout << endl;

    // Output formatted equations
    while(outputEquations.size()){
        cout << outputEquations.front();
        outputEquations.pop();
    }

}

/* ASCII Values

a-z
97-122
A-Z
65-90

*/