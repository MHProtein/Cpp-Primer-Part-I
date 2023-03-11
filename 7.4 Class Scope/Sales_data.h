#ifndef SALES_DATA_H
#define SALES_DATA_H
#pragma once
#include <string>
#include <istream>

class Sales_data
{
public:
    Sales_data() = default;
    Sales_data(const std::string& ISBN, size_t UNITS_SOLD, double price) :ClassNum(1), ClassNumRef(ClassNum)  //This is initialization
    {//Maybe to your fucking surprise, in the initializer list, the order of initialization depends on the appear-in-class-definition order of the members
        //So just like above, you should declare the value who is gonna be used in another member's initialization process in front of the latter.
        //Well, you should better make the order of members appearing in the initialization list the same of the order of their declaration
        //And avoid to initialize a member using another member's value

        //This is actually assignment//赋值
        //The distinction between initialization and assignment is a matter of low-level efficiency: a data is initialized and then assigned when it could have been initialized directly
        bookNo = new std::string(ISBN);
        units_sold = new size_t(UNITS_SOLD);
        revenue = new double(UNITS_SOLD * price);
    }

    //Delegating Constructor
    explicit Sales_data(const std::string& ISBN) :Sales_data(ISBN, 0, 0){}
    //明确的
    //This prevents other types to convert to the class type implicitly, and it's only useful in single parameter constructors

    explicit Sales_data(std::istream& in) :ClassNumRef(ClassNum), ClassNum(1)
    {
        int price = 0;
        bookNo = new std::string;
        units_sold = new size_t;
        in >> *bookNo >> *units_sold >> price;
        revenue = new double(*units_sold * (price));
    }

    void combine(const Sales_data& data);


private:
    std::string* bookNo;
    size_t* units_sold;
    double* revenue;
    const int ClassNum;
    const int& ClassNumRef;
};
#endif
