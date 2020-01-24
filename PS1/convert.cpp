#include "units.h"
#include <iostream>

int main() {
    double value;
    string units;

    cout << "Enter value with units: ";
    cin >> value >> units;
    UValue v1{value, units};

    cout << "Convert to units: ";
    cin >> units;
    UValue v2 = convert_to(v1, units);

    if (v2.get_units() == units) {
        cout << "Converted to: " << v2.get_value() << " "<< units << "\n";
    }
    else {
        cout << "Couldn't convert to " << units << "!\n";
    }

    return 0;
}
