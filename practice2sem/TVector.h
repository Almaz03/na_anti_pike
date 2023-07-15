#include <iostream>

template<typename T>
class TVector {
private:
    T *data;
    int n;

public:
    TVector(int n, T *data) {
        this->n = n;
        this->data = new T[n];

        for (int i = 0; i < n; ++i) {
            this->data[i] = data[i];
        }
    }

    TVector(int n) {
        this->n = n;
        this->data = new T[n];
    }

    TVector<T> operator+(const TVector<T> &other) const {
        TVector<T> result(n);

        for (int i = 0; i < n; ++i) {
            result.data[i] = data[i] + other.data[i];
        }

        return result;
    }

    TVector<T> operator/(const TVector<T> &other) const {
        TVector<T> result(n);

        for (int i = 0; i < n; ++i) {
            result.data[i] = data[i] * other.data[i];
        }

        return result;
    }

    TVector<T> operator*(T scalar) const {
        TVector<T> result(n);

        for (int i = 0; i < n; ++i) {
            result.data[i] = data[i] * scalar;
        }

        return result;
    }

    T operator*(const TVector<T> &other) const {
        T result = 0;

        for (int i = 0; i < n; ++i) {
            result += data[i] * other.data[i];
        }

        return result;
    }

    TVector<T> operator^(const TVector<T> &other) const {

        TVector<T> result(n);
        if (n != 3) exit(1);

        result.data[0] = data[1] * other.data[2] - data[2] * other.data[1];
        result.data[1] = data[2] * other.data[0] - data[0] * other.data[2];
        result.data[2] = data[0] * other.data[1] - data[1] * other.data[0];

        return result;
    }

    void print() const {
        std::cout << "(";
        for (int i = 0; i < n; ++i) {
            std::cout << data[i];
            if (i != n - 1) {
                std::cout << ", ";
            }
        }
        std::cout << ")\n";
    }

    ~TVector() {
        delete[] data;
    }
};
