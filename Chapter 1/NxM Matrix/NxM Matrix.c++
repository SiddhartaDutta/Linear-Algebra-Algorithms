#include <iostream>
#include <cmath>

using namespace std;

void rowReduceMatrix(float **matrixInput, int n, int m);

int main(){

    int n, m;

    cout << "Rows: ";
    cin >> n;
    cout << "Colms: ";
    cin >> m;

    // init matrix
    float **matrix = new float *[n];

    // create 2nd dim
    for(int i = 0; i < n; i++){
        matrix[i] = new float[m];
    }

    // request and store entries
    for(int x = 0; x < n; x++){

        for(int y = 0; y < m; y++){
            cout << "IN " << x << "," << y << " : ";
            cin >> matrix[x][y];
        }

    }

    rowReduceMatrix(matrix, n, m);

    // print matrix
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            cout << matrix[x][y] << "\t";
        }
        cout << endl;
    }

}

void rowReduceMatrix(float **matrixInput, int n, int m){

    int leadValCol = 0;

    // Determine pivot location
    for(int leadVal = 0; leadVal < n && leadVal < m; leadVal++){

        if(leadVal != 0){
            leadValCol += 1;
        }

        bool isZeroCol = true;
        int nonZeroRow;

        // remove extremely low values
        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                if(    (abs(fmod(matrixInput[x][y], 1)) < 0.0001) && (fmod(matrixInput[x][y], 1) != 0)    ){

                    matrixInput[x][y] -= fmod(matrixInput[x][y], 1);

                }
            }
        }

        // move 0-rows
        /*for(int x = 0; x < n; x++){

            bool isZero = true;

            for(int y = 0; y < m; y++){
                if(matrix[x][y] != 0)   isZero = false;
            }

            if(isZero){
                n--;

                // swap 0 row with last row
                for(int c = 0; c < m; c++){
                    float temp = matrix[x][c];
                    matrix[x][c] = matrix[n - 1][c];
                    matrix[n - 1][c] = temp;
                }
            }
        }*/

        // Ensure leadVal is not 0 - swap rows if needed
        if(!matrixInput[leadVal][leadValCol]){

            // find next non-zero
                // go down column looking for non-zero
            for(int col = leadValCol; col < m; col++){

                for(int row = leadVal + 1; row < n; row++){

                    // if non-zero row found, save row position, save finding, and force-end for loop
                    if(matrixInput[row][col]){
                        nonZeroRow = row;
                        isZeroCol = false;
                        row = n;
                        col = m;
                    }

                }

                // if non-zero pos found, save col position, save finding, and force-end for loop
                 if(matrixInput[leadVal][col]){
                     isZeroCol = false;
                     col = m;
                 }

                // if column is zero, add 1 to pivot column
                if(isZeroCol && col < m - 1)   leadValCol++;

            }

            // non-zero row found, swap rows
            if(!isZeroCol && !(leadVal == n - 1)){

                for(int col = 0; col < m; col++){

                    float temp = matrixInput[leadVal][col];
                    matrixInput[leadVal][col] = matrixInput[nonZeroRow][col];
                    matrixInput[nonZeroRow][col] = temp;

                }

            } 

        }

        // Divisor for pivot - outside to prevent constant calculation
        float divisor = matrixInput[leadVal][leadValCol];

        // Set pivot to = 1
        for(int col = 0; col < m; col++){
            if(divisor != 0){
                matrixInput[leadVal][col] /= divisor;
            }
        }

        divisor = matrixInput[leadVal][leadValCol];

        // Increment over each row
        for(int row = 0; row < n; row++){

            // Constant of row who's being amended (if pivot [0][0], value of [1][0])
            float multiplier = -matrixInput[row][leadValCol];

            // Increment across row (over columns of row)
            for(int column = 0; column < m; column++){

                if(row == leadVal){     // if row of current pivot, divide to reduce pivot to 1
                    if(divisor != 0){            // prevents division by 0
                        matrixInput[row][column] /= divisor;
                    }
                } else {                // else, multiply by row factor and add to reduce (makes pivot column 0)
                    matrixInput[row][column] += matrixInput[leadVal][column] * multiplier;
                }

                //cout << row << ", " << column << ", " << matrix[row][column] << endl;

            }

        }

    }

    // print matrix
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            cout << matrixInput[x][y] << "\t";
        }
        cout << endl;
    }

}