/* Header file for Matrix class. */

#include <stdexcept>

using namespace std;


/** A class that represents a 2D matrix of integers. */
class Matrix {
    /** Number of rows in the matrix */
    int rows;

    /** Number of columns in the matrix */
    int cols;

    /** 1d array to store elements of the matrix */
    int *elems;


    /** Helper function that copies contents from the given Matrix m.
     *
     * @param m Matrix to copy contents from into the current Matrix
     */
    void copy_contents(const Matrix &m) {
        rows = m.rows;
        cols = m.cols;

        // Make a deep copy
        elems = new int[rows * cols];

        for (int i = 0; i < rows * cols; i++) {
            elems[i] = m.elems[i];
        }
    }

    /** Helper function that moves contents from the given Matrix m.
     *
     * @param m Matrix to move contents from into the current Matrix
     */
    void move_contents(Matrix &m) {
        rows = m.rows;
        cols = m.cols;
        elems = m.elems;
        m.elems = nullptr;
    }

public:
    /** Default constructor that initializes a 0x0 matrix. */
    Matrix() {
        rows = 0;
        cols = 0;
        elems = new int[0];
    }

    /** Constructor that initializes a rows x cols matrix where all elements
     * are set to 0.
     * An invalid_argument error is thrown if if rows or cols is not positive.
     *
     * @param rows Number of rows
     * @param cols Number of columns
     */
    Matrix(int rows, int cols) {
        if (rows <= 0 || cols <= 0) {
            throw invalid_argument(
                "Number of rows and columns must be positive."
            );
        }

        this->rows = rows;
        this->cols = cols;
        elems = new int[rows * cols];

        for (int i = 0; i < rows * cols; i++) {
            elems[i] = 0;
        }
    }

    /** Copy-constructor that creates a new matrix object by copying contents
     * from m.
     *
     * @param m Matrix to copy contents from
     */
    Matrix(const Matrix &m) {
        copy_contents(m);
    }

    /** Move-constructor that moves the contents of Matrix m into the new object
     * being intialized.
     *
     * @param m Matrix to move contents from
     */
    Matrix(Matrix &&m) {
        move_contents(m);
    }

    /** Copy-assignment operator that frees the resources in the object and
     * copies the contents of m into the object, returning the reference to
     * the object.
     *
     * @param m Matrix to copy contents from
     */
    Matrix & operator=(const Matrix &m) {
        // Detect and handle self-assignment
        if (this == &m) {
            return *this;
        }

        this->~Matrix();
        copy_contents(m);

        return *this;
    }

    /** Move-assignment operator that moves the contents of Matrix m into the
     * LHS of the assignment.
     *
     * @param m Matrix to copy contents from
     */
    Matrix & operator=(Matrix &&m) {
        // Detect and handle self-assignment
        if (this == &m) {
            return *this;
        }

        this->~Matrix();
        move_contents(m);

        return *this;
    }

    /** Destructor for the object that frees the dynamically allocated memory.
     */
    ~Matrix() {
        delete[] elems;
    }


    /** Returns the number of rows in the matrix.
     *
     * @return Number of rows in the Matrix
     */
    int numRows() const {
        return rows;
    }

    /** Returns the number of cols in the matrix.
     *
     * @return Number of columns in the Matrix
     */
    int numCols() const {
        return cols;
    }

    /** Returns the value stored at the specified row and column.
     * Throws an invalid_argument exception if the row or column index is out of
     * bounds.
     *
     * @param r Row index
     * @param c Column index
     * @return Value at the specified row and column
     */
    int get(int r, int c) const {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            throw invalid_argument("The row or column index is out of bounds.");
        }

        return elems[r * cols + c];
    }

    /** Sets the value stored at the specified row and column.
     * Throws an invalid_argument exception if the row or column index is out of
     * bounds
     *
     * @param r Row index
     * @param c Column index
     * @param Value to store at the specified row and column
     */
    void set(int r, int c, int value) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            throw invalid_argument("The row or column index is out of bounds.");
        }

        elems[r * cols + c] = value;
    }

    /** Returns true if the two matrices are equal, with the same size and
     * identical elements, and false otherwise.
     *
     * @param m Matrix to compare to
     * @return Boolean value indicating whether they were equal or not
     */
    bool operator==(const Matrix &m) const {
        if (rows != m.rows || cols != m.cols) {
            return false;
        }

        for (int i = 0; i < rows * cols; i++) {
            if (elems[i] != m.elems[i]) {
                return false;
            }
        }

        return true;
    }

    /** Returns false if the two matrices are equal, with the same size and
     * identical elements, and true otherwise.
     *
     * @param m Matrix to compare to
     * @return Boolean value indicating whether they were unequal or not
     */
    bool operator!=(const Matrix &m) const {
        return !operator==(m);
    }


    /** Addition assignment operator.
     *
     * Throws an invalid argument if dimensions aren't equal.
     *
     * @param m Matrix being added to LHS
     * @return Reference to LHS after addition
     */
    Matrix & operator+=(const Matrix &m) {
        if (rows != m.rows || cols != m.cols) {
            throw invalid_argument("The dimensions must be equal.");
        }

        for (int i = 0; i < rows * cols; i++) {
            elems[i] += m.elems[i];
        }

        return *this;
    }

    /** Subtraction assignment operator.
     *
     * Throws an invalid argument if dimensions aren't equal.
     *
     * @param m Matrix being subtracted from LHS
     * @return Reference to LHS after subtraction
     */
    Matrix & operator-=(const Matrix &m) {
        if (rows != m.rows || cols != m.cols) {
            throw invalid_argument("The dimensions must be equal.");
        }

        for (int i = 0; i < rows * cols; i++) {
            elems[i] -= m.elems[i];
        }

        return *this;
    }

    /** Multiplication assignment operator.
     *
     * Throws an invalid argument if dimensions aren't compatible.
     *
     * @param m Matrix being multiplied to LHS
     * @return Reference to LHS after multiplication
     */
    Matrix & operator*=(const Matrix &m);
};


/* Addition operator for two Matrix objects.
 *
 * Throws an invalid argument if dimensions aren't equal.
 *
 * @param m First Matrix object
 * @param n Second Matrix object
 * @return Matrix object that is the sum of the two matrices
 */
inline Matrix & operator+(const Matrix &m, const Matrix &n) {
    return Matrix{m} += n;
}

/* Subtraction operator for two Matrix objects.
 *
 * Throws an invalid argument if dimensions aren't equal.
 *
 * @param m First Matrix object
 * @param n Second Matrix object
 * @return Matrix object that is the difference of the two matrices
 */
inline Matrix & operator-(const Matrix &m, const Matrix &n) {
    return Matrix{m} -= n;
}

/* Multiplication operator for two Matrix objects.
 *
 * Throws an invalid argument if dimensions aren't compatible.
 *
 * @param m First Matrix object
 * @param n Second Matrix object
 * @return Matrix object that is the product of the two matrices
 */
inline Matrix & operator*(const Matrix &m, const Matrix &n) {
    int m_rows = m.numRows();
    int m_cols = m.numCols();
    int n_rows = n.numRows();
    int n_cols = n.numCols();

    if (m_cols != n_rows) {
        throw invalid_argument("Dimensions aren't compatible.");
    }

    Matrix p{m_rows, n_cols};

    for (int r = 0; r < m_rows; r++) {
        for (int c = 0; c < n_cols; c++) {
            for (int i = 0; i < m_cols; i++) {
                p.set(r, c, m.get(r, i) * n.get(i, c));
            }
        }
    }

    return p;
}
