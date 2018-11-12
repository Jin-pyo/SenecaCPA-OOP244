#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <iostream>
#include "ErrorState.h"
#include "iProduct.h"


namespace AMA {
    const int max_sku_length = 7;
    const int max_unit_length = 10;
    const int max_name_length = 75;
    const double taxRate = 0.13;

    class Product : public iProduct {
        char prodType;
        char prodSku[max_sku_length + 1];
        char prodUnit[max_unit_length + 1];
        char * prodName;
        int qtyOnHand;
        int qtyReq;
        double priceBefore;
        bool taxable;

    protected:
        void name(const char*);
        const char* name() const;
        const char* sku() const;
        const char* unit() const;
        bool taxed() const;
        double price() const;
        double cost() const;
        void message(const char*);
        bool isClear() const;
        ErrorState errObj;

    public:

        Product(char prodType = 'N');
        Product(const char* prodSku, const char* prodName, const char* prodUnit, int qtyOnHand = 0, bool tax = true, double prodPrice = 0.0, int qtyNeed = 0);
        Product(const Product& p_prod);
        ~Product();

        std::fstream& store(std::fstream& file, bool newLine = true) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear) const;
        std::istream& read(std::istream& is);

        Product& operator= (const Product&);
        bool operator==(const char*) const;
        double total_cost() const;
        void quantity(int);
        bool isEmpty() const;
        int qtyNeeded() const;
        int quantity() const;
        bool operator>(const char*) const;
        int operator+=(int);

        bool operator > (const iProduct&) const;


    };

    std::ostream& operator<< (std::ostream&, const iProduct&);
    std::istream& operator>> (std::istream&, iProduct&);
    double operator +=(double&, const iProduct&);
}

#endif