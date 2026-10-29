//Luhn Validation
//
#include <iostream>
using namespace std;

int main()
{
    char cardNumber[17];

    cout << "Enter a 16-digit card number: ";
    cin >> cardNumber;
    
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
        cout << "Every element in the array is a digit." << endl;
    } 
    else 
    {
        cout << "The array contains a non-digit character." << endl;
    }

    int sum = 0;
    int digit = 0;
    //cout << "Length: " << length << endl;
    
    return 0;
}
