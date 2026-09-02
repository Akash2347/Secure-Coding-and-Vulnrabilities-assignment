#include <iostream>
#include <string>
#include <limits>
#include <optional>

using namespace std;

// Safe int -> short
optional<short> safeIntToShort(int value) {
    if (value < numeric_limits<short>::min() ||
        value > numeric_limits<short>::max()) {
        return nullopt;
    }

    return static_cast<short>(value);
}

// Safe signed -> unsigned
optional<unsigned int> safeSignedToUnsigned(int value) {
    if (value < 0) {
        return nullopt;
    }

    return static_cast<unsigned int>(value);
}

// Safe float -> int
optional<int> safeFloatToInt(float value) {
    if (value < numeric_limits<int>::min() ||
        value > numeric_limits<int>::max()) {
        return nullopt;
    }

    return static_cast<int>(value);
}

// Safe string -> int
optional<int> safeStringToInt(const string& text) {
    try {
        size_t position = 0;
        long long value = stoll(text, &position);

        // Make sure the complete string was converted
        if (position != text.length()) {
            return nullopt;
        }

        // Check int range
        if (value < numeric_limits<int>::min() ||
            value > numeric_limits<int>::max()) {
            return nullopt;
        }

        return static_cast<int>(value);
    }
    catch (...) {
        return nullopt;
    }
}

int main() {
    cout << "===== SAFE DATA TYPE CONVERSION =====\n";

    // 1. int -> short
    int largeInt = 40000;

    cout << "\nINT -> SHORT\n";
    cout << "Before: " << largeInt << endl;

    auto shortResult = safeIntToShort(largeInt);

    if (shortResult) {
        cout << "After : " << *shortResult << endl;
    } else {
        cout << "ERROR: Value is outside short range.\n";
    }

    // 2. signed -> unsigned
    int negative = -25;

    cout << "\nSIGNED -> UNSIGNED\n";
    cout << "Before: " << negative << endl;

    auto unsignedResult = safeSignedToUnsigned(negative);

    if (unsignedResult) {
        cout << "After : " << *unsignedResult << endl;
    } else {
        cout << "ERROR: Negative value cannot be converted safely.\n";
    }

    // 3. float -> int
    float decimal = 123.78f;

    cout << "\nFLOAT -> INT\n";
    cout << "Before: " << decimal << endl;

    auto intResult = safeFloatToInt(decimal);

    if (intResult) {
        cout << "After : " << *intResult << endl;
    } else {
        cout << "ERROR: Value is outside int range.\n";
    }

    // 4. Check integer overflow before addition
    int maxInt = numeric_limits<int>::max();

    cout << "\nINTEGER OVERFLOW CHECK\n";
    cout << "Before: " << maxInt << endl;

    if (maxInt == numeric_limits<int>::max()) {
        cout << "ERROR: Adding 1 would cause signed integer overflow.\n";
    } else {
        cout << "After: " << maxInt + 1 << endl;
    }

    // 5. String -> int
    string input = "999999999999999999999";

    cout << "\nSTRING -> INT\n";
    cout << "Before: " << input << endl;

    auto stringResult = safeStringToInt(input);

    if (stringResult) {
        cout << "After : " << *stringResult << endl;
    } else {
        cout << "ERROR: String contains an invalid or out-of-range integer.\n";
    }

    return 0;
}
