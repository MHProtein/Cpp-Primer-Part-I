#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;
};

bool valid(const std::string& number)
{
    if (number.size() == 11)
        return true;
    return false;
}

std::string format(const std::string& number)
{
    return "+86 " + number;
}

int main()
{
    std::string String("yoooooo");
    std::string AnotherString("hi");
    std::stringstream strm;
    strm.str();// returns a copy of the string that strm holds
    strm.str(AnotherString);//Copies the string into strm

    //istringtream
    std::vector<PersonInfo> people;
    std::string tempInfo;
    while(std::getline(std::cin,tempInfo))
    {
        PersonInfo info;
        std::istringstream temp(tempInfo);
        temp >> info.name;
        std::string phone;
        while(temp>>phone)
        {
            info.phones.push_back(phone);
        }
        people.push_back(info);
    }

    std::cout << people[0].name << std::endl;
    for ( const auto& phone : people[0].phones)
    {
        std::cout << phone << std::endl;
    }

    //ostringstream
    for(const auto& entry: people)
    {
        std::ostringstream formatted, badNums;
        for (const auto& nums : entry.phones)
        {
            if(!valid(nums))
            {
                badNums << " " << nums;
            }
            else
            {
                formatted << " " << format(nums);
            }
        }
        if (badNums.str().empty())
            std::cout << entry.name << " " << formatted.str() << std::endl;
        else
        {
            std::cerr << "input error: " << entry.name << "invalid number(s) " << badNums.str() << std::endl;
        }
    }

}