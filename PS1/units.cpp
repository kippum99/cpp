#include "units.h"

UValue::UValue(double value, string units) {
    this->value = value;
    this->units = units;
}

double UValue::get_value() {
    return this->value;
}

string UValue::get_units() {
    return this->units;
}
