#include "complex.h"
#include <iostream>

using namespace std;

void display(const complexNum& c1, const complexNum& c2);
void test(const complexNum& c1, const complexNum& c2);
void testAddition(const complexNum& c1, const complexNum& c2);
void testSubtraction(const complexNum& c1, const complexNum& c2);
void testMultiplication(const complexNum& c1, const complexNum& c2);
void testDivision(const complexNum& c1, const complexNum& c2);
void testAssignmentOfMultiple(const complexNum& c1, const complexNum& c2, const complexNum& c3);
void testEquality(const complexNum& c1, const complexNum& c2);
void testGetters(const complexNum& c1);
void test(const complexNum& c1, const complexNum& c2);

int main() {
    complexNum c1(3, 4);
    complexNum c2(1, -2);
    complexNum c3(-1, -1);
    complexNum c4(-3, 2);
    
    cout << "Complex number c1: " << c1 << endl;
    cout << "Complex number c2: " << c2 << endl;
    cout << "Complex number c3: " << c3 << endl;
    cout << "Complex number c4: " << c4 << endl;

    cout << endl << "testing c1 and c2: " << endl << endl;
    test(c1, c2);
    cout << endl << "testing c2 and c3: " << endl << endl;
    test(c2, c3);
    cout << endl << "testing c3 and c4: " << endl << endl;
    test(c3, c4);
    cout << endl << "rest of tests" << endl << endl;
    testGetters(c1);
    testAssignmentOfMultiple(c1, c2, c3);
}

void test(const complexNum& c1, const complexNum& c2){
    testAddition(c1, c2);
    testSubtraction(c1, c2);
    testMultiplication(c1, c2);
    testDivision(c1, c2);
    testEquality(c1, c2);
}

void testAddition(const complexNum& c1, const complexNum& c2) {
    cout << "Sum of first and secund: " << c1 + c2 << endl;

    cout << "Sum of first and 5.0: " << c1 + 5 << endl;

    cout << "Sum of 5.0 and first: " << 5 + c1 << endl;
}

void testSubtraction(const complexNum& c1, const complexNum& c2) {
    cout << "Difference of first and secund: " << c1 - c2 << endl;

    cout << "Difference of first and 5.0: " << c1 - 5 << endl;

    cout << "Difference of 5.0 and first: " << 5 - c1 << endl;
}

void testMultiplication(const complexNum& c1, const complexNum& c2) {
    cout << "Product of first and secund: " << c1 * c2 << endl;

    cout << "Product of first and 2.0: " << c1 * 2 << endl;

    cout << "Product of 2.0 and first: " << 2 * c2 << endl;
}

void testDivision(const complexNum& c1, const complexNum& c2) {
    cout << "Quotient of first divided by secund: " << c1 / c2 << endl;

    cout << "Quotient of first divided by 2.0: " << c1 / 2 << endl;

    cout << "Quotient of 2.0 divided by first: " << 2 / c1 << endl;
}

void testAssignmentOfMultiple(const complexNum& c1, const complexNum& c2, const complexNum& c3) {
    complexNum a = c1;
    complexNum b = c2;
    complexNum c = c3;
    
    a += b += c;
    cout << "Result of a += b += c: " << a << " and b: " << b << endl;

    a = c1;
    b = c2;
    c = c3;
    
    a -= b -= c;
    cout << "Result of a -= b -= c: " << a << " and b: " << b << endl;

    a = c1;
    b = c2;
    c = c3;
    
    a *= b *= c;
    cout << "Result of a *= b *= c: " << a << " and b: " << b << endl;

    a = c1;
    b = c2;
    c = c3;
    
    a /= b /= c;
    cout << "Result of a /= b /= c: " << a << " and b: " << b << endl;
}

void testEquality(const complexNum& c1, const complexNum& c2) {
    if (c1 == c2) {
        cout << "first is equal to secund" << endl;
    } else {
        cout << "first is not equal to secund" << endl;
    }

    if (c1 == 5) {
        cout << "first is equal to 5.0" << endl;
    } else {
        cout << "first is not equal to 5.0" << endl;
    }
    
    if (5 == c1) {
        cout << "5.0 is equal to first" << endl;
    } else {
        cout << "5.0 is not equal to first" << endl;
    }

    if (c1 != c2) {
        cout << "first is not equal to secund" << endl;
    } else {
        cout << "first is equal to secund" << endl;
    }
    
    if (c1 != 5) {
        cout << "first is not equal to 5.0" << endl;
    } else {
        cout << "first is equal to 5.0" << endl;
    }

    if (5 != c1) {
        cout << "5.0 is not equal to first" << endl;
    } else {
        cout << "5.0 is equal to first" << endl;
    }
}

void testGetters(const complexNum& c1) {
    cout << "Amplitude of first: " << c1.getAmplitude() << endl;
    cout << "Phase of first: " << c1.getPhase() << endl;
}