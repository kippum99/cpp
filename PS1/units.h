#include <string>

using namespace std;

class UValue {
    double value;
    string units;

public:
    UValue(double value, string units);

    double get_value();
    string get_units();
};
