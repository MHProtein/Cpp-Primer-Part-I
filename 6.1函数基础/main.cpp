#include <iostream>
#include <ostream>
#include <string>



void counter() 
{
    static int cnt = 0;
    ++cnt;
}

//use reference to return additional information

std::string::size_type find_char(std::string& str, char target_char, std::string::size_type& cnt)
{
    for(auto elem:str)
    {
        if (elem == target_char)
            ++cnt;
    }
    auto firtsPos = str.find(target_char);
    return firtsPos;
}

bool is_sentence(const std::string& str)
{
    std::string temp = str;
    size_t cnt = 0;
    return find_char(temp, '.', cnt) == str.size() - 1 && cnt == 1;
}

int main()
{

    std::string hello = "Hello Hello";
    size_t cnt = 0;
    auto fpos = find_char(hello, 'l', cnt);

    std::cout << fpos << " " << cnt << std::endl;


    return 0;
}