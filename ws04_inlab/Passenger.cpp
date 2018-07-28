#include <iostream>
#include <cstring>
#include "Passenger.h"
using namespace std;


// TODO: add file header comments here

// TODO: add your headers here


// TODO: continue your namespace here
namespace sict
{
    Passenger::Passenger()
    {
        *passenger_name = '\0';
        *destination = '\0';
    }

    Passenger::Passenger(const char *passName, const char *dest)
    {
        int flag = 1;

        if (passName != '\0' && passName != nullptr)
        {
            if ((dest != '\0')  && dest != nullptr)
            {
                strncpy(passenger_name, passName, 32);
                strncpy(destination, dest, 32);
                flag = 0;
            }
        }

        // Invalid data so object is set to safe empty state
        if (flag)
        {
            *passenger_name = '\0';
            *destination = '\0';
        }
    }

    bool Passenger::isEmpty() const
    {
        bool empty = true;

        if (*passenger_name != '\0' && passenger_name != nullptr)
        {
            if (*destination != '\0' && destination != nullptr)
            {
                empty = false;
            }
        }
        
        return empty;
    }

    void Passenger::display() const
    {
        if (!isEmpty())
        {
            cout << passenger_name << " - " << destination << endl;
        }
        
        else
        {
            cout << "No passenger!" << endl;
        }

        return;
    }
}

