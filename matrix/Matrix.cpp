#include "Matrix.h"

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), ref_count(new int(1)) {
    data = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols]{0};
    }
}

Matrix::Matrix(int number) : rows(1), cols(1), ref_count(new int(1)) {
    data = new int*[1];
    data[1] = new int[1]{number};
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data), ref_count(other.ref_count) {
    ++(*ref_count);
}

Matrix::~Matrix() {
    --(*ref_count);
    if (*ref_count == 0) {
        deallocate();
    }
}

void Matrix::deallocate() {
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
    delete ref_count;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        --(*ref_count);
        if (*ref_count == 0) {
            deallocate();
        }
        rows = other.rows;
        cols = other.cols;
        data = other.data;
        ref_count = other.ref_count;
        ++(*ref_count);
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw InvalidIndexError("Matrices have different dimensions for addition.");
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result(i, j) = data[i][j] + other(i, j);
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw InvalidIndexError("Matrices have different dimensions for subtraction.");
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result(i, j) = data[i][j] - other(i, j);
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw InvalidIndexError("Matrices have incompatible dimensions for multiplication.");
    }
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            result(i, j) = 0;
            for (int k = 0; k < cols; ++k) {
                result(i, j) += data[i][k] * other(k, j);
            }
        }
    }
    return result;
}

Matrix& Matrix::operator+=(const Matrix& other) {
    if (rows != other.rows || cols != other.cols) {
        throw InvalidIndexError("Matrices have different dimensions for addition.");
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] += other(i, j);
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    if (rows != other.rows || cols != other.cols) {
        throw InvalidIndexError("Matrices have different dimensions for subtraction.");
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] -= other(i, j);
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
    if (cols != other.rows) {
        throw InvalidIndexError("Matrices have incompatible dimensions for multiplication.");
    }
    *this = *this * other;
    return *this;
}

bool Matrix::operator==(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        return false;
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (data[i][j] != other(i, j)) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

int& Matrix::operator()(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw InvalidIndexError("Index out of bounds.");
    }
    return data[row][col];
}

const int& Matrix::operator()(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw InvalidIndexError("Index out of bounds.");
    }
    return data[row][col];
}

void Matrix::read_from_file(std::istream& in) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!(in >> data[i][j])) {
                throw MatrixError("Error reading matrix from file.");
            }
        }
    }
}

void Matrix::display(std::ostream& out) const {
    for (int i = 0; i < rows; ++i) {
        out << "|";
        for (int j = 0; j < cols; ++j) {
            out << data[i][j];
            if (j != cols - 1){
                out << " ";
            }
        }
        out << "|" << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
    matrix.display(out);
    return out;
}



Matrix operator+(double real, const Matrix& matrix){
    Matrix otherMatrix(real);
    return (matrix + otherMatrix);
}

Matrix operator-(double real, const Matrix& matrix){
    Matrix otherMatrix(real);
    return otherMatrix - matrix;
}

Matrix operator*(double real, const Matrix& matrix){
    Matrix otherMatrix(real);
    return otherMatrix * matrix;
}