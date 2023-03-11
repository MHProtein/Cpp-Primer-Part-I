#include <string>
#include <iostream>
#include <algorithm>
#include <list>

void practice1(std::string& s, const std::string& oldVal, const std::string& newVal)
{
    for (auto it = s.begin(); it != s.end() - oldVal.size() + 1;)
    {
        if (std::string{ it,it + oldVal.size() } == oldVal)
        {
            it = s.erase(it, it + oldVal.size());
            it = s.insert(it, newVal.begin(), newVal.end());
            it += newVal.size();
        }
        else
            ++it;
    }
}

void practice2(std::string& s, const std::string& oldVal, const std::string& newVal)
{
    for (size_t i = 0; i <= s.size() - oldVal.size();)
    {
        if (s[i] == oldVal[0] && s.substr(i, oldVal.size()) == oldVal)
        {
            s.replace(i, oldVal.size(), newVal);
            i += newVal.size();
        }
        else
            ++i;
    }
}

auto practice3(std::string& Name, const std::string& prefix, const std::string& suffix)
{
    Name.insert(Name.begin(), prefix.begin(), prefix.end());
    return Name.append(suffix);
}

auto practice4()
{
    double sum = 0;
    std::string strArr[] = { "12.2","56.3","89.6","434.4","564.34" };
    for (const auto& str : strArr)
    {
        double temp = std::stod(str);
        sum += temp;
    }
    std::cout << sum << std::endl;
}

class Time
{
public:
    Time() = default;
    Time(const std::string& time)
    {
        unsigned tag = 0;
        unsigned format = 0;

        std::transform(time.begin(), time.end(), time.begin(), ::toupper);
        // 1/1/1900
        if(time.find_first_of('/')!=std::string::npos)
        {
            format = 0x01;
        }
        // January 1, 1900 or Jan 1 1900
        if (time.at(0) >= 'A' && time.at(0) <= 'Z')
        {
            format = 0x10;
            if(time.find_first_of(',')!=std::string::npos)
            {
                tag = 1;
            }
        }

        switch(format)
        {
        case 0x01:
            {
                this->month = std::stoi(time.substr(0, time.find_first_of('/')));
                this->day = std::stoi(time.substr(time.find_first_of('/'), time.find_last_of('/') - time.find_first_of('/')));
                this->year = std::stol(time.substr(time.find_last_of('/')));
                break;
            }
        case 0x10:
            {
                if (time.find(std::to_string(JAN)) < time.size()) this->month = JAN;
                if (time.find(std::to_string(FEB)) < time.size()) this->month = FEB;
                if (time.find(std::to_string(MAR)) < time.size()) this->month = MAR;
                if (time.find(std::to_string(APR)) < time.size()) this->month = APR;
                if (time.find(std::to_string(MAY)) < time.size()) this->month = MAY;
                if (time.find(std::to_string(JUN)) < time.size()) this->month = JUN;
                if (time.find(std::to_string(JUL)) < time.size()) this->month = JUL;
                if (time.find(std::to_string(AUG)) < time.size()) this->month = AUG;
                if (time.find(std::to_string(SEP)) < time.size()) this->month = SEP;
                if (time.find(std::to_string(OCT)) < time.size()) this->month = OCT;
                if (time.find(std::to_string(NOV)) < time.size()) this->month = NOV;
                if (time.find(std::to_string(DEC)) < time.size()) this->month = DEC;

                if(tag)
                {
                    this->day = std::stoi(time.substr(time.find_first_of(' '), time.find_first_of(',') - time.find_first_of(' ')));
                    this->year = std::stoi(time.substr(time.find_last_of(' ')));
                }
                else
                {
                    this->day = std::stoi(time.substr(time.find_first_of(' '), time.find_last_of(' ') - time.find_first_of(' ')));
                    this->year = std::stoi(time.substr(time.find_last_of(' ')));
                }
                break;
            }
        }
    }

private:
    enum Month { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
    unsigned year;
    unsigned month;
    unsigned day;
};

int main()
{
    //Other Ways to Construct a string
    std::string s("hello world");
    const char* c = "fuck the world";
    std::string exp(c, 10); //first 10 characters of c
    std::string exp2(s, 2);//all characters after position 2
    std::string exp3(s, 1, 10);//characters in the range of 1 to 11

    //substr Operation
    std::string s2 = s.substr(0, 5);//hello
    std::string s3 = s.substr(6);//world;

    //Other Ways to Change string
    s.insert(s.size(), 5, '!');//inserts 5 ! at the back of the string
    s.erase(s.size() - 5, 5);//erase the last 5 elements of s
    s.insert(0, s2, 0, s2.size());//inserts the number of s2.size()-0 elements before the position 0
    s.append("!23123");
    s.replace(2, 4, "12341234");//replace the next 4 elements from 2 with "1234"
    //the string used to replace don't have to share the same length as the string to be erased

    std::string sss("123123123123123");
    std::string ssss("123");
    std::string sssss("456");
    practice2(sss, ssss, sssss);
    std::cout << sss << std::endl;

    //Search Operations in string
    sss.find("123"); //Find the first occurrence of args in s
    sss.rfind("123"); //Find the last occurrence of args in s
    sss.find_first_of("123"); //Find the the first occurrence of any character from args in s
    sss.find_last_of("123");//Find the last occurrence of any character from args in s;
    sss.find_first_not_of("123"); //Find the first character in s that is not in args
    sss.find_last_not_of("123");//Find the last character in s that is not in args
    //these functions return a std::string::size_type
    //if they failed to find the string or character we want, it will return a std::string::npos which is a unsigned -1,
    //which means it is the value of the biggest capacity of string

    //9.5.5 Numeric Conversions

    int a = 0;
    std::to_string(a);

    //std::stoi(s, p, b);
    std::stoi(sss);   //Return the initial substring of s that has numeric content as an int,
    std::stol(sss);   //long, unsigned long, unsigned long long, long long, respectively. //·Ö±ðµÄ
    std::stoul(sss);  //b indicates the numeric base to use for the conversion, b defaults to 10
    std::stoll(sss);  // p is a pointer to a size_t in which to put the index of the first nonnumeric character in s; p defaults to 0, in which case the function does not store the index
    std::stoull(sss);

    //std::stof(s, p);
    std::stof(sss);//Return the initial numeric substring in s as a float, double, or long double, respectively.
    std::stod(sss);//p has the same behavior as described for the integer conversions
    std::stold(sss);

    std::list<int> l;
    
}