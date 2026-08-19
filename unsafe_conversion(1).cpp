#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    int largeInt = 40000;
    short smallShort = (short)largeInt;

    cout << "INT -> SHORT\n";
    cout << "Before: " << largeInt << endl;
    cout << "After : " << smallShort << endl;

    int negative = -25;
    unsigned int positive = (unsigned int)negative;

    cout << "\nSIGNED -> UNSIGNED\n";
    cout << "Before: " << negative << endl;
    cout << "After : " << positive << endl;

    float decimal = 123.78f;
    int number = (int)decimal;

    cout << "\nFLOAT -> INT\n";
    cout << "Before: " << decimal << endl;
    cout << "After : " << number << endl;

    int maxInt = numeric_limits<int>::max();

    cout << "\nINTEGER OVERFLOW\n";
    cout << "Before: " << maxInt << endl;

    int overflow = maxInt + 1;

    cout << "After : " << overflow << endl;

    string input = "999999999999999999999";

    try {
        int value = stoi(input);
        cout << "\nSTRING -> INT\n";
        cout << "Before: " << input << endl;
        cout << "After : " << value << endl;
    }
    catch (...) {
        cout << "\nString conversion failed or value is out of range."
             << endl;
    }

    return 0;
}
