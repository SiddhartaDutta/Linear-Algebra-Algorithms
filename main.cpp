#include <iostream>

#include "matrix.h"
using namespace std;

int main(){

    int n, m;

    cout << "Rows: ";
    cin >> n;
    cout << "Colms: ";
    cin >> m;

    Matrix test = Matrix(n, m, true, true);
    test.printCLI();
    test.solutionsOfLinearSystems();
    test.printCLI();

}
