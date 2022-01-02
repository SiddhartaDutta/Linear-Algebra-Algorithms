#include <iostream>
using namespace std;

#include <matrix.h>

int main(){

    int n, m;

    cout << "Rows: ";
    cin >> n;
    cout << "Colms: ";
    cin >> m;

    Matrix test = Matrix(n, m);
    
    test.rowReduceMatrix(test, n, m);

    // print matrix
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            cout << matrix[x][y] << "\t";
        }
        cout << endl;
    }

}
