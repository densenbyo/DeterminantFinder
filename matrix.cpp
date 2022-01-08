//
// Created by Mukan Atazhanov on 07-Jan-22.
//

#include "matrix.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

//finds determinant
long double matrix::solveDeterminant(matrix& mat) {
    double detResult = 1;
    for(int i = 0; i < mat.get_rows(); ++i){
        double pivot = mat(i, i);
        int pivotRow = i;

        for(int row = i + 1; row < mat.get_rows(); ++row){
            if((abs(mat(row, i)) < abs(pivot)) && abs(mat(row, i)) != 0){
                pivot = mat(row, i);
                pivotRow = row;
            } else if(abs(pivot) == 0 && (abs(mat(row,i)) > abs(pivot))){
                pivot = mat(row, i);
                pivotRow = row;
            }
        }
        if(pivot == 0.0){
            return 0.0;
        }
        if(pivotRow != i){
            mat.swapRows(i, pivotRow);
            detResult *= -1.0;
        }
        detResult *= pivot;

        for(int row = i + 1; row < mat.get_rows(); ++row){
            for(int column = i + 1; column < mat.get_rows(); ++column){
                mat(row, column) -= mat(row, i) * mat(i, column) / pivot;
            }
        }
    }
    return detResult;
}

//prints matrix
void matrix::printMatrix(matrix& mat) {
    cout << setprecision(2) << fixed;
    for(size_t i = 0; i < mat.get_rows(); i++){
        cout << " | ";
        for(size_t j = 0; j < mat.get_columns(); j++){
            cout << mat(i, j) << " | ";
        }
        cout << endl;
    }
}

//constructor
matrix::matrix(unsigned _rows, unsigned _columns, const double& _init) {
    value.resize(_rows);
    for(auto & i : value){
        i.resize(_columns, _init);
    }
    rows = _rows;
    columns = _columns;
}

//go through all rows
void matrix::swapRows(const unsigned int &row1, const unsigned int &row2) {
    this->value[row1].swap(this->value[row2]);
}

//accessibility to elements
double& matrix::operator()(const unsigned& row, const unsigned& col) {
    return this->value[row][col];
}
const double& matrix::operator()(const unsigned& row, const unsigned& col) const {
    return this->value[row][col];
}

//getters
unsigned int matrix::get_rows() const {
    return this->rows;
}
unsigned int matrix::get_columns() const {
    return this->columns;
}

// set input values to array value
void matrix::setValue(const unsigned& row, const unsigned& column, double data) {
    this -> value[row][column] = data;
}




