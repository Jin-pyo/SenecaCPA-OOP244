#include <iostream>
#include <cstring>
#include <iomanip>
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
        yrDepart = 0;
        monthDepart = 0;
        dayDepart = 0;
    }

    Passenger::Passenger(const char *passName, const char *dest)
    {
        int flag = 1;

        if (passName != '\0' && passName != nullptr)
        {
            if ((dest != '\0')  && dest != nullptr)
            {
                // set passenger name
                strncpy(passenger_name, passName, 32);
                passenger_name[31] = '\0';

                // set destination
                strncpy(destination, dest, 32);
                destination[31] = '\0';

                // set date
                yrDepart = 2017;
                monthDepart = 7;
                dayDepart = 1;

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

    Passenger::Passenger(const char *passName, const char *dest, int yr, int month, int day)
    {
        int flag = 1;

        if ((yr >= 2017 && yr <= 2020) && (month >= 1 && month <= 12) && (day >= 1 && day <= 31))
        {
            if (passName != '\0' && passName != nullptr)
            {
                if ((dest != '\0') && dest != nullptr)
                {
                    // set passenger name
                    strncpy(passenger_name, passName, 32);
                    passenger_name[31] = '\0';

                    // set destination
                    strncpy(destination, dest, 32);
                    destination[31] = '\0';

                    // set date
                    yrDepart = yr;
                    monthDepart = month;
                    dayDepart = day;

                    flag = 0;
                }
            }
        }

        // Invalid data so object is set to safe empty state
        if (flag)
        {
            *passenger_name = '\0';
            *destination = '\0';

            yrDepart = 0;
            monthDepart = 0;
            dayDepart = 0;
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
        cout << setw(2) << setfill('0');

        if (!isEmpty())
        {
            cout << passenger_name << " - " << destination << " on " << yrDepart << "/" << setw(2) << setfill('0') << monthDepart << "/" << dayDepart << endl;
        }
        
        else
        {
            cout << "No passenger!" << endl;
        }

        return;
    }

    const char* Passenger::name() const
    {
        return this->passenger_name;
    }


    bool Passenger::canTravelWith(const Passenger& passenger) const
    {
        bool canTravel = false;


        if ((strcmp(this->destination, passenger.destination)) == 0)
        {
            if (this->yrDepart == passenger.yrDepart && this->monthDepart == passenger.monthDepart && this->dayDepart == passenger.dayDepart)
            {
                canTravel = true;
            }
        }
        
        
        return canTravel;
    }

}

