#include <string>

using namespace std;

// A united-value class
class UValue {
    double value;   // value itself
    string units;   // units for the value

public:
    UValue(double value, string units);

    double get_value();
    string get_units();
};

UValue convert_to(UValue input, string to_units);
