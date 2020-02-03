#include "units.h"
#include <iostream>

// Main program that asks for a value with units and converts to different
// units
int main() {
    double value;
    string units;

    // Prompt user for value with units
    cout << "Enter value with units: ";
    cin >> value >> units;
    UValue v1{value, units};

    // Prompt user for new units
    cout << "Convert to units: ";
    cin >> units;
    UValue v2 = convert_to(v1, units);

    // Output result
    if (v2.get_units() == units) {
        cout << "Converted to: " << v2.get_value() << " "<< units << "\n";
    }
    else {
        cout << "Couldn't convert to " << units << "!\n";
    }

    return 0;
}
