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

//2.5.1���ͱ���
typedef double wages;//wages��double��ͬ���
typedef wages base, * p;//base��wages��ͬ��ʣ�p��double*��ͬ���
//typedef������

//c++11 ��������
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
    //auto�����ñ�������������ȥ�������ʽ����������
    //auto����ı��������г�ʼֵ

    //�����ñ���Ϊ��ʼֵʱ�������������ö����������λauto������
    int i = 0, & r = i;
    auto a = r;
    std::cout << a << std::endl;

    //autoһ�����Ե�����const��ͬʱ�ײ�const�ᱣ������
    const int ci = i, & cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;

    //���ϣ���ƶϳ���auto�����Ƕ���const��
    const auto f = ci;

    //2.5.3decltype
    //�������������ʽ�����Ͳ�����
    //return double
    decltype(ff()) sum = ff();
  
    decltype(ci) cii = 100;//ciiΪconst int����

    int num = 1, & rnum = num, * pnum = &num;
    decltype(++num) x = num;
    std::cout << x << std::endl;//decltype������������ڵı��ʽ��ֻ���ر��ʽ������

    decltype(rnum + 0) s = 10;//������ý��������������ָ�����ͣ����԰�������Ϊ���ʽ��һ����
    decltype(*pnum) ppp = num;//�������ʱ�����ã���᷵����������

    //decltype�ķ���ֵ����ʽ��ʽ������أ��������������һ�����ţ����������������һ�����ʽ
    //������һ�ֿ�����Ϊ��ֵ������ֵ��������ʽ������ֵ�ǻ�������õľ�����ʽ�����Ի�õ���������
    decltype((num)) ff = num;
    decltype(num) ffff;

    return 0;
}