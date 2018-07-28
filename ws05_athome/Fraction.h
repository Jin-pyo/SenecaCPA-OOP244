// TODO: header file guard

// TODO: create namespace
namespace sict
{
    // TODO: define the Fraction class
    class Fraction {
        // TODO: declare instance variables 
        int numerator;
        int denominator;

        // TODO: declare private member functions
        int max() const;
        int min() const;
        void reduce();
        int gcd() const;

    public:
        // TODO: declare public member functions
        Fraction();
        Fraction(int numDigit, int denomDigit);
        bool isEmpty() const;
        void display() const;

        // TODO: declare operator overloads
        Fraction operator+ (const Fraction& rhs) const;
        Fraction operator* (const Fraction& rhs) const;
        bool operator== (const Fraction& rhs) const;
        bool operator!= (const Fraction& rhs) const;
        Fraction operator+= (const Fraction& rhs);

    };
}

