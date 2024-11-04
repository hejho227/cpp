#include "complex.h"
#include <math.h>

using namespace std;

complexNum::complexNum() : real(0), imaginary(0){};


complexNum::complexNum(double real, double imaginary){
    this->real = real;
    this->imaginary = imaginary;
}


complexNum::complexNum(double real){
    this->real = real;
    this->imaginary = 0;
}


complexNum complexNum::operator+(const complexNum& other) const{
    return complexNum (this->real + other.real, this->imaginary + other.imaginary);
}


complexNum complexNum::operator-(const complexNum& other) const{
    return complexNum (this->real - other.real, this->imaginary - other.imaginary);
}


complexNum complexNum::operator*(const complexNum& other) const{
    complexNum answer = *this;
    answer *= other;
    return answer;
}


complexNum complexNum::operator/(const complexNum& other) const{
    complexNum answer = *this;
    answer /= other;
    return answer;
}


complexNum& complexNum::operator+=(const complexNum& other){
    this->real += other.real;
    this->imaginary += other.imaginary;
    return *this;
}

complexNum& complexNum::operator-=(const complexNum& other){
    this->real -= other.real;
    this->imaginary -= other.imaginary;
    return *this;
}

complexNum& complexNum::operator*=(const complexNum& other){
    double realCal = this->real * other.real - this->imaginary * other.imaginary;
    double imagCal = this->imaginary * other.real + this->real * other.imaginary;
    this->real = realCal;
    this->imaginary = imagCal;
    return *this;
}


complexNum& complexNum::operator/=(const complexNum& other){
    complexNum conjugate(other.real, -other.imaginary); 
    conjugate *= *this;
    double lower = other.real * other.real + other.imaginary * other.imaginary;

    double realCal = (float)conjugate.real / (float)lower;
    double imagCal = (float)conjugate.imaginary / (float)lower;
    this->real = realCal;
    this->imaginary = imagCal;
    return *this;
}

ostream& operator<<(ostream& stream, const complexNum& number){
    if (number.imaginary == 0){
        stream << number.real;
        return stream;
    }
    if (number.real != 0) stream << number.real;
    if (number.getImaginary() < 0){
        stream << " - " << abs(number.imaginary) << "i";
    }else{
        stream << " + " << number.imaginary << 'i';
    } 
    return stream;
}


bool complexNum::operator==(const complexNum& other) const{
    return ((this->real == other.real) && (this->imaginary == other.imaginary));
}


bool complexNum::operator!=(const complexNum& other) const{
    return !((this->real == other.real) && (this->imaginary == other.imaginary));
}


double complexNum::getImaginary() const {
    return imaginary;
}


double complexNum::getReal() const {
    return real;
}


double complexNum::getAmplitude() const{
    return (sqrt(this->real * this->real + this->imaginary * this->imaginary));
}

double complexNum::getPhase() const{
    return (atan2(this->imaginary, this->real));
}


complexNum operator+(double real, const complexNum& complex) {
    return complexNum(real) + complex;
}


complexNum operator-(double real, const complexNum& complex) {
    return complexNum(real) - complex;
}


complexNum operator*(double real, const complexNum& complex) {
    return complexNum(real) * complex;
}


complexNum operator/(double real, const complexNum& complex) {
    return complexNum(real) / complex;
}


bool operator==(double real, const complexNum& other){
    return (complexNum (real) == other);
}


bool operator!=(double real, const complexNum& other){
    return (complexNum (real) != other);
}