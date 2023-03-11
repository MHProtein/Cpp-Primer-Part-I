#include <iostream>
#include "Sales_Item.h"

double ff()
{
    double n = 10;
    double sum = 0;
    for(int i=0;i<n+1;i++)
    {
        sum += i;
    }
    return sum;
}

//2.5.1类型别名
typedef double wages;//wages是double的同义词
typedef wages base, * p;//base是wages的同义词，p是double*的同义词
//typedef是声明

//c++11 别名声明
using SI = Sales_Item;


int main()
{
    //2.5.2 auto
    wages wage = 100.0;
    p p = &wage;

    int v1 = 10;
    double v2 = 20.22;
    auto v3 = v1 + v2;
    std::cout << v3 << std::endl;
    //auto可以让编译器代替我们去分析表达式所属的类型
    //auto定义的变量必须有初始值

    //当引用被作为初始值时，编译器以引用对象的类型座位auto的类型
    int i = 0, & r = i;
    auto a = r;
    std::cout << a << std::endl;

    //auto一般会忽略掉顶层const，同时底层const会保存下来
    const int ci = i, & cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;

    //如果希望推断出的auto类型是顶层const：
    const auto f = ci;

    //2.5.3decltype
    //编译器分析表达式的类型并返回
    //return double
    decltype(ff()) sum = ff();
  
    decltype(ci) cii = 100;//cii为const int类型

    int num = 1, & rnum = num, * pnum = &num;
    decltype(++num) x = num;
    std::cout << x << std::endl;//decltype不会计算括号内的表达式，只返回表达式的类型

    decltype(rnum + 0) s = 10;//如果想让结果类型是引用所指的类型，可以把引用作为表达式的一部分
    decltype(*pnum) ppp = num;//如果操作时解引用，则会返回引用类型

    //decltype的返回值与表达式形式密切相关，如果变量名加上一对括号，编译器会把它当作一个表达式
    //变量是一种可以作为赋值语句的左值的特殊表达式，而赋值是会产生引用的经典表达式，所以会得到引用类型
    decltype((num)) ff = num;
    decltype(num) ffff;

    return 0;
}