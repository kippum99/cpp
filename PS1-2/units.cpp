#include "units.h"

// Contains implementation of functions in units.h

// Two-argument constructor - stores given value and units
UValue::UValue(double value, string units) {
    this->value = value;
    this->units = units;
}

// Returns value of a UValue
double UValue::get_value() {
    return value;
}

// Returns units of a UValue
string UValue::get_units() {
    return units;
}


/* Adds a new conversion to the converter.
 *
 * Throws invalid_argument if conversion already exists.
 */
void UnitConverter::add_conversion(string from_units, double multiplier,
                                    string to_units) {
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

/* Converts units of a UValue input to to_units.
 *
 * Throws invalid_argument if conversion doesn't exist.
 */
UValue UnitConverter::convert_to(UValue input, string to_units) {
    string from_units = input.get_units();

    // Find a conversion and return converted UValue
    for (Conversion c : conversions) {
        if (c.from_units == from_units && c.to_units == to_units) {
            return UValue{input.get_value() * c.multiplier, to_units};
        }
    }

    // Report failure if conversion doesn't exist
    string msg = "Don't know how to convert from " + from_units + " to "
                     + to_units;
    throw invalid_argument(msg);
}
