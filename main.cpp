#include <iostream>

#include "matrix.h"
using namespace std;

int main(){

    while(1){

        // Print UI
        cout << "Linear Algebra Calculator\n";
        cout << "Create Matrix\n";
        cout << "Row Reduce Matrix\n";
        cout << "Find Solutions of a Linear System\n";
        cout << "Print Matrix\n";
        cout << "Display Matrix Pivots\n";

        string inputStr;
        int inputInt;

        try{

            cin >> inputStr;
            inputInt = stoi(inputStr);
                
            switch(inputInt){

                case 1:
                    break;

                default:
                    return;

            }

        } catch(...){
            cout << "Error: Invalid Input\n";
        }


    }

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
