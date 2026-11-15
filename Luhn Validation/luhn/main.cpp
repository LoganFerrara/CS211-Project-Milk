//Luhn Validation;
// This program reads a card number and checks its format;
#include <iostream>
using namespace std;
//Luhn Validation
//
#include <iostream>
using namespace std;

bool checkLuhn(char cardNumber[], int length)
{
    int sum = 0;
    int digit = 0;

    for (int i = length - 1; i >= 0; i--)
    {
        digit = cardNumber[i] - '0';

        if (i % 2 == 0)
        {
            digit = digit * 2;

                if (digit > 9)
                {
                    digit = digit - 9;
                }
    }
        sum = sum + digit;
    }
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
    
    char cardNumber[100]; //create a c-string with 99 digits and a null character;
    
while (true)
{
    cout << "Enter a 16-digit card number: "; //Ask for digits;
    cin.getline(cardNumber, 100); //cin.getline reads the entire input while keeping the spaces
    
    if (cin.fail())
    {
        cout << "Input is too long." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        continue;
    }
    
    
    int length = 0; 
    bool allDigits = true;

    while (cardNumber[length] != '\0')
    {
        length++;
    }

    
    if(length == 16)
    {
        cout << "Correct length" << endl;
    }
    else
    {
        cout << "Incorrect length" << endl;
    }
    
    for(int i = 0; i < length; i++)
    {
        if (cardNumber[i] < '0' || cardNumber[i] > '9') 
        {
            allDigits = false;
        }
    }
    if (allDigits == true) 
    {
        cout << "Every element in the array is a digit." << endl; //all digit notification;
    } 
    else 
    {
        cout << "The array contains a non-digit character." << endl; //not all digit notification;
    }


    if(length == 16 && allDigits == true) 
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
    char again;
    
    cout << endl;
    cout << "Would you like to check another number? (y/n): ";
    cin >> again;
    cin.ignore(10000, '\n');

    if (again == 'n' || again == 'N')
    {
        break;
    }   
}
    
    return 0;
}
