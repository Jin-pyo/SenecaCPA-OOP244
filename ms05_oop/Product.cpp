#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>
#include "Product.h"

using std::cin;
using std::cout;

namespace AMA {

    Product::Product(char p_prodType)
    {
        prodType = p_prodType;
        prodSku[0] = '\0';
        prodUnit[0] = '\0';
        prodName = nullptr;
        qtyOnHand = 0;
        qtyReq = 0;
        priceBefore = 0.0;
        taxable = false;

    }

    Product::Product(const char* p_prodSku, const char* p_prodName, const char* p_prodUnit, int p_qty, bool p_taxable, double p_price, int p_qtyReq)
    {
        name(p_prodName);

        strncpy(prodSku, p_prodSku, max_sku_length);
        prodSku[max_sku_length] = '\0';

        strncpy(prodUnit, p_prodUnit, max_unit_length);
        prodUnit[max_unit_length] = '\0';

        qtyOnHand = p_qty;
        taxable = p_taxable;
        priceBefore = p_price;
        qtyReq = p_qtyReq;
    }

    Product::Product(const Product& p_prod)
    {
        name(p_prod.prodName);

        strncpy(prodSku, p_prod.prodSku, max_sku_length);
        prodSku[max_sku_length] = '\0';

        strncpy(prodUnit, p_prod.prodUnit, max_unit_length);
        prodUnit[max_unit_length] = '\0';

        qtyOnHand = p_prod.qtyOnHand;
        taxable = p_prod.taxable;
        priceBefore = p_prod.priceBefore;
        qtyReq = p_prod.qtyReq;
    }

    Product::~Product()
    {
        delete[] prodName;
    }

    Product& Product::operator= (const Product& prod)
    {

        prodType = prod.prodType;

        strncpy(prodSku, prod.prodSku, max_sku_length);
        prodSku[max_sku_length] = '\0';

        strncpy(prodUnit, prod.prodUnit, max_unit_length);
        prodUnit[max_unit_length] = '\0';

        name(prod.prodName);

        qtyOnHand = prod.qtyOnHand;
        qtyReq = prod.qtyReq;
        priceBefore = prod.priceBefore;
        taxable = prod.taxable;


        return *this;
    }

    std::fstream& Product::store(std::fstream& file, bool newLine) const
    {
        file << prodType << ','
            << prodSku << ','
            << prodName << ','
            << prodUnit << ','
            << taxable << ','
            << priceBefore << ','
            << qtyOnHand << ','
            << qtyReq;

        if (newLine == true)
        {
            file << std::endl;
        }

        return file;
    }

    std::fstream& Product::load(std::fstream& file)
    {
        Product temp;
        temp.prodName = new char[max_name_length + 1];

        /* file.get(temp.prodType);
         file.ignore(); */
        file.getline(temp.prodSku, max_sku_length, ',');
        file.getline(temp.prodName, max_name_length, ',');
        file.getline(temp.prodUnit, max_unit_length, ',');
        file >> temp.taxable;
        file.ignore();
        file >> temp.priceBefore;
        file.ignore();
        file >> temp.qtyOnHand;
        file.ignore();
        file >> temp.qtyReq;
        file.ignore();

        *this = temp;

        return file;
    }


    std::ostream& Product::write(std::ostream& os, bool linear) const
    {
        if (!errObj.isClear())
        {
            os << errObj.message();
        }

        else if (linear)
        {
            os << std::setfill(' ') << std::left
                << std::setw(max_sku_length) << prodSku << "|"
                << std::setw(20) << prodName << "|"
                << std::right
                << std::fixed << std::setprecision(2)
                << std::setw(7) << cost() << "|"
                << std::setw(4) << qtyOnHand << "|"
                << std::left
                << std::setw(10) << prodUnit << "|"
                << std::right
                << std::setw(4) << qtyReq << "|";
        }

        else
        {
            os << " Sku: " << prodSku << std::endl
                << " Name (no spaces): " << prodName << std::endl
                << " Price: " << priceBefore << std::endl
                << " Price after tax: ";

            if (taxable)
            {
                os << cost() << std::endl;
            }

            else
            {
                os << "N/A" << std::endl;
            }

            os << " Quantity on Hand: " << qtyOnHand << ' ' << prodUnit << std::endl
                << " Quantity needed: " << qtyReq;
        }

        return os;
    }



