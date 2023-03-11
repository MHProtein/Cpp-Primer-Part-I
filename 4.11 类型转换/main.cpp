#include <iostream>

int main()
{
    //隐式类型转换 implicit conversion
    int ival = 3.14 + 4;
    //3转换为double 在进行加法 最后结果转换为int
    //自动执行，无需程序员介入

    //以下情况会发生implicit conversion
    //比int类型小的整数值首先提升为较大的整数类型
    //在条件中，非bool值转换为bool类型
    //在初始化过程中，初始值转换为变量的类型；再赋值语句中，右侧运算对象转换为左侧运算对象
    //如果算术运算或关系运算对象有多种类型，需要转换成同一类型
    //函数调用时也会发生类型转换

    //4.11.1算术转换 arithmetic conversion
    //运算符的运算对象转换为最宽的类型
    //如果一个运算对象是long double 那么另一个不论是什么类型都会转换为long double
    //如果既有int 又有浮点数，那么会转换为浮点数

    //整型提升 integer promotion
    //较大的char类型 wchar_t, char16_t,char32_t提升为int, unsigned int, long, unsigned long, long long, unsigned long long中最小的一种类型，在可以容纳的前提

    //无符号 
    /*
     * if(signed<=unsigned)
     * {
     *      signed->unsigned
     * }
     * else
     * {
     *      depends on their size
     * }
     */

    //其他隐式类型转换
    //array->pointer
    int ia[10] = { 0 };
    int* p = ia;

    //指针的转换
    //0或nullptr能转换位任意指针类型
    //指向任意非常量的指针能转换成void*
    //指向任意对象的指针能转换成const void*

    //转换为bool类型
    int* ptr = nullptr;
    if (!ptr);

    //类类型转换
    //while (std::cin >> ia[0]);//cin类型转换为bool

    //4.11.3显示转换 （强制类型转换）
    //static_cast
    //只要不包含底层const都可以使用static_cast 他告诉编译器我们并不在乎潜在的精度损失、//当需要把一个较大的算术类型赋值给较小的类型时非常有用

    int i = 10, j = 20;
    double slope = static_cast<double>(i) / j;

    //对于编译器无法自动执行的类型转换也非常有用， 我们可以用它找回void*指针中的值
    void* ip = &i;
    double* dp = static_cast<double*>(ip);

    //const_cast //usually be used in the context of function overrides
    const char* st;
    const_cast<char*>(st);
    //cast away the const

    //reinterpret_cast
    int* pi = nullptr;
    char* pc = reinterpret_cast<char*>(pi);  //pc is an int


    return 0;
}