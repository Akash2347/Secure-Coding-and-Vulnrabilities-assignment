#include <iostream>
#include <string>
#include <limits>
#include <optional>

using namespace std;

optional<short> safeIntToShort(int value) {
    if (value < numeric_limits<short>::min() ||
        value > numeric_limits<short>::max()) {
        return nullopt;
    }

    return static_cast<short>(value);
}

optional<unsigned int> safeSignedToUnsigned(int value) {
    if (value < 0) {
        return nullopt;
    }

    return static_cast<unsigned int>(value);
}

optional<int> safeFloatToInt(float value) {
    if (value < numeric_limits<int>::min() ||
        value > numeric_limits<int>::max()) {
        return nullopt;
    }

    return static_cast<int>(value);
}

optional<int> safeStringToInt(const string& text) {
    try {
        size_t position = 0;
        long long value = stoll(text, &position);

        if (position != text.length()) {
            return nullopt;
        }

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

    int largeInt = 40000;

    cout << "\nINT -> SHORT\n";
    cout << "Before: " << largeInt << endl;

    auto shortResult = safeIntToShort(largeInt);

    if (shortResult) {
        cout << "After : " << *shortResult << endl;
    } else {
        cout << "ERROR: Value is outside short range.\n";
    }

    int negative = -25;

    cout << "\nSIGNED -> UNSIGNED\n";
    cout << "Before: " << negative << endl;

    auto unsignedResult = safeSignedToUnsigned(negative);

    if (unsignedResult) {
        cout << "After : " << *unsignedResult << endl;
    } else {
        cout << "ERROR: Negative value cannot be converted safely.\n";
    }

    float decimal = 123.78f;

    cout << "\nFLOAT -> INT\n";
    cout << "Before: " << decimal << endl;

    auto intResult = safeFloatToInt(decimal);

    if (intResult) {
        cout << "After : " << *intResult << endl;
    } else {
        cout << "ERROR: Value is outside int range.\n";
    }

    int maxInt = numeric_limits<int>::max();

    cout << "\nINTEGER OVERFLOW CHECK\n";
    cout << "Before: " << maxInt << endl;

    if (maxInt == numeric_limits<int>::max()) {
        cout << "ERROR: Adding 1 would cause signed integer overflow.\n";
    } else {
        cout << "After: " << maxInt + 1 << endl;
    }

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
