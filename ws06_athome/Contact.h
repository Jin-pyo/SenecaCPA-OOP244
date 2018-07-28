#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <iostream>
using namespace std;

namespace sict
{
    class Contact
    {
        char contactName[20];
        long long *phoneNum = nullptr;
        int amtOfNums = 0;

    public:
        Contact();
        Contact(const char *name, const long long *number, int numAmt);
        Contact(Contact& instance);
        ~Contact();

        bool isEmpty() const;
        void display() const;
        bool isValid(const long long number) const;
        Contact& operator += (const long long phoneNumber);
        Contact& operator = (const Contact& instance);

    };


}

#endif