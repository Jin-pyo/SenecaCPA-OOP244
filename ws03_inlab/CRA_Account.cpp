

#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;


namespace sict
{

    void CRA_Account::set(const char* familyName, const char* givenName, int sin)
    {
        if (familyName[0] != '\0' || givenName[0] != '\0')
        {
            if (sin <= max_sin && sin >= min_sin)
            {
                strncpy(famName, familyName, max_name_length);
                strncpy(acctName, givenName, max_name_length);
                sinNum = sin;
                returnData = 0;
            }
        }
            else
            {

                strncpy(famName, "NO_NAME", max_name_length);
                strncpy(acctName, "NO_NAME", max_name_length);
                sinNum = 1;

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
            if (balance > 2)
            {
                cout << "Family Name: " << famName << endl
                    << "Given Name : " << acctName << endl
                    << "CRA Account: " << sinNum << endl
                    << "Year (" << year << ") refund due: " << amount << endl;
            }
        }

        return;
    }
};
