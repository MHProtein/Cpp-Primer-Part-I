#include <iostream>
#include <vector>//容器
#include <string>
#include"GradesClassify.h"

int main()
{
    //3.1.1 initialize vector
    //列表初始化vector
    std::vector<std::string> articles = { "a","an","the" };//列表初始化
    //创建指定数量的元素
    std::vector<int> v1(10, -1);//调用构造函数来初始化
    //value initialization
    std::vector<std::string> v2(10);
    //必须使用直接初始化的形式来指定vector大小

    //3.3.2 add elements to vector
    std::vector<int> v3;
    for(auto i=0;i!=100;++i)
    {
        v3.push_back(i);
    }

    //除非元素大小都一样，否则在定义vector对象的时候设定其大小没有必要，甚至可能导致性能更差

    //3.3.3其他vector操作
    for(auto& elem:v3)
    {
        elem *= elem;
    }

    for(auto it=v3.begin();it!=v3.end();++it)
    {
        *it = *it;
    }

    if(!v3.empty())
    {
        
    }

    decltype(v3.size()) sz = 10;
    std::vector<int>::size_type szz = 100;
    GradesClassify* grades_classify = new GradesClassify;
    grades_classify->GradesClassification();

    //下标只能访问已存在的元素

    return 0;
}