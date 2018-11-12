// Final Project Milestone 1
//
// Version 1.0
// Date         JULY 2018
// Author       TRACY NGUYEN
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iomanip>
#include "Date.h"

namespace AMA {

    // number of days in month mon_ and year year_
    //
    int Date::mdays(int mon, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int month = mon >= 1 && mon <= 12 ? mon : 13;
        month--;
        return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

    bool Date::isValid(int year_param, int month_param, int day_param)
    {
        bool valid = false;

        errState = YEAR_ERROR;

        if (year_param >= min_year && year_param <= max_year)
        {
            errState = MON_ERROR;

            if (month_param >= 1 && month_param <= 12)
            {
                errState = DAY_ERROR;

                if (day_param >= 1 && day_param <= mdays(month_param, year_param))
                {
                    errState = NO_ERROR;
                    valid = true;
                }
            }
        }

        return valid;

    }

    Date::Date()
    {
        year = 0000;
        month = 00;
        day = 00;

        comparator = 0;
        errState = NO_ERROR;
    }

    Date::Date(int year_param, int month_param, int day_param)
    {
        if (isValid(year_param, month_param, day_param))
        {
            year = year_param;
            month = month_param;
            day = day_param;

            comparator = year * 372 + month * 13 + day;
        }


        if (errState != NO_ERROR)
        {
            year = 0000;
            month = 00;
            day = 00;

            comparator = 0;
        }


    }

    bool Date::operator == (const Date& rhs) const
    {
        bool equal = false;

        if (comparator != 0 || rhs.comparator != 0)
        {
            if (comparator == rhs.comparator)
            {
                equal = true;
            }
        }

        return equal;
    }

    bool Date::operator != (const Date& rhs) const
    {
        bool notEqual = false;

        if (!(*this == rhs))
        {
            notEqual = true;
        }

        return notEqual;
    }

    bool Date::operator < (const Date& rhs) const
    {
        bool less = false;

        if (comparator != 0 || rhs.comparator != 0)
        {
            if (comparator < rhs.comparator)
            {
                less = true;
            }
        }

        return less;
    }

    bool Date::operator  > (const Date& rhs) const
    {
        bool greater = false;

        if (!(*this < rhs))
        {
            greater = true;
        }

        return greater;
    }

    bool Date::operator <= (const Date& rhs) const
    {
        bool lessEqual = false;

        if ((*this < rhs) || (*this == rhs))
        {
            lessEqual = true;
        }

        return lessEqual;
    }

    bool Date::operator >= (const Date& rhs) const
    {
        bool greaterEqual = false;

        if ((*this > rhs) || (*this == rhs))
        {
            greaterEqual = true;
        }

        return greaterEqual;
    }

    void Date::errCode(int errorCode)
    {
        errState = errorCode;
        return;
    }

    int Date::errCode() const
    {
        return errState;
    }

    bool Date::bad() const
    {
        bool bad = false;

        if (errState != NO_ERROR)
        {
            bad = true;
        }

        return bad;
    }

    std::istream& Date::read(std::istream& istr)
    {

        char slash;
        int year_param;
        int month_param;
        int day_param;

        istr >> year_param >> slash >> month_param >> slash >> day_param;

        if (!(istr.fail()))
        {
            if (isValid(year_param, month_param, day_param))
            {
                year = year_param;
                month = month_param;
                day = day_param;
            }
        }

        else
        {
            errState = CIN_FAILED;
        }

        return istr;

    }

    std::ostream& Date::write(std::ostream& ostr) const
    {
        ostr << year << '/' << std::setfill('0') << std::setw(2) << month << '/' << std::setfill('0') << std::setw(2) << day;
        return ostr;
    }

    std::ostream& operator << (std::ostream& os, Date& obj)
    {
        obj.write(os);
        return os;
    }

    std::istream& operator >> (std::istream& is, Date& obj)
    {
        obj.read(is);
        return is;
    }

    void Date::operator= (const Date& rhs)
    {
        year = rhs.year;
        month = rhs.month;
        day = rhs.day;

        return;
    }

}
