// Tracy Nguyen 127270171
#include "Perishable.h"

namespace AMA
{
    Perishable::Perishable() : Product('P')
    {
      
    }

    std::fstream& Perishable::store(std::fstream& file, bool newLine) const
    {
        Product::store(file, false);
        file << ',';
        dateObj.write(file);

        if (newLine)
        {
            file << std::endl;
        }

        return file;
    }

    std::fstream& Perishable::load(std::fstream& file)
    {
        Product::load(file);
        dateObj.read(file);

        file.ignore();

        return file;
    }

    std::ostream& Perishable::write(std::ostream& os, bool linear) const
    {

        Product::write(os, linear);

        if (!isEmpty() && isClear())
        {
            if (!linear)
            {
                os << std::endl << " Expiry date: ";
                dateObj.write(os);
            }

            else
            {
                dateObj.write(os);
            }
        }

        return os;
    }

    std::istream& Perishable::read(std::istream& is)
    {
        Product::read(is);

        if (!is.fail())
        {
            std::cout << " Expiry date (YYYY/MM/DD): ";

            Date tempDate;
            tempDate.read(is);

            int errCode = tempDate.errCode();

            if (errCode)
            {
                is.setstate(std::ios::failbit);

                if (errCode == 1)
                {
                    errObj.message("Invalid Date Entry");
                }

                else if (errCode == 2)
                {
                    errObj.message("Invalid Year in Date Entry");
                }

                else if (errCode == 3)
                {
                    errObj.message("Invalid Month in Date Entry");
                }

                else if (errCode == 4)
                {
                    errObj.message("Invalid Day in Date Entry");
                }
            }

            else
            {
                errObj.clear();
                dateObj = tempDate;
            }
        }



        return is;
    }

    const Date& Perishable::expiry() const
    {
        return dateObj;
    }


}