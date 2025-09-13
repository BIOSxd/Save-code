#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template<class T>
class Matrix {
private:
    int rows, cols;
    T* data;
public:
    Matrix(int r = 2, int c = 2) : rows(r), cols(c) {
        data = new T[rows * cols];
    }

    ~Matrix() { delete[] data; }

    T& at(int i, int j) { return data[i * cols + j]; }

    void input() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> at(i, j);
    }

    void fillRandom(T minVal = 0, T maxVal = 9) {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                at(i, j) = minVal + rand() % (maxVal - minVal + 1);
    }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << data[i * cols + j] << " ";
            cout << endl;
        }
    }

    T minElement() const {
        T m = data[0];
        for (int i = 1; i < rows * cols; i++)
            if (data[i] < m) m = data[i];
        return m;
    }

    T maxElement() const {
        T m = data[0];
        for (int i = 1; i < rows * cols; i++)
            if (data[i] > m) m = data[i];
        return m;
    }

    Matrix operator+(const Matrix& other) {
        Matrix res(rows, cols);
        for (int i = 0; i < rows * cols; i++)
            res.data[i] = data[i] + other.data[i];
        return res;
    }

    Matrix operator-(const Matrix& other) {
        Matrix res(rows, cols);
        for (int i = 0; i < rows * cols; i++)
            res.data[i] = data[i] - other.data[i];
        return res;
    }

    Matrix operator*(const Matrix& other) {
        Matrix res(rows, cols);
        for (int i = 0; i < rows * cols; i++)
            res.data[i] = data[i] * other.data[i];
        return res;
    }

    Matrix operator/(const Matrix& other) {
        Matrix res(rows, cols);
        for (int i = 0; i < rows * cols; i++) {
            if (other.data[i] == 0) throw runtime_error("Деление на ноль");
            res.data[i] = data[i] / other.data[i];
        }
        return res;
    }
};

int main() {
    srand(time(0));

    Matrix<int> A(2, 2), B(2, 2);

    cout << "Введите матрицу A:\n";
    A.input();

    B.fillRandom();
    cout << "\nСлучайная матрица B:\n";
    B.print();

    cout << "\nA + B:\n"; (A + B).print();
    cout << "\nA - B:\n"; (A - B).print();
    cout << "\nA * B:\n"; (A * B).print();
    cout << "\nA / B:\n"; (A / B).print();

    cout << "\nМинимум в A: " << A.minElement() << endl;
    cout << "Максимум в B: " << B.maxElement() << endl;

    return 0;
}