#include <iostream>

#include "matrix.h"
using namespace std;

int main(){

    int n, m;

    cout << "Rows: ";
    cin >> n;
    cout << "Colms: ";
    cin >> m;

    Matrix test = Matrix(n, m, true);
    test.printCLI();
    test.solutionsOfLinearSystems();
    //test.printCLI();
    //cout << !0;

    // print matrix
    // for(int x = 0; x < n; x++){
    //     for(int y = 0; y < m; y++){
    //         cout << test[x][y] << "\t";
    //     }
    //     cout << endl;
    // }

}
