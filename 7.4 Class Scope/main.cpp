#include <iostream>
#include <vector>

#include "Sales_data.h"

int main()
{
    Sales_data data1("xx", 0, 20.0);
    Sales_data data2(static_cast<Sales_data>(std::cin));
}
