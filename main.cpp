#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <chrono>
#include <string>
#include <vector>
#include "matrix.hpp"

using namespace std;
namespace timer {
    auto now() {
        return std::chrono::high_resolution_clock::now();
    }

    template <typename TimePoint>
    long long to_ms(TimePoint tp) {
        return std::chrono::duration_cast<std::chrono::milliseconds>(tp).count();
    }
}

int main(int argc, char *argv[]) {
    bool printIt = false;
    bool solveIt = false;

    cout << endl;
    cout << "Matrix determinant finder by Gaussian elimination method \n"
            "ARGUMENTS: \n"
            "[1 to get info]\n"
            "[2 to start app]\n"
            "[3 to show current matrix]" << endl;
    cout << endl;

    int c;
    cout << "Input argument :\n" ;
    cin >> c;
    if (strcmp(argv[c], "--help") == 0) {
        cout << "Application solves only in Single thread\n"
                "That is why I do not recommend to solve big matrix (it will be really slow)\n"
                "First input: Size of matrix NxN (N has to be same)\n"
                "Second input: Values of matrix\n"
                "Argument list : \n"
                "1 to show help info \n "
                "2 starts finding determinant \n"
                "3 show prints current matrix";
        return 0;
    } else if (strcmp(argv[c], "run") == 0) {
        solveIt = true;
    } else if (strcmp(argv[c], "print") == 0 ) {
        printIt = true;
    } else {
        cout << "Wrong input!" << endl;
        return 0;
    }

    cout << "MATRIX CONFIG" << endl;
    cout << "Size of matrix NxN" << endl;
    int n = 0;
    int m = 1;
    scanf("%d %d", &n, &m);
    if (m != n) {
        cout << "NxN: N has to be same" << endl;
    }

    cout << "Input values of matrix" << endl;
    matrix matrix(n, m, 0);
    double temp;
    for (int i = 0; i < matrix.get_rows(); i++) {
        for (int j = 0; j < matrix.get_columns(); j++) {
            scanf("%le", &temp);
            matrix.setValue(i, j, temp);
        }
    }

    if (printIt) {
        matrix::printMatrix(matrix);
        return 0;
    }

    if (solveIt) {
        auto t1 = timer::now();
        long double res = matrix::solveDeterminant(matrix);
        auto t2 = timer::now();
        cout << "Determinant is " << res
             << "\n Time: " << timer::to_ms(t2 - t1) << "ms";
        return 0;
    }
}
