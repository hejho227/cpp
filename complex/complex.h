#pragma once
#include <iostream>
using namespace std;

class complexNum{
    private:
	    double real, imaginary;

    public:
        complexNum();
        complexNum(double real);
        complexNum(double real, double imaginary);
        complexNum operator+(const complexNum& other) const;
        complexNum operator-(const complexNum& other) const;
        complexNum operator*(const complexNum& other) const;
        complexNum operator/(const complexNum& other) const;
        complexNum& operator+=(const complexNum& other);
        complexNum& operator-=(const complexNum& other);
        complexNum& operator*=(const complexNum& other);
        complexNum& operator/=(const complexNum& other);
        friend ostream& operator<<(ostream& stream, const complexNum& number);

        bool operator==(const complexNum& other) const;
        bool operator!=(const complexNum& other) const;

        double getAmplitude() const;
        double getPhase() const;
        double getImaginary() const;
        double getReal() const;



};

complexNum operator+(double real, const complexNum& complex);
complexNum operator-(double real, const complexNum& complex);
complexNum operator*(double real, const complexNum& complex);
complexNum operator/(double real, const complexNum& complex);
bool operator==(double real, const complexNum& other);
bool operator!=(double real, const complexNum& other);