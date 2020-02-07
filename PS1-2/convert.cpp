#include "units.h"
#include <iostream>
#include <fstream>

// Initializes a UnitConverter with conversions from a given file and returns it
UnitConverter init_converter(const string &filename) {
    UnitConverter converter;
    ifstream ifs{filename};

    // Make sure file as opened successfully
    if (!ifs) {
        throw invalid_argument("Couldn't open file");
    }

    // Read conversion data from file until we hit EOF
    while (ifs) {
        string from_units;
        double multiplier;
        string to_units;
        ifs >> from_units >> multiplier >> to_units;

        // May throw invalid_argument exception if conversion already exists
        converter.add_conversion(from_units, multiplier, to_units);
    }

    return converter;
}

/* Main program that asks for a value with units and converts to different
 * units
 */
int main() {
    UnitConverter u;

    try {
        u = init_converter("rules.txt");
    }
    catch (invalid_argument e) {
        cout << e.what() << "\n";
        return 1;
    }

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
