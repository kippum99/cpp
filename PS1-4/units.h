#include <set>
#include <string>
#include <vector>

using namespace std;

/** A united-value class holding a double value and string units for the value.
 */
class UValue {
    /** value itself */
    double value;

    /** units for the value */
    string units;

public:
    // Two-argument constructor - stores given value and units
    UValue(double value, const string &units);

    // Returns value of a UValue
    double get_value() const;

    // Returns units of a UValue
    string get_units() const;
};

/** A class to keep track of all conversions and perform conversions.
 */
class UnitConverter {
    /** Struct to keep track of conversion details
     */
    struct Conversion {
        /** A unit to convert from */
        string from_units;

        /** Multiplier for converting value from from_units to to_units */
        double multiplier;

        /** A unit to convert to */
        string to_units;
    };

    /** Collection of conversions */
    std::vector<Conversion> conversions;

public:
    // Adds a conversion to the converter
    void add_conversion(const string &from_units, double multiplier,
                        const string &to_units);

    // Converts units of a UValue input to to_units
    UValue convert_to(const UValue &input, const string &to_units) const;
    UValue convert_to(const UValue &input, const string &to_units,
                        set<string> &seen) const;
};
