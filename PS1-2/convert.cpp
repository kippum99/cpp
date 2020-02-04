#include "units.h"
#include <iostream>

// Initializes a UnitConverter with basic conversions and returns it
UnitConverter init_converter() {
    UnitConverter converter;

    converter.add_conversion("mi", 5280, "ft");
    converter.add_conversion("mi", 1.6, "km");
    converter.add_conversion("mi", 12, "in");
    converter.add_conversion("in", 2.54, "cm");

    converter.add_conversion("lb", 0.45, "kg");
    converter.add_conversion("stone", 14, "lb");
    converter.add_conversion("lb", 16, "oz");

    converter.add_conversion("gal", 3.79, "L");
    converter.add_conversion("bushel", 9.3, "gal");
    converter.add_conversion("ft^3", 7.5, "gal");
    converter.add_conversion("L", 1000, "ml");

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
