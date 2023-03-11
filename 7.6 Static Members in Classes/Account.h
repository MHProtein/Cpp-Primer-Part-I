#pragma once
#include <string>

class Account
{
public:
    void calculate()
    {
        amount = amount * interestRate;
    }

    static double rate() { return interestRate; }
    static void rate(double);
    static double getInterestRate() { return interestRate; }

    //You can make a member associated with the class itself by adding the keyword static
    //Interest
private:
    std::string owner;
    double amount;
    static double interestRate; //There's only one interestRate shared with all the Account objects
    static double initRate()
    {
        return 0.12;
    }
};

//double Account::interestRate = 1.2;
