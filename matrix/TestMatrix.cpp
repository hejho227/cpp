#include "Matrix.h"
#include <iostream>

using namespace std;

void display(const Matrix& m1, const Matrix& m2);
void test(const Matrix& m1, const Matrix& m2);
void testAddition(const Matrix& m1, const Matrix& m2);
void testSubtraction(const Matrix& m1, const Matrix& m2);
void testMultiplication(const Matrix& m1, const Matrix& m2);
void testAssignmentOperations(const Matrix& m1);
void testEqual(const Matrix& m1, const Matrix& m2);
void testElementAccess(const Matrix& m1);

int main() {
    Matrix m1(2, 2);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(1, 0) = 3;
    m1(1, 1) = 4;

    Matrix m2(2, 2);
    m2(0, 0) = 5;
    m2(0, 1) = 6;
    m2(1, 0) = 7;
    m2(1, 1) = 8;

    display(m1, m2);
    test(m1, m2);
    
    return 0;
}

void display(const Matrix& m1, const Matrix& m2) {
    cout << "Matrix m1:\n" << m1 << endl;
    cout << "Matrix m2:\n" << m2 << endl;
}

void test(const Matrix& m1, const Matrix& m2) {
    testAddition(m1, m2);
    testSubtraction(m1, m2);
    testMultiplication(m1, m2);
    testAssignmentOperations(m1);
    testEqual(m1, m2);
    testElementAccess(m1);
}

void testAddition(const Matrix& m1, const Matrix& m2) {
    try {
        Matrix result = m1 + m2;
        cout << "Sum of matrices m1 and m2:\n" << result << endl;
        result = m1 + 2;
        cout << "Sum of matrices m1 and 2:\n" << result << endl;
        result = 2 + m1;
        cout << "Sum of matrices 2 and m1:\n" << result << endl;
    } catch (const MatrixError& e) {
        cout << "Error during matrix addition: " << e.what() << endl;
    }
}

void testSubtraction(const Matrix& m1, const Matrix& m2) {
    try {
        Matrix result = m1 - m2;
        cout << "Difference of matrices m1 and m2:\n" << result << endl;
        result = m1 - 2;
        cout << "Difference of matrices m1 and 2:\n" << result << endl;
        result = 2 - m1;
        cout << "Difference of matrices 2 and m1:\n" << result << endl;
    } catch (const MatrixError& e) {
        cout << "Error during matrix subtraction: " << e.what() << endl;
    }
}

void testMultiplication(const Matrix& m1, const Matrix& m2) {
    try {
        Matrix result = m1 * m2;
        cout << "Product of matrices m1 and m2:\n" << result << endl;
        result = m1 * 2;
        cout << "Product of matrices m1 and 2:\n" << result << endl;
        result = 2 * m1;
        cout << "Product of matrices 2 and m1:\n" << result << endl;
    } catch (const MatrixError& e) {
        cout << "Error during matrix multiplication: " << e.what() << endl;
    }
}

void testAssignmentOperations(const Matrix& m1) {
    Matrix result = m1;

    result += m1;
    cout << "Result after += m1 operation:\n" << result << endl;
    result += 2;
    cout << "Result after += 2 operation:\n" << result << endl;

    result = m1;
    result -= m1;
    cout << "Result after -= m1 operation:\n" << result << endl;
    result -= 2;
    cout << "Result after -=  2operation:\n" << result << endl;

    result = m1;
    result *= m1;
    cout << "Result after *= m1 operation:\n" << result << endl;
    result *= 2;
    cout << "Result after *= 2 operation:\n" << result << endl;
}

void testEqual(const Matrix& m1, const Matrix& m2) {
    if (m1 == m2) {
        cout << "m1 == m2" << endl;
    } else {
        cout << "m1 != m2" << endl;
    }

    Matrix m3 = m1;
    if (m1 == m3) {
        cout << "m1 == m3 (copy of m1)" << endl;
    }
}

void testElementAccess(const Matrix& m1) {
    try {
        cout << "Element at (0, 0) in m1: " << m1(0, 0) << endl;
        cout << "Element at (1, 1) in m1: " << m1(1, 1) << endl;

        // Test out-of-bounds access
        cout << "Trying to access element at (2, 2) (should throw an exception)" << endl;
        cout << m1(2, 2) << endl;  // This should throw InvalidIndexError
    } catch (const InvalidIndexError& e) {
        cout << "Caught InvalidIndexError: " << e.what() << endl;
    }
}
