#include <iostream>
#include <string>
#include <iterator>

int getNumber()
{
    return 1;
}

int main()
{
    int a = 0;
    std::cout << a << " " << ++a << std::endl; //undefined action

    //4.2
    bool b1 = true;
    bool b2 = -b1;
    //b2=true cause when b1 is promoted to an integer 1, so when -1 is transformed back into boolean, since the initial value doesn't equals to 0, so b2 equals to true

    //IF You've got a huge size array, when you wanna go through it, you'd better use a reference
    std::string text[100] = { "0" };
    for (const auto& basic_string : text)
    {
        std::cout << basic_string << std::endl;
    }

    int i = 0;
    while ((i = getNumber()) != 42)
    {
        
    }

    auto it = text->begin();
    std::cout << *it++ << std::endl;//this means *(it++) which print the current value first and then move it one position forward

    std::string str = "hello there";

    auto itstr = str.begin();
    while (itstr != str.end() && (*itstr) != '.')
       // *itstr = ::toupper(*itstr++); 未定义行为
    {
        *itstr = ::toupper(*itstr);
        ++itstr;
    }

    auto p = &str;
    std::size_t n = p->size();
    std::size_t m = str.size();
    std::size_t o = (*p).size();

    constexpr int biggerExpr = 10; 
    constexpr int smallerExpr = 2;
    bool is_bigger = biggerExpr > smallerExpr ? true : false;
    //条件运算符的优先级非常低 进行输出操作的话必须打好括号！！！！！

    
    return 0;
}