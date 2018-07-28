// TODO: add file header comments here

// TODO: add header file guard here
#ifndef _PASSENGER_H_
#define _PASSENGER_H_

// TODO: declare your namespace here
namespace sict
{
    class Passenger
    {
    private:
        char passenger_name[32];
        char destination[32];
        int yrDepart;
        int monthDepart;
        int dayDepart;

    public:
        Passenger();
        Passenger(const char *passName, const char *dest);
        Passenger(const char *passName, const char *dest, int yr, int month, int day);
        bool isEmpty() const;
        void display() const;
        const char* name() const;
        bool canTravelWith(const Passenger&) const;
    };


}


// TODO: define the Passenger class here



#endif