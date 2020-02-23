#include <iostream>
#include <stdexcept>

using namespace std;

/** A class representing a Rational number with a numerator and a denominator.
 */
class Rational {
    /** Numerator of the fraction representation of the number */
    int n;

    /** Denominator of the fraction representation of the number */
    int d;

    /** Helper funciton that finds the greatest common divisor of two integers.
     */
    int gcd(int a, int b);

public:
    /** Constructor that supports zero, one, or two arguments.
     * Throws invalid_argument error if denominator is 0.
     */
    Rational(int n = 0, int d = 1);

    /** Returns the numerator. */
    int num() const;

    /** Returns the denominator. */
    int denom() const;

    /** Returns the reciprocal of the number. */
    Rational reciprocal() const;

    /** Reduces the number such that the greatest common divisor of the
     * numerator and denominator is 1.
     */
    void reduce();

    /** Addition assignment operator for Rational numbers. */
    Rational & operator+=(const Rational &rhs);

    /** Subtraction assignment operator for Rational numbers. */
    Rational & operator-=(const Rational &rhs);

    /** Multiplication assignment operator for Rational numbers. */
    Rational & operator*=(const Rational &rhs);

    /** Division assignment operator for Rational numbers. */
    Rational & operator/=(const Rational &rhs);
};
