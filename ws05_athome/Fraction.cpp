#include <iostream>

// TODO: insert header files
#include "Fraction.h"
using namespace std;

// TODO: continue the namespace
namespace sict
{
    // TODO: implement the default constructor
    Fraction::Fraction()
    {
        numerator = -1;
        denominator = 0;
    }

    // TODO: implement the two-argument constructor
    Fraction::Fraction(int numDigit, int denomDigit)
    {

        if (numDigit >= 0 && denomDigit > 0)
        {
            numerator = numDigit;
            denominator = denomDigit;
        }

        else
        {
            numerator = -1;
            denominator = 0;
        }

        reduce();
    }


    // TODO: implement the max query
    int Fraction::max() const
    {
        int greater;

        if (denominator > numerator)
        {
            greater = denominator;
        }

        else
        {
            greater = numerator;
        }

        return greater;
    }

    // TODO: implement the min query
    int Fraction::min() const
    {
        int lesser;

        if (denominator < numerator)
        {
            lesser = denominator;
        }

        else
        {
            lesser = numerator;
        }

        return lesser;
    }

    // gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // TODO: implement the reduce modifier
    void Fraction::reduce()
    {
        int greatestDenom = gcd();
        numerator /= greatestDenom;
        denominator /= greatestDenom;

        return;
    }

    // TODO: implement the display query
    void Fraction::display() const
    {

        if (isEmpty())
        {
            cout << "no fraction stored";
        }

        else if (denominator != 1)
        {
            cout << numerator << "/" << denominator;
        }

        else
        {
            cout << numerator;
        }

        return;
    }

    // TODO: implement the isEmpty query
    bool Fraction::isEmpty() const
    {
        bool empty = true;

        if (numerator >= 0 && denominator > 0)
        {
            empty = false;
        }

        return empty;
    }

    // TODO: implement the + operator
    Fraction Fraction::operator+ (const Fraction& rhs) const
    {
        Fraction copy;

        if (!this->isEmpty() && !rhs.isEmpty())
        {
            copy.numerator = this->numerator*rhs.denominator + rhs.numerator*this->denominator;
            copy.denominator = this->denominator * rhs.denominator;
        }

        return copy;
    }

    Fraction Fraction::operator* (const Fraction& rhs) const
    {
        Fraction copy;

        if (!this->isEmpty() && !rhs.isEmpty())
        {
            copy.numerator = this->numerator * rhs.numerator;
            copy.denominator = this->denominator * rhs.denominator;

            copy.reduce();
        }

        return copy;
    }

    bool Fraction::operator== (const Fraction& rhs) const
    {
        bool equal = false;

        if (!this->isEmpty() && !rhs.isEmpty())
        {
            if (this->numerator == rhs.numerator)
            {
                if (this->denominator == rhs.denominator)
                {
                    equal = true;
                }
            }
        }

        return equal;
    }

    bool Fraction::operator!= (const Fraction& rhs) const
    {
        bool notEqual = false;

        if (!this->isEmpty() && !rhs.isEmpty())
        {
            if (!(*this == rhs))
            {
                notEqual = true;
            }
        }

        return notEqual;
    }

    Fraction Fraction::operator+= (const Fraction& rhs)
    {
        *this = *this + rhs;
        this->reduce();

        return *this;
    }
}