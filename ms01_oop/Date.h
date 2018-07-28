// Final Project Milestone 1
//
// Version 1.0
// Date     JULY 2018
// Author   TRACY NGUYEN
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H

#include <iostream>

namespace AMA {

    const int min_year = 2000;
    const int max_year = 2030;

    class Date {

#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4


        int mdays(int month, int year)const;
        void errCode(int errorCode);


        int year;
        int month;
        int day;
        int comparator;
        int errState;


    public:
        Date();
        Date(int year, int month, int day);

        bool operator == (const Date& rhs) const;
        bool operator != (const Date& rhs) const;
        bool operator < (const Date& rhs) const;
        bool operator > (const Date& rhs) const;
        bool operator <= (const Date& rhs) const;
        bool operator >= (const Date& rhs) const;

        int errCode() const;
        bool bad() const;

        std::istream& read(std::istream& str);
        std::ostream& write(std::ostream& ostr) const;

        bool isValid(int yr, int month, int day);



    };


    std::ostream& operator << (std::ostream&, Date&);
    std::istream& operator >> (std::istream&, Date&);


}

#endif