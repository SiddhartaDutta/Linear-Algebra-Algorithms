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

    for(int i = 0; i < n; i++){
        matrix[i] = new float[m];
    }

    // 




}