#include "units.h"
#include <stdexcept>

// Contains implementation of functions in units.h

/** Two-argument constructor - stores given value and units
 */
UValue::UValue(double value, const string &units) {
    this->value = value;
    this->units = units;
}

/** Returns value of a UValue
 */
double UValue::get_value() const {
    return value;
}

/** Returns units of a UValue
 */
string UValue::get_units() const {
    return units;
}


/** Adds a new conversion to the converter.
 *
 * Throws invalid_argument if conversion already exists.
 */
void UnitConverter::add_conversion(const string &from_units, double multiplier,
                                    const string &to_units) {
    // Check if conversion already exists
    for (Conversion c : conversions) {
        if (c.from_units == from_units && c.to_units == to_units) {
            string msg = "Already have a conversion from " + from_units + " to "
                            + to_units;
            throw invalid_argument(msg);
        }
    }

    // Add given conversion and reversed conversion
    conversions.push_back({from_units, multiplier, to_units});
    conversions.push_back({to_units, 1 / multiplier, from_units});
}

/** Converts units of a UValue input to to_units by calling three-argument
 * convert_to() function.
 */
UValue UnitConverter::convert_to(const UValue &input, const string &to_units)
                                                                    const {
    set<string> seen{};
    return convert_to(input, to_units, seen);
}

/** Converts units of a UValue input to to_units using recursion.
 *
 * Throws invalid_argument if conversion doesn't exist.
 */
UValue UnitConverter::convert_to(const UValue &input, const string &to_units,
                                    set<string> &seen) const {
    string from_units = input.get_units();
    seen.insert(from_units);

    // Find a conversion and return converted UValue
    for (Conversion c : conversions) {
        if (c.from_units == from_units) {
            if (c.to_units == to_units) {
                return UValue{input.get_value() * c.multiplier, to_units};
            }
            else if (seen.count(c.to_units) == 0) {
                UValue v{input.get_value() * c.multiplier, c.to_units};
                try {
                    return convert_to(v, to_units, seen);
                }
                catch (invalid_argument) {
                }
            }
        }
    }

    // Report failure if conversion doesn't exist
    string msg = "Don't know how to convert from " + from_units + " to "
                     + to_units;
    throw invalid_argument(msg);
}
