#include <iostream>
#include <string>
#include "Sales_Data.h"


int main()
{
    Sales_Date data1, data2;
    double price = 0;
    std::cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;


    return 0;
}