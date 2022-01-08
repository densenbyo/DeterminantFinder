//
// Created by Mukan Atazhanov on 07-Jan-22.
//

#ifndef SEMESTRALKA_MATRIX_HPP
#define SEMESTRALKA_MATRIX_HPP

#include <vector>

using namespace std;

class matrix {
    private:
        unsigned int rows;
        unsigned int columns;
        void swapRows(const unsigned& row1,const unsigned& row2);

    public:
        //array of matrix value
        vector<vector<double>> value;

        matrix(unsigned _rows, unsigned _columns, const double& _init);

        //accessibility to elements
        double& operator()(const unsigned& row, const unsigned& col);
        const double& operator()(const unsigned& row, const unsigned& col) const;

        static long double solveDeterminant(matrix& mat);
        static void printMatrix(matrix& mat);

        // GETTERS
        unsigned int get_rows() const;
        unsigned int get_columns() const;

        // set input data to array value
        void setValue(const unsigned& row, const unsigned& column, double data);
};


#endif //SEMESTRALKA_MATRIX_HPP
