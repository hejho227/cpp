#pragma once

#include <iostream>
#include <stdexcept>    
#include <string>

class MatrixError : public std::runtime_error {
public:
    explicit MatrixError(const std::string& message) : std::runtime_error(message) {}
};

class InvalidIndexError : public MatrixError {
public:
    explicit InvalidIndexError(const std::string& message) : MatrixError(message) {}
};

class MemoryAllocationError : public MatrixError {
public:
    explicit MemoryAllocationError(const std::string& message) : MatrixError(message) {}
};

class Matrix {
private:
    int rows, cols;
    int** data;
    int* ref_count;

    void deep_copy(const Matrix& other);
    void deallocate();

public:
    Matrix(int rows, int cols);
    Matrix(int number);
    Matrix(const Matrix& other);
    ~Matrix();
    Matrix& operator=(const Matrix& other);

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);

    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;

    int& operator()(int row, int col);
    const int& operator()(int row, int col) const;

    void read_from_file(std::istream& in);
    void display(std::ostream& out) const;

    int get_rows() const { return rows; }
    int get_cols() const { return cols; }
};


Matrix operator+(double real, const Matrix& matrix);
Matrix operator-(double real, const Matrix& matrix);
Matrix operator*(double real, const Matrix& matrix);
Matrix operator/(double real, const Matrix& matrix);
std::ostream& operator<<(std::ostream& out, const Matrix& matrix);