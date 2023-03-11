#include <iostream>
#include <string>
#include <iterator>

class Account
{
public:
    Account(){}
    Account(std::string name):AccountName(name){}
private:
    std::string AccountName;
};

void print(const char* cp)
{
    
}

void print(const int* beg, const int* end)
{
    
}

void print(const int arr[], size_t length)
{
    
}

//It is an error for two functions share the same parameter list to differ only in terms of their return types

//Overloading and const Parameters
//A parameter that has a top-level const is indistinguishable from one without a top-level const
//low-level parameters can be distinguished from parameters without low-level const
void lookup(Account& account){}
void lookup(const Account& account){}
void lookup(Account* accountRef){}
void lookup(const Account* accountRef){}

//const_cast and Overloading

const std::string& shorterString(const std::string& s1,const std::string& s2)
{
    return (s1.size() > s2.size()) ? s2 : s1;
}

std::string& shorterString(std::string& s1,std::string& s2)
{
    //we don't want the values of s1 and s2 get changed when the function working
    auto& r = shorterString(const_cast<const std::string&>(s1), const_cast<const std::string&>(s2));
    return const_cast<std::string&>(r);
}
//This version calls the const version of shorterString by casting its arguments to references to const.
//That function returns a reference to a const string, which we know is bound to one of our original, non-const arguments
//Therefore, we know it is safe to cast that string back to a plain string& in the return

//6.4.1 Overloading and Scope
//if you declare a function shares the same name with a function in the outer scope, the latter will be hidden
//since in C++, name lookup happens before type check

int main()
{
    int arr[10];
    for(size_t i=0;i<10;i++)
    {
        arr[i] = i;
    }
    print(arr, std::end(arr) - std::begin(arr));

    return 0;
}
