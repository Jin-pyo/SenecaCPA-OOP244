#ifndef _CRA_ACCT_
#define _CRA_ACCT_

#include <iostream>
#include <iomanip>
#include <cstring>
#include "CRA_Account.h"

using namespace std;


namespace sict
{

    void CRA_Account::set(const char* familyName, const char* givenName, int sin)
    {
        int invalid = 0;

        if (*familyName == '\0' || *givenName == '\0')
        {
            invalid = 1;
        }

        else
        {
            if (sin <= max_sin && sin >= min_sin && invalid == 0)
            {
                // Copy sin number into array format
                int sinArrCpy[9];
                int x = 1;

                for (int i = 8; i >= 0; i--)
                {
                    sinArrCpy[i] = (sin % (10 * x)) / x;
                    x *= 10;
                }


                // Check if sin digits follow the rules and add up correctly
                // Separate digits into correct "categories"
                int firstSet[4] = { sinArrCpy[1], sinArrCpy[3], sinArrCpy[5], sinArrCpy[7] };
                int secondSet[4] = { sinArrCpy[0], sinArrCpy[2], sinArrCpy[4], sinArrCpy[6] };
                int checkDigit = sinArrCpy[8];
                int sinTotal = 0;


                // Finding the total of the first 8 digits
                for (int i = 0; i < 4; i++)
                {
                    // First set
                    if (firstSet[i] > 5)
                    {
                        sinTotal += (firstSet[i] * 2) % 10;
                        sinTotal++;
                    }

                    else if (firstSet[i] == 5)
                    {
                        sinTotal++;
                    }

                    else
                    {
                        sinTotal += firstSet[i] * 2;
                    }

                    // Second set
                    sinTotal += secondSet[i];
                }

                if (checkDigit == (10 - sinTotal % 10))
                {
                    strncpy(famName, familyName, max_name_length);
                    strncpy(acctName, givenName, max_name_length);
                    sinNum = sin;

                }

                else
                {
                    invalid = 1;
                }
            }
        }


        if (invalid)
        {
            strncpy(famName, "NO_NAME", max_name_length);
            strncpy(acctName, "NO_NAME", max_name_length);
            sinNum = 1;
        }

        return;
    }

    void CRA_Account::set(int year, double balance)
    {
        int flag = 1;
        
        for (int i = 0; i < max_yrs; i++)
        {
            if (flag)
            {
                if (!isEmpty() && taxReturnYrs[i] == 0)
                {
                    taxReturnYrs[i] = year;
                    yearlyBalance[i] = balance;
                    flag = 0;
                }
            }
        }

        return;
    }

    bool CRA_Account::isEmpty() const
    {
        bool empty = true;

        if (CRA_Account::sinNum <= max_sin && CRA_Account::sinNum >= min_sin)
        {
            empty = false;

        }


        return empty;
    }

    void CRA_Account::display() const
    {

        if (isEmpty())
        {
            cout << "Account object is empty!" << endl;
        }

        else
        {
            cout << "Family Name: " << famName << endl
                << "Given Name : " << acctName << endl
                << "CRA Account: " << sinNum << endl;

            for (int i = 0; i < max_yrs; i++)
            {
                cout << setprecision(2) << fixed;

                if (yearlyBalance[i] > 2)
                {

                    cout << "Year (" << taxReturnYrs[i] << ") balance owing: " << yearlyBalance[i] << endl;
                }

                else if (yearlyBalance[i] < -2)
                {
                    cout << "Year (" << taxReturnYrs[i] << ") refund due: " << (yearlyBalance[i]*-1) << endl;
                }

                else
                {
                    cout << "Year (" << taxReturnYrs[i] << ") No balance owing or refund due!" << endl;
                }
            }
        }
        return;
    }
};

#endif