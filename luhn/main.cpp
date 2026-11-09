

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Check that the input contains exactly 16 digits
bool isValidFormat(const string& number) {
    if (number.length() != 16) {
        return false;
    }

    for (char digit : number) {
        if (!isdigit(static_cast<unsigned char>(digit))) {
            return false;
        }
    }

    return true;
}

// Check the Luhn algorithm
bool checkLuhn(const string& number) {
    int sum = 0;
    bool doubleDigit = false;

    // Start from the rightmost digit
    for (int i = static_cast<int>(number.length()) - 1; i >= 0; i--) {
        int digit = number[i] - '0';

        if (doubleDigit) {
            digit *= 2;

            if (digit > 9) {
                digit -= 9;
            }
        }

        sum += digit;
        doubleDigit = !doubleDigit;
    }

    return (sum % 10 == 0);
}

int main() {
    string number;
    char again;

    do {
        cout << "Enter a 16-digit number: ";
        getline(cin, number);

        if (!isValidFormat(number)) {
            cout << "Invalid input! Please enter exactly 16 digits."
                 << endl;
        }
        else if (checkLuhn(number)) {
            cout << "The number passes the Luhn check!" << endl;
        }
        else {
            cout << "The number fails the Luhn check!" << endl;
        }

        cout << "Do you want to check another number? (y/n): ";
        cin >> again;
        cin.ignore(10000, '\n');

    } while (again == 'y' || again == 'Y');

    cout << "Goodbye!" << endl;

    return 0;
}
