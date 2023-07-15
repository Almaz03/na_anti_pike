// Matrix.h

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cmath>
#include <iomanip>

template<typename T>
class Matrix {
public:
    Matrix(int rows, int cols, T **data);

    Matrix(int rows, int cols);

    ~Matrix();

    Matrix<T> transpose() const;

    Matrix<T> inverse() const;

    Matrix<T> operator+(const Matrix<T> &other) const;

    Matrix<T> operator*(const Matrix<T> &other) const;

    Matrix<T> operator*(T scalar) const;

    Matrix<T> &operator=(const Matrix<T> &other);

    void print();

protected:
    int rows;
    int cols;
    T **data;

    T determinant() const;

    Matrix<T> minor(int row, int col) const;
};


template<typename T>
Matrix<T>::Matrix(int rows, int cols, T **data) {
    this->rows = rows;
    this->cols = cols;
    this->data = new T *[rows];
    for (int i = 0; i < rows; i++) this->data[i] = new T[cols];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            this->data[i][j] = data[i][j];
        }
    }
}

template<typename T>
Matrix<T>::Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    data = new T *[rows];
    for (int i = 0; i < rows; i++) data[i] = new T[cols];
}

template<typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
}


template<typename T>
Matrix<T> Matrix<T>::transpose() const {
    Matrix<T> result(cols, rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[j][i] = data[i][j];
        }
    }

    return result;
}

template<typename T>
Matrix<T> Matrix<T>::inverse() const {
    if (rows != cols) {
        std::cout << "not square" << std::endl;
        exit(1);
    }

    Matrix<T> invMatrix(rows, cols);

    T det = determinant();
    if (det == 0) {
        std::cout << "Determinant is 0. EXIT" << std::endl;
        exit(1);
    }

    Matrix<T> adjMatrix(rows, cols);
    int k = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Matrix<T> minorMatrix = minor(i, j);
            T minorDet = minorMatrix.determinant();
            if ((rows + cols) % 2 == 1) { k = -1; }
            else k = 1;
            adjMatrix.data[i][j] = k * minorDet;
            if (adjMatrix.data[i][j] == 0 ) adjMatrix.data[i][j] = 0 ;

        }
    }
    det = 1.0 / det;
    invMatrix = adjMatrix.transpose() * det;

    return invMatrix;
}


template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &other) const {
    if (rows != other.rows || cols != other.cols) {
        std::cout << "Not same size\n" << std::endl;
        exit(1);
    }

    Matrix<T> result(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }

    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &other) const {
    if (cols != other.rows) {
        std::cout << "Not capable" << std::endl;
        exit(1);
    }

    int resultRows = rows;
    int resultCols = other.cols;
    Matrix<T> result(resultRows, resultCols);

    for (int i = 0; i < resultRows; i++) {
        for (int j = 0; j < resultCols; j++) {
            T sum = 0;
            for (int k = 0; k < cols; k++) {
                sum += data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }

    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(T scalar) const {
    Matrix<T> result(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }

    return result;
}

template<typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &other) {
    if (this == &other) {
        return *this;
    }


    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[]data;

    rows = other.rows;
    cols = other.cols;
    data = new T *[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new T[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }

    return *this;
}

//
//template<typename T>
//void Matrix<T>::print(1) const {
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//       std::cout << std::fixed << std::setprecision(6) << data[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//}
template<typename T>
void Matrix<T>::print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double k = data[i][j];
            std::cout << std::fixed << std::setprecision(10) << k << " ";
            if (data[i][j] == 0.) data[i][j] = 0;
            //printf("%f ", data[i][j]);
        }
        printf("\n");
    }
}

template<typename T>
T Matrix<T>::determinant() const {
    if (rows != cols) {
        std::cout << "Not square" << std::endl;
        exit(1);
    }

    if (rows == 1) {
        return data[0][0];
    }

    if (rows == 2) {
        return (data[0][0] * data[1][1]) - (data[0][1] * data[1][0]);
    }

    T det = 0.;
    for (int i = 0; i < cols; i++) {
        if (data[0][i] == 0) continue;
        else { det += std::pow(-1, i) * data[0][i] * minor(0, i).determinant(); }
    }

    return det;
}

template<typename T>
Matrix<T> Matrix<T>::minor(int row, int col) const {

    Matrix<T> minorMatrix(rows - 1, cols - 1);
    int minorRow = 0;
    for (int i = 0; i < rows; i++) {
        if (i == row) {
            continue;
        }
        int minorCol = 0;
        for (int j = 0; j < cols; j++) {
            if (j == col) {
                continue;
            }
            minorMatrix.data[minorRow][minorCol] = data[i][j];
            minorCol++;
        }
        minorRow++;
    }
    return minorMatrix;
}

#endif  // MATRIX_H
