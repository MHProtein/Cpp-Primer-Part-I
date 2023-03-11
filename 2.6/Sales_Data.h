#ifndef SALES_DATA_H
#define SALES_DATA_H
#pragma once
#include<string>

//头文件保护符
//头文件保护符依赖于预处理变量。
//预处理变量有两种状态：已定义和未定义
//#define指令把一个名字设定为预处理变量，另外两个指令则分别检查某个指定的预处理变量是否已经定义：
//#ifdef 当且仅当变量已定义时为真，
//#ifndef仅当变量未定义是为真
//一旦检查结果为真，则执行后续操作直至遇到#endif指令为止

struct Sales_Date
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;//收入
};

#endif

/*
 * 确保头文件多次包含仍能安全工作的常用技术是预处理器（preprocessor），预处理器是在编译之前执行的一段程序，可以部分改变我们所写的程序
 * 之前已经用到了一项预处理功能#include，当预处理器看到#include标记时就会用指定的头文件的内容代替#include
 */