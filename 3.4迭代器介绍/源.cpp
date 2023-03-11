#include <iostream>
#include <string>
#include <vector>

int main()
{
    //3.4.1 use iterators

    std::vector<int> v;
    for (decltype(v.size()) index = 0; index != 10; ++index)
    {
        v.push_back(index);
    }

    for (auto it = v.begin(); it != v.end(); ++it)
    {
        //v.begin()返回指向第一个元素的迭代器
        //v.end()指示的是容器的一个本不存在的off the end元素，仅是个标记而已，表示我们已经
        //处理完所有的元素

        std::cout << *it << std::endl;
    }

    v.begin() != v.end();//检查非空

    //为什么是！=而不是<？
    //所有stl容器的迭代器都定义了==和！=，但他们大多数都没有定义<

    //iterator types
    std::vector<int>::iterator vit;//可以读写vector<int>的元素
    std::vector<int>::const_iterator vcit;//只能读，不能写

    auto vit2 = v.cbegin(); //return const_iterator
    auto vit3 = v.cend();

    std::vector<std::string> vs{ "ss","fff" };
    auto its = vs.begin();
    (*its).empty();
    //equals to
    its->empty();

    //但凡是使用了迭代器的循环体，都不要向迭代器所属的容器添加元素 否则会使迭代器失效

    //3.4.2迭代器的运算

    auto mid = its + vs.size() / 2;//得到最接近中间元素的一个迭代器

    auto distance = mid - its;//distance's type is difference_type
    //difference is signed for the distance between two iterators could be negative or positive



}