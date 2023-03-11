#include <iostream>
#include "Account.h"

int main()
{
    double r;
    Account ac1;
    Account* ac2;
    r = Account::rate();
    r = ac1.rate();
    r = ac2->rate();
    std::cout << Account::getInterestRate() << std::endl;
}
