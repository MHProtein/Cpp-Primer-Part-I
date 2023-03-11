#include<iostream>
#include <format>
#include <string>
#include <algorithm>
#include <exception>

int main()
{
    //do while
    std::string rsp; 
    do
    {
        std::cout << "plz enter two numbers:";
        int val1 = 0, val2 = 0;
        std::cin >> val1 >> val2;
        std::cout << std::format("The sum of {} and {} is {}", val1, val2, val1 + val2) << std::endl;
        std::cout << "More?(y/n):";
        std::cin >> rsp;
        std::transform(rsp.cbegin(), rsp.cend(), rsp.begin(), ::toupper);
    } while (!rsp.empty() && rsp == "YES");

    std::string item1;
    std::string item2;
    while(std::cin>>item1>>item2)
    {
        try
        {
        }
        catch(std::runtime_error err)
        {
            std::cout << err.what() << std::endl;
        }
    }

    return 0; 
}