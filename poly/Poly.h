#pragma once
#include <iostream>
#include <map>
using namespace std;

class Poly{
    private:
	    map<int, double> coeficiant;

    public:
        Poly();
        Poly(double constant);
        Poly(int exponent, double constant);


        Poly operator+(const Poly& other) const;
        Poly& operator+=(const Poly& other);
        Poly& operator-=(const Poly& other);
        Poly operator-(const Poly& other) const;

        friend ostream& operator<<(ostream& stream, const Poly& poly);
        
        double& operator[](int exp);
        const double operator[](int exp) const;

        Poly operator*(const Poly& other) const;
        Poly& operator*=(const Poly& other);

        Poly operator-() const;

        double operator()(int exp) const;


};

Poly operator*(double constant, const Poly& other);
Poly operator-(double constant, const Poly& other);
Poly operator+(double constant, const Poly& other);