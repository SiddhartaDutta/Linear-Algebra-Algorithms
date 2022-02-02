#include "matrix.h"

using namespace std;

void Matrix::modifyMatrix(int row, int cols, float value){
    matrix[row][cols] = value;
}