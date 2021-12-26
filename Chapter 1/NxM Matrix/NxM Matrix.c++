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

    // print matrix
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            cout << matrix[x][y] << "\t";
        }
        cout << endl;
    }

    //test swap
    // if(!matrix[0][0]){
        
    //     float m1[m];

    //     for(int col = 0; col < m; col++){

    //         m1[col] = matrix[0][col];
    //         matrix[0][col] = matrix[1][col];
    //         matrix[1][col] = m1[col];

    //     }

    // }

    //return 1;

    // Determine pivot location
    for(int leadVal = 0; leadVal < n && leadVal < m; leadVal++){

        // Ensure leadVal is not 0 - swap rows if needed
        if(!matrix[leadVal][leadVal]){
            
            float *m1 = new float[m];

            for(int col = 0; col < m-1; col++){

                m1[col] = matrix[leadVal][col];
                matrix[leadVal][col] = matrix[leadVal + 1][col];
                matrix[leadVal + 1][col] = m1[col];

            }

        }

        // Divisor for pivot - outside to prevent constant calculation
        float divisor = matrix[leadVal][leadVal];

        for(int col = 0; col < m; col++){
            if(divisor != 0){
                matrix[leadVal][col] /= divisor;
            }
            //cout << matrix[leadVal][col] << endl;
        }

        divisor = matrix[leadVal][leadVal];

        // Increment over each row
        for(int row = 0; row < n; row++){

            // Constant of row who's being amended (if pivot [0][0], value of [1][0])
            float multiplier = -matrix[row][leadVal];

            // Increment across row (over columns of row)
            for(int column = 0; column < m; column++){

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

    // print matrix
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            cout << matrix[x][y] << "\t";
        }
        cout << endl;
    }

}