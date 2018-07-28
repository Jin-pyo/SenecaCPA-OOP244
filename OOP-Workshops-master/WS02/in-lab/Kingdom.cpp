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

}