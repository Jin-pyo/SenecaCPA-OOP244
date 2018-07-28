#include <iostream>

#include "iAccount.h"
#include "Account.h"

namespace sict
{
    Account::Account(double p_balance)
    {
        if (p_balance > 0)
        {
            currentBalance = p_balance;
        }

        else
        {
            currentBalance = 0.0;
        }
    }

    bool Account::credit(double p_credit)
    {
        bool valid = false;

        if (p_credit > 0)
        {
            valid = true;
            currentBalance += p_credit;
        }

        return valid;
    }

    bool Account::debit(double p_debit)
    {
        bool valid = false;

        if (p_debit > 0)
        {
            valid = true;
            currentBalance -= p_debit;
        }

        return valid;
    }

    double Account::balance() const
    {
        return currentBalance;
    }
}