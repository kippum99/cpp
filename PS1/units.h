#include <string>

class UValue {
    double value;
    string units;

public:
    UValue(value, units);

    double get_value();
    double get_units();
}
