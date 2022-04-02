#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Matrix {

    private:

        struct matrixCoord{
            int row;
            int col;

            bool operator==(const matrixCoord& mcCheck){
                if(this->row == mcCheck.row && this->col == mcCheck.col){
                    return true;
                }

                return false;
            }
        };

        float **matrix;
        bool augmented;
        int n;
        int m;
        int adjustedM;

    public:

    /* CONSTRUCTORS */
    Matrix(int rows, int cols, bool augmented, bool fill){

        n = rows;

        m = cols;

        this->augmented = augmented;

        if(augmented){
            adjustedM = cols - 1;
        } else {
            adjustedM = cols;
        }

        // Create 1st dimension of matrix
        matrix = new float *[rows];

        // Create 2nd dimension of matrix
        for(int i = 0; i < n; i++){
            matrix[i] = new float[cols];
        }

        // Fill matrix if requested
        if(fill){
            // request and store entries
            for(int x = 0; x < n; x++){

                for(int y = 0; y < m; y++){
                    cout << "IN " << x << "," << y << " : ";
                    cin >> matrix[x][y];
                }

            }
        }

    }

    // Non-augmented and filled constructor
    Matrix(int rows, int cols, bool fill) : Matrix(rows, cols,  false, fill){}

    // Empty matrix constructor
    Matrix(int rows, int cols) : Matrix(rows, cols, false, false){}


    /* ACCESSORS */
    void printCLI();
    void printSymbolizedMatrixCLI();
    

    /* MUTATORS */

    // General Purpose Mutators
    void modifyMatrix(int row, int cols, float value);

    // "New" Mutators
        // Row reduce given/"this" matrix.
    void rowReduceMatrix();
        // Return vector with pivot locations.
    vector<matrixCoord> locateMatrixPivots();
        // Display pivots using vector of locations.
    void displayMatrixPivots();
        // Display solutions of the linear system in algebraic form.
    void solutionsOfLinearSystems();
};

#endif