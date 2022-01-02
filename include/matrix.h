#include <iostream>
using namespace std;

class Matrix {

    private:
        float **matrix;
        int n;
        int m;

    public:

    /* CONSTRUCTORS */
    Matrix(int rows, int cols){

        n = rows;

        m = cols;

        // Create 1st dimension of matrix
        matrix = new float *[rows];

        // Create 2nd dimension of matrix
        for(int i = 0; i < n; i++){
            matrix[i] = new float[cols];
        }

        // request and store entries
        for(int x = 0; x < n; x++){

            for(int y = 0; y < m; y++){
                cout << "IN " << x << "," << y << " : ";
                cin >> matrix[x][y];
            }

        }

    }


    /* ACCESSORS */

    /* MUTATORS */

};