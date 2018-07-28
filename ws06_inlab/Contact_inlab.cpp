#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include "Contact.h"
using namespace std;

namespace sict
{
    Contact::Contact()
    {
        contactName[0] = '\0';

    }

    Contact::Contact(const char *name, const long long *number, int numAmt)
    {
        int countryCode = 0;
        int areaCode = 0;
        int remainingNums = 0;

        int *valid = nullptr;
        valid = new int[numAmt];


        if (name != nullptr)
        {
            strncpy(contactName, name, 19);
            contactName[19] = '\0';
        }

        //Set name to empty state if invalid
        else
        {
            *contactName = '\0';
        }

        if (number != nullptr)
        {

            for (int i = 0; i < numAmt; i++)
            {
                //Checks if phone number is within 11 or 12 digit range
                if ((number[i] >= 11001000000 && number[i] <= 99999999999) || (number[i] >= 111001000000 && number[i] <= 999999999999))
                {

                    //Isolate potentially invalid digits
                    countryCode = number[i] / (long long)pow(10, 10);
                    areaCode = (number[i] / (long long)pow(10, 9)) % 10;
                    remainingNums = (number[i] / (long long)pow(10, 6)) % 10;


                    // Check if digits are zeros where they shouldn't be (invalid)
                    if (countryCode > 0 && areaCode > 0 && remainingNums > 0)
                    { 
                        //Marker for which index holds a valid number
                        valid[amtOfNums] = i;
                        

                        //Increase number of valid numbers
                        amtOfNums++;

                       
                    }
                }

            }


            //Allocate space for valid numbers and assign
            phoneNum = new long long[amtOfNums];
            int x = 0;

            for (int i = 0; i < numAmt; i++)
            {
                if (valid[x] == i)
                {
                    phoneNum[x] = number[i];
                    x++;
                }
            }
        }
    }

    Contact::~Contact()
    {
        delete[] phoneNum;
    }

    bool Contact::isEmpty() const
    {
        bool empty = false;

        if (*contactName == '\0')
        {
            empty = true;
        }

        return empty;
    }

    void Contact::display() const
    {
        if (isEmpty())
        {
            cout << "Empty contact!" << endl;
        }

        else
        {
            cout << contactName << endl;

            //Check in case there's a name but no number
            if (phoneNum != nullptr)
            {
                for (int i = 0; i < amtOfNums; i++)
                {
                    cout << "(+" << phoneNum[i] / (long long)pow(10, 10) << ") "
                        << (phoneNum[i] / (long)pow(10, 7)) % 1000 << " "
                        << (phoneNum[i] % (long long)pow(10, 7)) / (long long)pow(10, 4)
                        << "-" << setfill('0') << setw(4) << phoneNum[i] % 10000
                        << endl;
                }
            }
        }



        return;
    }
}