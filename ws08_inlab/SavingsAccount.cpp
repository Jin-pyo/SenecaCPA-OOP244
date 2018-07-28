#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"

namespace sict
{
    SavingsAccount::SavingsAccount(double initBalance, double rate)
    {
        if (initBalance > 0)
        {
            currentBalance = initBalance;
        }

        else
        {
            currentBalance = 0.0;
        }

        if (rate > 0)
        {
            intRate = rate;
        }

        else
        {
            intRate = 0.0;
        }

    }

    void SavingsAccount::monthEnd()
    {
        currentBalance *= (intRate + 1);
        return;
    }

    void SavingsAccount::display(std::ostream& os) const
    {
        os << "Account type: Savings" << std::endl
            << std::fixed << std::setprecision(2)
            << "Balance: $" << currentBalance << std::endl
            << "Interest Rate (%): " << intRate * 100 << std::endl;

        return;
    }
}
