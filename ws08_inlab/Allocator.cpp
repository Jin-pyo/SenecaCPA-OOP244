#include "SavingsAccount.h" 

namespace sict {

    // define interest rate
    //
#define INTRATE 0.05

    // TODO: Allocator function
    //
    iAccount* CreateAccount(const char* accType, double initBalance)
    {
        bool validType = false;
        iAccount* p;

        if (accType[0] == 'S')
        {
            validType = true;
           p = new SavingsAccount (initBalance, INTRATE);
        }


        return validType ? p : nullptr;
    }







}
