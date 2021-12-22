#include <iostream>
#include <cmath>

using namespace std;

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

    //multRow(matrix[0], 2);

    for(int pos = 0; pos < n && pos < m; pos++){

        // check if val in pos = 0
        if(!matrix[pos][pos]){
            // find val to swap rows (if exists)
        }

        // if not, conv to 1, adjust row and add to others
        float tempPivotVal = matrix[pos][pos];

        // Iterate thru row to divide row entries by pivot - sets row in terms of pivot = 1
        for(int x = 0; x < m; x++){
            matrix[pos][x] /= tempPivotVal; // divide entry by pivot
        }


        /* Tests going down */
        // Adjust all other rows to isolate pivot
        if((pos + 1) < n){

            // Increment over each following row
            for(int x = pos; x < (n - 1); x++){

                // following row's negative "pivot to be removed" value
                float tempFactor = -matrix[pos + 1][pos];

                // Increment across row (over columns of row)
                for(int y = 0; y < m; y++){

                    // take following row, multiply pivot row columns with pivot to be removed and add to following row
                    matrix[pos + 1][y] += matrix[pos][y] * tempFactor;

                }

            }

        }

    }

    // determine matrix
        // [0][0] & [1][0]
            // make [0][0] = 1
    // matrix[0][0] /= matrix[0][0];
    // matrix[0][1] /= matrix[0][0];
    //         // [1][0] = 0
    // float temp = -(matrix[0][1] * matrix[1][0]);
    // matrix[1][0] = 0;
    // matrix[1][1] += temp;

    // if(matrix[1][1]){
    //     matrix[1][1] = 1;
    //     float temp = -(matrix[1][1] * matrix[0][1]);
    //     matrix[0][1] += temp;
    // }

    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            cout << matrix[x][y] << "\t";
        }
        cout << endl;
    }




}