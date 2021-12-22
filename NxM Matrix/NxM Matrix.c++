#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int n, m;

    cout << "Rows: ";
    cin >> n;
    cout << endl << "Colms: ";
    cin >> m;

    // init matrix
    float **matrix = new float *[n];

    // create 2nd dim
    for(int i = 0; i < n; i++){
        matrix[i] = new float[m];
    }

    // request and store entries
    for(int x = 0; x < 2; x++){

        for(int y = 0; y < 2; y++){
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

        // Adjust all other rows to isolate pivot
        if((pos + 1) < n){

            // Increment over each following row
            for(int x = pos; x < (n - 1); x++){

                float tempAddend = -();

                // Increment across row (over columns of row)
                for(int y = 0; y < m; y++){

                    

                }

            }
        }

    }

    // determine matrix
        // [0][0] & [1][0]
            // make [0][0] = 1
    matrix[0][0] /= matrix[0][0];
    matrix[0][1] /= matrix[0][0];
            // [1][0] = 0
    float temp = -(matrix[0][1] * matrix[1][0]);
    matrix[1][0] = 0;
    matrix[1][1] += temp;

    if(matrix[1][1]){
        matrix[1][1] = 1;
        float temp = -(matrix[1][1] * matrix[0][1]);
        matrix[0][1] += temp;
    }


    cout << matrix[0][0] << "\t" << matrix [0][1] << endl << matrix[1][0] << "\t" << matrix [1][1] << endl;




}