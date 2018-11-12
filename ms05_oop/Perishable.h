#ifndef _PERISHABLE_H_
#define _PERISHABLE_H_

#include <iostream>

#include "Product.h"
#include "Date.h"

namespace AMA {

    class Perishable : public Product
    {
        Date dateObj;

    public:
        Perishable();
        std::fstream& store(std::fstream& file, bool newLine = true) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear) const;
        std::istream& read(std::istream& is);
        const Date& expiry() const;

    };
}


#endif