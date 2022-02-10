#include <cmath>

#include "matrix.h"

using namespace std;

void Matrix::rowReduceMatrix(){

    int leadValCol = 0;

    // Determine pivot location
    for(int leadVal = 0; leadVal < n && leadValCol < adjustedM; leadVal++){

        if(leadVal != 0){
            leadValCol += 1;
        }

        bool isZeroCol = true;
        int nonZeroRow;

        // remove extremely low values
        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                if(    (abs(fmod(matrix[x][y], 1)) < 0.0001) && (fmod(matrix[x][y], 1) != 0)    ){

                    matrix[x][y] -= fmod(matrix[x][y], 1);

                }
            }
        }

        // Ensure leadVal is not 0 - swap rows if needed
        if(!matrix[leadVal][leadValCol]){

            // find next non-zero
                // go down column looking for non-zero
            for(int col = leadValCol; col < m; col++){

                for(int row = leadVal + 1; row < n; row++){

                    // if non-zero row found, save row position, save finding, and force-end for loop
                    if(matrix[row][col]){
                        nonZeroRow = row;
                        isZeroCol = false;
                        row = n;
                        col = m;
                    }

                }

                // if non-zero pos found, save col position, save finding, and force-end for loop
                 if(matrix[leadVal][col]){
                     isZeroCol = false;
                     col = m;
                 }

                // if column is zero, add 1 to pivot column
                if(isZeroCol && col < m - 1)   leadValCol++;

            }

            // non-zero row found, swap rows
            if(!isZeroCol && !(leadVal == n - 1)){

                for(int col = 0; col < m; col++){

                    float temp = matrix[leadVal][col];
                    matrix[leadVal][col] = matrix[nonZeroRow][col];
                    matrix[nonZeroRow][col] = temp;

                }

            } 

        }

        // Divisor for pivot - outside to prevent constant calculation
        float divisor = matrix[leadVal][leadValCol];

        // Set pivot to = 1 (also ensure augment is protected)
        for(int col = 0; col < m && leadValCol < adjustedM; col++){
     
            if(divisor != 0){
                matrix[leadVal][col] /= divisor;
            }
        }

        divisor = matrix[leadVal][leadValCol];

        // Increment over each row
        for(int row = 0; row < n; row++){

            // Constant of row who's being amended (if pivot [0][0], value of [1][0])
            float multiplier = -matrix[row][leadValCol];

            // Increment across row (over columns of row) (also ensure augment is protected)
            for(int column = 0; column < m && leadValCol < adjustedM; column++){

                if(row == leadVal){     // if row of current pivot, divide to reduce pivot to 1
                    if(divisor != 0){            // prevents division by 0
                        matrix[row][column] /= divisor;
                    }
                } else {                // else, multiply by row factor and add to reduce (makes pivot column 0)
                    matrix[row][column] += matrix[leadVal][column] * multiplier;
                }

                //cout << row << ", " << column << ", " << matrix[row][column] << endl;

            }

        }

    }

}