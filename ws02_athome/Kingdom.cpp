/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date: May 2018
// Author: Tracy Nguyen
***********************************************************/


// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"

using namespace std;


namespace sict
{

    void display(const struct Kingdom name)
    {

        cout << name.m_name << ", population " << name.m_population << endl;
        return;

    }

   
    void display(const struct Kingdom *name, int num)
    {
        cout << "------------------------------" << endl
            << "Kingdoms of SICT" << endl
            << "------------------------------" << endl;

        int totalpop = 0;

        for (int i = 0; i < num; i++)
        {
            cout << i + 1 << ". " << name[i].m_name << ", population " << name[i].m_population << endl;
            totalpop += name[i].m_population;

        }

        cout << "------------------------------" << endl
            << "Total population of SICT: " << totalpop << endl
            << "------------------------------" << endl;

        return;
    }
    
}