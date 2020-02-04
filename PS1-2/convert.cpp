#include "units.h"
#include <iostream>

// Initializes a UnitConverter with basic conversions and returns it
UnitConverter init_converter() {
    UnitConverter converter;
    conerter.add_conversion({"mi", 5280, "ft"});

    return converter;
}

/* Main program that asks for a value with units and converts to different
 * units
 */
int main() {
    UnitConverter u = init_converter();

    // Prompt user for value with units
    double value;
    string units;
    cout << "Enter value with units: ";
    cin >> value >> units;
    UValue v1{value, units};

    // Prompt user for new units
    cout << "Convert to units: ";
    cin >> units;

    // Convert and output result
    try {
        UValue v2 = u.convert_to(v1, units);
        cout << "Converted to: " << v2.get_value() << " "<< units << "\n";
    }
    catch (invalid_argument e) {
        cout << "Couldn't convert to " << units << "!\n"
            << e.what() << "\n";
    }

    return 0;
}
