#include <string>

using namespace std;

// A united-value class holding a double value and string units for the value
class UValue {
    double value;   // value itself
    string units;   // units for the value

public:
    // Two-argument constructor - stores given value and units
    UValue(double value, string units);

    double get_value();   // Returns value of a UValue
    string get_units();   // Returns units of a UValue
};

// Converts units of a UValue input to to_units
UValue convert_to(UValue input, string to_units);
