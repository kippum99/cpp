#include "units.h"

// Two-argument constructor - stores given value and units
UValue::UValue(double value, string units) {
    this->value = value;
    this->units = units;
}

// Returns value of a UValue
double UValue::get_value() {
    return this->value;
}

// Returns units of a UValue
string UValue::get_units() {
    return this->units;
}

// Converts units of a UValue input to to_units
UValue convert_to(UValue input, string to_units) {
    if (input.get_units() == "lb" && to_units == "kg") {
        return UValue(input.get_value() * 0.45, "kg");
    }
    else if (input.get_units() == "gal" && to_units == "L") {
        return UValue(input.get_value() * 3.79, "L");
    }
    else if (input.get_units() == "mi" && to_units == "km") {
        return UValue(input.get_value() * 1.6, "km");
    }
    else {
        return input;
    }
}
