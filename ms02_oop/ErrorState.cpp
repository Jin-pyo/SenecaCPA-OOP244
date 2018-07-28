#include <iostream>
#include <cstring>
#include "ErrorState.h"

namespace AMA
{
    ErrorState::ErrorState(const char* errorMessage)
    {
        int count = 0;

        if (errorMessage == nullptr)
        {
            errMsg = nullptr;
        }

        else
        {
            // Find number of characters in string
            for (int i = 0; errorMessage[i] != '\0'; i++)
            {
                count++;
            }

            errMsg = new char[count + 1];

            strncpy(errMsg, errorMessage, count);
            errMsg[count] = '\0';
        }
    }

    ErrorState::~ErrorState()
    {
        delete[] errMsg;
    }

    void ErrorState::clear()
    {
        delete[] errMsg;
        errMsg = nullptr;
    }

    bool ErrorState::isClear() const
    {
        bool clear = false;

        if (errMsg == nullptr)
        {
            clear = true;
        }

        return clear;
    }

    void ErrorState::message(const char* str)
    {
        clear();


        int count = 0;

        //Count num of characters in string
        for (int i = 0; str[i] != '\0'; i++)
        {
            count++;
        }

        errMsg = new char[count + 1];
        strncpy(errMsg, str, count);
        errMsg[count] = '\0';

        return;
    }

    const char* ErrorState::message() const
    {
        return errMsg;
    }

    std::ostream& operator << (std::ostream& os, const ErrorState& msgObj)
    {
        if(!(msgObj.isClear()))
        { 
            os << msgObj.message();
        }

            return os;
    }

}