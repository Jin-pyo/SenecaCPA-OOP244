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

            *this = temp;

        return file;
    }

    std::ostream& Product::write(std::ostream& os, bool linear) const
    {
        if (linear)
        {
            os << std::left
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
                << " Name (no spaces):  " << prodName << std::endl
                << " Price: " << priceBefore << std::endl;

            if (taxable)
            {
                os << " Price after tax: " << cost() << std::endl;
            }

            else
            {
                os << " N/A" << std::endl;
            }

            os << " Quantity on hand: " << qtyOnHand << std::endl
                << " Quantity needed:  " << qtyReq << std::endl;
        }

        return os;
    }

    std::istream& Product::read(std::istream& is)
    {

        char t_prodSku[max_sku_length + 1];
        char* t_prodName = new char[max_name_length + 1];
        char t_prodUnit[max_unit_length + 1];
       
        char t_tax;
        bool t_taxable;
        
        int t_qtyOnHand;
        int t_qtyReq;
        double t_priceBefore;

        cout << " Sku: ";
        is >> t_prodSku;
        cout << " Name (no spaces): ";
        is >> t_prodName;
        cout << " Unit: ";
        is >> t_prodUnit;
        cout << " Taxed? (y/n): ";
        is >> t_tax;

        if (t_tax != 'y' && t_tax != 'Y' && t_tax != 'n' && t_tax != 'N')
        {
            errObj.message("Only (Y)es or (N)o are acceptable");
            is.setstate(std::ios::failbit);
        }

        else if (t_tax == 'y' || t_tax == 'Y')
        {
            t_taxable = true;
        }

        else if (t_tax == 'n' || t_tax == 'N')
        {
            t_taxable = false;
        }
        
        else
        {
            errObj.message("Only (Y)es or (N)o are acceptable");
            is.setstate(std::ios::failbit);
        }

        if (!is.fail())
        {
            cout << " Price: ";
            is >> t_priceBefore;

            if (is.fail())
            {
                errObj.message("Invalid Price Entry");
            }
        }

        if (!is.fail())
        {
            cout << " Quantity on hand: ";
            is >> t_qtyOnHand;

            if (is.fail())
            {
                errObj.message("Invalid Quantity Entry");
            }
        }

        if (!is.fail())
        {
            cout << " Quantity needed: ";
            is >> t_qtyReq;
            
            if (is.fail())
            {
                errObj.message("Invalid Quantity Needed Entry");
            }
        }


        if (!is.fail())
        {
            Product temp = Product(t_prodSku, t_prodName, t_prodUnit, t_qtyOnHand, t_taxable, t_priceBefore, t_qtyReq);
            *this = temp;
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

        if (prodType == 'N')
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

    bool Product::operator>(const Product& p_prod) const
    {
        bool gt = false;

        if (strcmp(prodName, p_prod.prodName) > 0)
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

    std::ostream& operator<< (std::ostream& os, const Product& p_prod)
    {
        p_prod.write(os, true);

        return os;
    }

    std::istream& operator>> (std::istream& is, Product& p_prod)
    {
        p_prod.read(is);

        return is;
    }

    double operator+= (double& additCost, const Product& p_prod)
    {
        return p_prod.total_cost() + additCost;
    }
}