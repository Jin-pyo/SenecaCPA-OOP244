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
        ~Contact();
        bool isEmpty() const;
        void display() const;
    };
}