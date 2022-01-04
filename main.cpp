#include <iostream>

#include "../Math-Projs/include/matrix.h"
//#include "matrix.h"
using namespace std;

int main(){

    int n, m;

    cout << "Rows: ";
    cin >> n;
    cout << "Colms: ";
    cin >> m;

    Matrix test = Matrix(n, m);
    
    test.rowReduceMatrix(n, m);

    // print matrix
    // for(int x = 0; x < n; x++){
    //     for(int y = 0; y < m; y++){
    //         cout << test[x][y] << "\t";
    //     }
    //     cout << endl;
    // }

}
