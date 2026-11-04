//Luhn Validation;
// This program reads a card number and checks its format;
#include <iostream>
using namespace std;

int main()
{
    char cardNumber[17];                                  //create a c-string with 16 digits and a null character;

    cout << "Enter a 16-digit card number: ";             //Ask for digits;
    cin >> cardNumber;                                    //record digits;
    
    int length = 0;                                       //character count;
    bool allDigits = true;                                //input digit only check;

    while (cardNumber[length] != '\0')                    //lenght verification, add 1 to length until ('0/');
    {
        length++;
    }
    
    if(length == 16)                                      //correct length  notification;
    {
        cout << "Correct length" << endl;
    }
    else                                                  
    {
        cout << "Incorrect length" << endl;               //incorrect length notification (length /= 16);
    
    for(int i = 0; i < length; i++)
    {
        if (cardNumber[i] < '0' || cardNumber[i] > '9')   //for loop checks from 0 toi length-1 individually;
        {
            allDigits = false;                            //checks for that only digits are present;
        }
    }
    if (allDigits == true) 
    {
        cout << "Every element in the array is a digit." << endl;       //all digit notification;
    } 
    else 
    {
        cout << "The array contains a non-digit character." << endl;    //not all digit notification;
    }

    int sum = 0;
    int digit = 0;
    cout << "Length: " << length << endl;
    
    return 0;
}
