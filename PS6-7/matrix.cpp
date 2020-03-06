#include "matrix.h"

/** Multiplication assignment operator.
 *
 * Throws an invalid argument if dimensions aren't compatible.
 *
 * @param m Matrix being multiplied to LHS
 * @return Reference to LHS after multiplication
 */
Matrix & Matrix::operator*=(const Matrix &m) {
    *this = *this * m;

    return *this;
}
