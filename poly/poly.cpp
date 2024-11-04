#include "Poly.h"
#include <math.h>

using namespace std;

Poly::Poly() {}


Poly::Poly(double coeff){
    coeficiant[0] = coeff;
}


Poly::Poly(int exponent, double coeff){
    coeficiant[exponent] = coeff;
}


double& Poly::operator[](int exp){
    return coeficiant[exp];
}

const double Poly::operator[](int exp) const{
    auto found = coeficiant.find(exp);
    if (found == coeficiant.end()) return 0;
    return found->second;
}



Poly Poly::operator+(const Poly& other) const{
    Poly answer = *this;
    for (auto const& [exponent, coef] : other.coeficiant){
        answer.coeficiant[exponent] += coef;
        if (answer.coeficiant[exponent] == 0) answer.coeficiant.erase(exponent);
    }
    return answer;
}


Poly Poly::operator-(const Poly& other) const{
    Poly answer = *this;
    for (auto const& [exponent, coef] : other.coeficiant){
        answer.coeficiant[exponent] -= coef;
        if (answer.coeficiant[exponent] == 0) answer.coeficiant.erase(exponent);
    }
    return answer;
}



ostream& operator<<(ostream& stream, const Poly& polynom){
    bool first = 1;
    if (polynom.coeficiant.empty()){
        stream << '0';
        return stream;
    }
    for (auto iterator = polynom.coeficiant.rbegin(); iterator != polynom.coeficiant.rend(); iterator++){
        if (!first && iterator->second > 0) {
            stream << '+';
        }else if (iterator->second < 0) stream << '-';
        if (iterator->first == 0) {
            stream << abs(iterator->second);
        }else stream << abs(iterator->second) << "x^" << iterator->first;
        first = 0;
    }
    return stream;
}




Poly Poly::operator*(const Poly& other) const{
    Poly answer = *this;
    answer *= other;
    return answer;
}


Poly& Poly::operator+=(const Poly& other){
    for (auto const& [exponent, coef] : other.coeficiant){
        this->coeficiant[exponent] += coef;
        if (this->coeficiant[exponent] == 0) this->coeficiant.erase(exponent);
    }
    return *this;
}


Poly& Poly::operator-=(const Poly& other){
    for (auto const& [exponent, coef] : other.coeficiant){
        this->coeficiant[exponent] -= coef;
        if (this->coeficiant[exponent] == 0) this->coeficiant.erase(exponent);
    }
    return *this;
}


Poly& Poly::operator*=(const Poly& other){
    Poly answer;
    for (auto const& [exponent, coef] : other.coeficiant){
        for (auto const& [exp2, coef2] : this->coeficiant){
            answer[exponent + exp2] = coef * coef2;
        }
    }
    *this = answer;
    return *this;
}


Poly Poly::operator-() const{
    Poly answer;
    for (auto& [exponent, coef] : coeficiant){
        answer[exponent] = -coef;
    }
    return answer;
}


double Poly::operator()(int exp) const{
    double answer;
    for (auto& [exponent, coef] : coeficiant){
        answer += coef * pow(exp, exponent);
    }
    return answer;
}



/*

bool poly::operator==(const poly& other){
    return ((this->real == other.real) && (this->imaginary == other.imaginary));
}


bool poly::operator!=(const poly& other){
    return !((this->real == other.real) && (this->imaginary == other.imaginary));
}


*/

Poly operator+(double constant, const Poly& other) {
    Poly temporary = constant;
    return other + temporary;
}


Poly operator-(double constant, const Poly& other) {
    Poly temporary = constant;
    return temporary - other;
}


Poly operator*(double constant, const Poly& other) {
    Poly temporary = constant;
    return  other * temporary;
}