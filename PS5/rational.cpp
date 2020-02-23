/** This file contains implementation of functions in units.h */

#include "rational.h"

/** Constructor that supports zero, one, or two arguments.
 * Throws invalid_argument error if denominator is 0.
 */
Rational::Rational(int n, int d) {
    if (d == 0) {
        throw invalid_argument("Denominator can't be zero.");
    }
    else if (d < 0) {
        this->n = -n;
        this->d = -d;
    }
    else {
        this->n = n;
        this->d = d;
    }
}

/** Returns the numerator. */
int Rational::num() const {
    return n;
}

/** Returns the denominator. */
int Rational::denom() const {
    return d;
}

/** Returns the reciprocal of the given number. */
Rational Rational::reciprocal() const {
    return Rational{d, n};
}

/** Reduces the given number such that the greatest common divisor of the
 * numerator and denominator is 1.
 */
void Rational::reduce() {
    if (n == 0) {
        d = 1;
    }
    else {
        int _gcd = gcd(n, d);
        n /= _gcd;
        d /= _gcd;
    }
}


/** Addition assignment operator for Rational numbers. */
Rational & Rational::operator+=(const Rational &rhs) {
    n = n * rhs.denom() + rhs.num() * d;
    d *= rhs.denom();
    reduce();

    return *this;
}

/** Subtraction assignment operator for Rational numbers. */
Rational & Rational::operator-=(const Rational &rhs) {
    *this += Rational{-rhs.num(), rhs.denom()};

    return *this;
}

/** Multiplication assignment operator for Rational numbers. */
Rational & Rational::operator*=(const Rational &rhs) {
    n *= rhs.num();
    d *= rhs.denom();
    reduce();

    return *this;
}

/** Division assignment operator for Rational numbers. */
Rational & Rational::operator/=(const Rational &rhs) {
    *this *= rhs.reciprocal();

    return *this;
}


/** Helper funciton that finds the greatest common divisor of two integers.
 */
int Rational::gcd(int a, int b) {
    for (int i = (a < b ? a : b); i > 1; i--) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }

    return 1;
}


/** Returns the sum of two given rational numbers. */
Rational operator+(const Rational &a, const Rational &b) {
    return Rational{a} += b;
}

/** Returns the difference of two given rational numbers. */
Rational operator-(const Rational &a, const Rational &b) {
    return Rational{a} -= b;
}

/** Returns the product of two given rational numbers. */
Rational operator*(const Rational &a, const Rational &b) {
    return Rational{a} *= b;
}

/** Returns the quotient of two given rational numbers. */
Rational operator/(const Rational &a, const Rational &b) {
    return Rational{a} /= b;
}

/** Stream-Output for the given Rational number. */
ostream & operator<<(ostream &os, const Rational &r) {
    os << r.num();

    if (r.denom() != 1) {
        os << "/" << r.denom();
    }

    return os;
}
