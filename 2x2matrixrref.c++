#include <iostream>
#include <cmath>

using namespace std;

//void multRow(float *[], float);

int main(){

    float matrix[2][2];
    //float matrixPTR = &matrix;

    // get inputs
    for(int x = 0; x < 2; x++){

        for(int y = 0; y < 2; y++){
            cout << "IN " << x << "," << y << " : ";
            cin >> matrix[x][y];
        }

    }

    //multRow(matrix[0], 2);

    // determine matrix
        // [0][0] & [1][0]
            // make [0][0] = 1
    matrix[0][0] /= matrix[0][0];
    matrix[0][1] /= matrix[0][0];
            // [1][0] = 0
    float temp = -(matrix[0][1] * matrix[1][0]);
    matrix[1][0] = 0;
    matrix[1][1] += temp; 


    cout << matrix[0][0] << "\t" << matrix [0][1] << endl << matrix[1][0] << "\t" << matrix [1][1] << endl;
    

}

/*
void multRow(float *matrixRow[][8], float factor){

    for(int i = 0; i < sizeof(*matrixRow)/sizeof(*matrixRow[0]); i++){

        *matrixRow[i] *= factor;

    }

    //return matrixRow;
}
*/

/*



___ ___ 
___ ___





*/