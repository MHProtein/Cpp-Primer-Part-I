#include <iostream>
#include <string>
#include <cctype>

int main()
{
    //3.2.1
    //several ways to initialize string
    std::string s1= "hi";
    std::string s2(s1);
    std::string s3 = s1;
    std::string s4("value");
    std::string s5(10, 'c');

    //copy initialization and direct initialization
    //如果使用等号初始化一个变量，实际上执行的是copy initialization，编译器把等号右边的初始值拷贝到新创建的对象中去
    //如果不使用等号，则执行的是直接初始化

    std::string s6 = "hiya";//copy initialization
    std::string s7("hiya");//direct initialization

    //3.3.2
    //读写string对象
    std::string s;
    //std::cin >> s;
    //读取未知数量的string对象
    std::string word;
    while (std::cin >> word)
        std::cout << word << std::endl;
    //use getline to read a whole line
    getline(std::cin, s);

    //std::string::size_type
    decltype(s.size()) sz = 10;//s.size() returns the std::string::size_type type
    std::string::size_type szz = 100;
    auto szzz = s.size();
    //他是一个无符号类型的值，而且能存放下任何string对象的大小，用于存放string类size函数的返回值变量都是上述类型的
    //如果一条表达式中已经有了size（）函数就不要再使用int了，这样可以避免int和unsigned混用可能带来的问题
    //unsigned 与 int比较时，int会转换为unsigned进行比较

    //字面值和string对象相加
    //因为字符串字面值不是string类型，所以两个字符串字面值不能相加
    //string s8="hello"+" "+s7;错误
    std::string s0 = "Hello" + (" " + s7);

    //3.2.3 处理string对象中的字符
    isalnum(s[0]);//为字母或数字是返回true
    isalpha(s[0]);//为字母是返回true
    iscntrl(s[0]);//为控制字符是返回true
    isdigit(s[0]);//为数字是为true
    isgraph(s[0]);//不是空格但可打印是为true
    islower(s[0]);
    isupper(s[0]);
    isprint(s[0]);//为可打印字符时为真（即c是空格或c具有可视形式）
    ispunct(s[0]);//为标点符号是为真
    isspace(s[0]);//空白时为真（即c是空格、\t，\v，enter、\n、进纸符中的一种）
    isxdigit(s[0]);//为16进制时为真
    tolower(s[0]);
    toupper(s[0]);

    for(auto& elem:s)
    {
        elem = toupper(elem);
    }

    //使用下标执行迭代
    for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
    {
        //设下标类型为std::string::size_type避免了下标的值小于0，只需保证下标的值<s.size（）的值即可
    }

    for(std::string::iterator it=s.begin();it!=s.end();++it)
    {
        //for循环中，i++先返回i的值再自增i，所以在每次for循环中都会花费额外的内存和时间去开辟新的临时变量空间来转存，效率更低
        //++i是直接将i自增后再返回，省去了开辟新的临时变量的额外消耗，故其效率比i++高
    }

    return 0;
}