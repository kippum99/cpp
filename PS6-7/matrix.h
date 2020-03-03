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


    /** Helper function that copies contents from the given Matrix m. */
    void copy_contents(const Matrix &m) {
        rows = m.rows;
        cols = m.cols;

        // Make a deep copy
        elems = new int[rows * cols];

        for (int i = 0; i < rows * cols; i++) {
            elems[i] = m.elems[i];
        }
    }

public:
    /** Default constructor that initializes a 0x0 matrix. */
    Matrix() {
        rows = 0;
        cols = 0;
    }

    /** Constructor that initializes a rows x cols matrix where all elements
     * are set to 0.
     * An invalid_argument error is thrown if if rows or cols is not positive.
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
     */
    Matrix(const Matrix &m) {
        copy_contents(m);
    }

    /** Copy-assignment operator that frees the resources in the object and
     * copies the contents of m into the object, returning the reference to
     * the object.
     */
    Matrix & operator=(const Matrix &m) {
        this->~Matrix();
        copy_contents(m);

        return *this;
    }

    /** Destructor for the object that frees the dynamically allocated memory.
     */
    ~Matrix() {
        delete[] elems;
    }


    /** Returns the number of rows in the matrix. */
    int numRows() const {
        return rows;
    }

    /** Returns the number of cols in the matrix. */
    int numCols() const {
        return cols;
    }

    /** Returns the value stored at the specified row and column.
     * Throws an invalid_argument exception if the row or column index is out of
     * bounds.
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
     */
    void set(int r, int c, int value) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            throw invalid_argument("The row or column index is out of bounds.");
        }

        elems[r * cols + c] = value;
    }

    /** Returns true if the two matrices are equal, with the same size and
     * identical elements, and false otherwise.
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
     */
    bool operator!=(const Matrix &m) const {
        return !operator==(m);
    }
};
