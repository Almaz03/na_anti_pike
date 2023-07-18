#include "Matrix.h"
#include "TVector.h"
#include <iostream>

int main() {
    std::cout << "\nVECTOR\n\n";
    int n = 3;
    int data1[] = {1, 2, 3};
    int data2[] = {4, 5, 3};

    TVector<int> vec1(n, data1);
    TVector<int> vec2(n, data2);

    TVector<int> sum = vec1 + vec2;
    std::cout << "Sum: ";
    sum.print();

    TVector<int> cross_product = vec1 ^ vec2;
    std::cout << "Vect: ";
    cross_product.print();

    int dot = vec1 * vec2;
    std::cout << "Smesh: " << dot << std::endl;

    TVector<int> scaled = vec1 * dot;
    std::cout << "Scal: ";
    scaled.print();

    std::cout << "\nMATRIX\n\n";
    double **values;
    int rows = 3, cols = 3;
    values = new double *[rows];


    for (int i = 0; i < rows; i++) values[i] = new double[cols];

    int c = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            values[i][j] = c + rand() % 10;
            c++;
        }
    }

    Matrix<double> matrix(rows, cols, values);

    Matrix<double> transposeMatrix = matrix.transpose();
    std::cout << "Transponnsed:" << std::endl;
   // transposeMatrix.print();

    double **values2;
    int rows2 = 3, cols2 = 3;
    values2 = new double *[rows2];
    for (int i = 0; i < rows2; i++) values2[i] = new double[cols2];
    c = 1;
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            values2[i][j] = (c++) * 2;
        }
    }

    Matrix<double> matrix2(rows2, cols2, values2);
    Matrix<double> sumMatrix = matrix + matrix2;
    std::cout << "Sum:" << std::endl;
   // sumMatrix.print();

    Matrix<double> multiplyMatrix = matrix * transposeMatrix;
    std::cout << "Multi:" << std::endl;
   // multiplyMatrix.print();

    Matrix<double> scalarMultiplyMatrix = matrix * 2;
    std::cout << "Scalar:" << std::endl;
   // scalarMultiplyMatrix.print();

    std::cout << "Inverse:" << std::endl;
    Matrix<double> inMatrix = matrix.inverse();
    //inMatrix.print();

    double **value4;
    value4 = new double *[3];
    for (int i = 0; i < 3; ++i) {
        value4[i] = new double[3];
    }

    value4[0][0] = 1. / 2.;
    value4[0][1] = (pow(3., 1. / 2.) / 2.);
    value4[0][2] = 0;

    value4[1][0] = -(pow(3., 1. / 2.) / 2.);
    value4[1][1] = 1. / 2.;
    value4[1][2] = 0;

    value4[2][0] = 0;
    value4[2][1] = 0;
    value4[2][2] = 1.;


//    value4[0][0] = 1./ 2;
//    value4[0][1] = 3;
//    value4[0][2] = 0.;
//
//    value4[1][0] = -3./2;
//    value4[1][1] = 1. / 2;
//    value4[1][2] = 0.;
//
//    value4[2][0] = 0.;
//    value4[2][1] = 0.;
//    value4[2][2] = 1.;

    std::cout << "4th Array:";
    Matrix<double> matrix4(3, 3, value4);
//    matrix4.print();
    std::cout<<std::endl;
    matrix4 = matrix4.inverse();

    matrix4.print();
    double k = 0 *-1.;
    std::cout<<"THIS "<<k<<std::endl;


    for (int i = 0; i < 3; i++) {
        delete[] value4[i];
        delete[] values[i];
        delete[] values2[i];
    }
    delete[] value4;
    delete[] values2;
    delete[] values;


    return 0;
}
