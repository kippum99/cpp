#include <string>
#include <vector>

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

// A class to keep track of all conversions and perform conversions
class UnitConverter {
    // Struct to keep track of conversion details
    struct Conversion {
        string from_units;
        double multiplier;
        string to_units;
    };

    std::vector<Conversion> conversions; // Collection of conversions

public:
    // Adds a conversion to the converter
    void add_conversion(string from_units, double multiplier, string to_units);

    // Converts units of a UValue input to to_units
    UValue convert_to(UValue input, string to_units);
};
