// Luhn Card Number Validator
//   Reads a card number and runs three checks:
//     1. Length - must be exactly 16 characters
//     2. Digits - every character must be 0-9
//     3. Luhn   - the checksum must be divisible by 10
//   The user can keep entering numbers until they answer 'n'.

#include <iostream>   // cin, cout, endl
using namespace std;
// Check Luhn
// Purpose:  Applies the Luhn algorithm to a string of digits.
// Paramiter:   cardNumber - C-string holding the digit characters
//           length     - number of characters in cardNumber
// Gives:  true if the checksum is divisible by 10, else false
// Assumes:  every character is a digit and length is 16
//           (the i % 2 test only picks the right digits to
//            double when the length is even)

bool checkLuhn(char cardNumber[], int length)
{
    int sum = 0;                                                                // running total of all adjusted digits
    int digit = 0;                                                              // numeric value of the current character

                                                                                // Walk from the last character to the first (right to left)
    for (int i = length - 1; i >= 0; i--)
    {
                                                                                // Convert the character to its number: '7' - '0' = 7
        digit = cardNumber[i] - '0';

                                                                                // Even indexes (14, 12, ... 0) are the digits that get doubled
        if (i % 2 == 0)
        {
            digit = digit * 2;

                                                                                // A doubled digit above 9 has two digits, so add them together.
                                                                                // Subtracting 9 does the same thing (14 -> 1 + 4 = 5 = 14 - 9)
            if (digit > 9)
            {
                digit = digit - 9;
            }
        }
        sum = sum + digit;                                                      // add this digit (doubled or not) to the total
    }

                                                                                // The number is valid when the total ends in 0
    if (sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
                                                                                // C-string with room for 99 characters plus the null terminator '\0'
    char cardNumber[100];

    while (true)                                                                // repeat until the user chooses to quit
    {
                                                                                // ---------- Step 1: read the input ----------
        cout << "Enter a 16-digit card number: ";
        cin.getline(cardNumber, 100);                                           // reads the whole line, spaces included

                                                                                // More than 99 characters sets the fail flag:
                                                                                // reset cin, discard the rest of the line, and ask again
        if (cin.fail())
        {
            cout << "Input is too long." << endl;
            cin.clear();                                                        // reset the error state
            cin.ignore(10000, '\n');                                            // discard leftover characters
            continue;                                                           // back to the top of the loop
        }

                                                                                // ---------- Step 2: measure the length ----------
        int length = 0;
        bool allDigits = true;                                                  // stays true unless a non-digit is found

                                                                                // Count characters until the null terminator
        while (cardNumber[length] != '\0')
        {
            length++;
        }

                                                                                // ---------- Step 3: length check (report only) ----------
        if (length == 16)
        {
            cout << "Correct length" << endl;
        }
        else
        {
            cout << "Incorrect length" << endl;
        }

                                                                                // ---------- Step 4: digit check ----------
                                                                                // A digit character is always between '0' and '9'
        for (int i = 0; i < length; i++)
        {
            if (cardNumber[i] < '0' || cardNumber[i] > '9')
            {
                allDigits = false;
            }
        }
        if (allDigits == true)
        {
            cout << "Every element in the array is a digit." << endl;
        }
        else
        {
            cout << "The array contains a non-digit character." << endl;
        }

                                                                                // ---------- Step 5: Luhn check ----------
                                                                                // Only run Luhn if BOTH checks passed, because checkLuhn
                                                                                // assumes 16 digit characters
        if (length == 16 && allDigits == true)
        {
            if (checkLuhn(cardNumber, length))
            {
                cout << "Card number passes Luhn validation." << endl;
            }
            else
            {
                cout << "Card number fails Luhn validation." << endl;
            }
        }
        else
        {
            cout << "Invalid card number. Please enter exactly 16 digits." << endl;
        }

                                                                                // ---------- Step 6: ask whether to repeat ----------
        char again;

        cout << endl;
        cout << "Would you like to check another number? (y/n): ";
        cin >> again;
        cin.ignore(10000, '\n');   // clear the leftover newline for the next getline

                                                                                // 'n' or 'N' ends the program; any other answer repeats it
        if (again == 'n' || again == 'N')
        {
            break;
        }
    }

    return 0;   
}
