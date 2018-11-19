#include <iostream>
#include <cstring>
using namespace std; 

namespace sict {
    // These numbers define 
    // a) the range of data we expect to see in this workshop
    //    0 to 1 billion
    //    use them in the min and max function
    // b) the output column width for a single data field

    const int LARGEST_NUMBER = 1000000000; // 1,000,000,000
    const int SMALLEST_NUMBER = 0;
    const int COLUMN_WIDTH = 15;

    template <typename T>
    // max returns the largest item in data
    //
    T max(const T* data, int n)
    {
        T largest = SMALLEST_NUMBER;

        for (int i = 0; i < n; i++)
        {
            if (data[i] > largest)
            {
                largest = data[i];
            }
        }

        return largest;
    }

    // min returns the smallest item in data
    //
    template <typename T>
    T min(const T* data, int n)
    {
        T lowest = LARGEST_NUMBER;

        for (int i = 0; i < n; i++)
        {
            if (data[i] < lowest)
            {
                lowest = data[i];
            }
        }

        return lowest;
    }

    // sum returns the sum of n items in data
    //    
    template <typename T>
    T sum(const T* data, int n)
    {
        T total = 0.0;

        for (int i = 0; i < n; i++)
        {
            total += data[i];
        }

        return total;
    }

    // average returns the average of n items in data
    //
    template <typename T>
    double avg(const T* data, int n)
    {
        double average = (sum(data, n)) / n;

        return average;
    }

    // read extracts n items from input and stores them in data
    // - the items are comma separated
    // - this function assumes that a comma exists at the next field to be read
    // - for example: ,data1, data2,data3, ...., datan
    //
    template <typename T>
    bool read(std::istream& input, T* data, int n)
    {
        bool success = true;

        for (int i = 0; i < n; i++)
        {
            input.ignore();
            input >> data[i];

            if (input.fail())
            {
                success = false;
                i = n;
            }
        }

        return success;
    }

    // display inserts n items of data into std::cout
    //
    template <typename T>
    void display(const char* name, const T* data, int n)
    {
        cout.width(COLUMN_WIDTH + 5);
        cout.setf(ios::right);
        cout << name;

        for (int i = 0; i < n; i++)
        {
            cout.width(COLUMN_WIDTH);
            cout << data[i];
        }

        cout << endl;

        return;
    }

    template <typename T>
    // readRow extracts a single record from input and stores n data fields in data
    // - includes error checking: checks if the name of the row is valid.
    //
    bool readRow(std::istream& input, const char* name, T* data, int n) {
        char rowname[2000];
        bool ok = !input.bad();

        // row format is 
        // name,1,2,3,4,5,6

        if (ok) {
            // read the name  first
            input.get(rowname, 2000, ',');

            // note: get will read a string upto the , character
            // it will leave the , character in the input buffer 

            // check that the caller is reading the correct row (name)
            // - if the user is reading the wrong row, return an error
            if (std::strcmp(rowname, name) != 0) {
                // wrong row
                std::cout << "Cannot parse row for " << name << std::endl;
                input.ignore(2000, '\n');
                ok = false;
            }
        }

        if (ok)
            // read the data array
            ok = read(input, data, n);

        // finish the line
        input.ignore(2000, '\n');
        return ok;
    }

    void answers(const int*, const int*, const int*, const double*, const int*, const int n);

}

