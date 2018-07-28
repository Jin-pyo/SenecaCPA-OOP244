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

    public:
        Passenger();
        Passenger(const char *pName, const char *dest);
        bool isEmpty() const;
        void display() const;
    };


}


// TODO: define the Passenger class here



#endif