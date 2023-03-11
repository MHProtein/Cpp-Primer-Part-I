#include "Sales_data.h"

#include <iostream>

inline void Sales_data::combine(const Sales_data& data)
{
    if (this->bookNo != data.bookNo)
        std::cout << "ISBN not match" << std::endl;
    else
    {
        *this->units_sold += *data.units_sold;
        *this->revenue += *data.revenue;
    }
}
