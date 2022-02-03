#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
using namespace std;

class Matrix {

    private:

        struct matrixCoord{
            int row;
            int col;
        };

        float **matrix;
        int n;
        int m;

    public:

    /* CONSTRUCTORS */
    Matrix(int rows, int cols, bool fill){

        n = rows;

        m = cols;

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

    // Empty matrix constructor
    Matrix(int rows, int cols) : Matrix(rows, cols, false){}


    /* ACCESSORS */
    void printCLI();
    void printSymbolizedMatrixCLI();
    

    /* MUTATORS */

    // General Purpose Mutators
    void modifyMatrix(int row, int cols, float value);

    // "New" Mutators
    void rowReduceMatrix();
    vector<struct matrixCoord> locateMatrixPivots();
    void displayMatrixPivots();
    void solutionsOfLinearSystems();
};

#endif