    std::istream& Product::read(std::istream& is)
    {
        char t_taxable;
        char * t_prodName = new char[max_name_length + 1];


        if (!is.fail())
        {
            cout << " Sku: ";
            is >> prodSku;
            cin.ignore();


            cout << " Name (no spaces): ";
            is >> t_prodName;
            name(t_prodName);

            cout << " Unit: ";
            is >> prodUnit;

            cout << " Taxed? (y/n): ";
            is >> t_taxable;

            if (!is.fail())
            {
                if (t_taxable != 'y' && t_taxable != 'Y' && t_taxable != 'n' && t_taxable != 'N')
                {
                    errObj.message("Only (Y)es or (N)o are acceptable");
                    is.setstate(std::ios::failbit);
                }

                else {
                   
                    if (t_taxable == 'y' || t_taxable == 'Y')
                    {
                        taxable = true;
                    }

                    else //if (t_taxable == 'n' || t_taxable == 'N')
                    {
                        taxable = false;
                    }

                    cout << " Price: ";
                    is >> priceBefore;

                    if (is.fail())
                    {
                        is.setstate(std::ios::failbit);
                        errObj.message("Invalid Price Entry");
                    }

                    else
                    {
                        cout << " Quantity on hand: ";
                        is >> qtyOnHand;

                        if (is.fail())
                        {
                            errObj.message("Invalid Quantity Entry");
                            is.setstate(std::ios::failbit);
                        }

                        else
                        {
                            cout << " Quantity needed: ";
                            is >> qtyReq;
                            cin.ignore();

                            if (is.fail())
                            {
                                errObj.message("Invalid Quantity Needed Entry");
                                is.setstate(std::ios::failbit);
                            }


                            if (!is.fail())
                            {
                                errObj.clear();
                            }
                        }
                    }
                }
            }

            else
            {
                is.setstate(std::ios::failbit);
                errObj.message("Only (Y)es or (N)o are acceptable");
            }

        }
        return is;
    }

    void Product::name(const char* p_prodName)
    {
        if (p_prodName != nullptr)
        {
            int i;
            // Find number of characters in string
            for (i = 0; p_prodName[i] != '\0' || i <= max_name_length; i++);

            prodName = new char[i + 1];

            strncpy(prodName, p_prodName, i);
            prodName[i] = '\0';
        }

        else
        {
            delete[] prodName;
        }

        return;
    }

    const char* Product::name() const
    {
        return prodName;
    }

    const char* Product::sku() const
    {
        return prodSku;
    }

    const char* Product::unit() const
    {
        return prodUnit;
    }

    bool Product::taxed() const
    {
        return taxable;
    }

    double Product::price() const
    {
        return priceBefore;
    }

    double Product::cost() const
    {
        double cost;

        if (taxable)
        {
            cost = priceBefore * (1 + taxRate);
        }

        else
        {
            cost = priceBefore;
        }


        return cost;
    }

    void Product::message(const char* errMsg)
    {
        errObj.message(errMsg);

        return;
    }

    bool Product::isClear() const
    {
        bool clear = false;

        clear = errObj.isClear();

        return clear;
    }

    bool Product::operator==(const char* str) const
    {
        bool match = false;

        if (strcmp(str, prodSku) == 0)
        {
            match = true;
        }

        return match;
    }

    double Product::total_cost() const
    {
        return ((priceBefore * qtyOnHand) * (1 + taxRate));
    }

    void Product::quantity(int p_qtyOnHand)
    {
        qtyOnHand = p_qtyOnHand;
        return;
    }

    bool Product::isEmpty() const
    {
        bool empty = false;

        if (prodName == nullptr)
        {
            empty = true;
        }

        return empty;
    }

    int Product::qtyNeeded() const
    {
        return qtyReq;
    }

    int Product::quantity() const
    {
        return qtyOnHand;
    }

    bool Product::operator>(const char* p_prodSku) const
    {
        bool gt = false;

        if (strcmp(prodSku, p_prodSku) > 0)
        {
            gt = true;
        }

        return gt;
    }

    bool Product::operator>(const iProduct& p_prod) const
    {
        bool gt = false;

        if (strcmp(prodName, p_prod.name()) > 0)
        {
            gt = true;
        }

        return gt;
    }

    int Product::operator+= (int additUnits)
    {
        if (additUnits > 0)
        {
            qtyOnHand += additUnits;
        }

        return qtyOnHand;
    }

    std::ostream& operator<< (std::ostream& os, const iProduct& p_prod)
    {
        p_prod.write(os, true);

        return os;
    }

    std::istream& operator>> (std::istream& is, iProduct& p_prod)
    {
        p_prod.read(is);

        return is;
    }

    double operator+= (double& additCost, const iProduct& p_prod)
    {
        return p_prod.total_cost() + additCost;
    }
}