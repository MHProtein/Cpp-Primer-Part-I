#include <iostream>
#include <vector>//����
#include <string>
#include"GradesClassify.h"

int main()
{
    //3.1.1 initialize vector
    //�б��ʼ��vector
    std::vector<std::string> articles = { "a","an","the" };//�б��ʼ��
    //����ָ��������Ԫ��
    std::vector<int> v1(10, -1);//���ù��캯������ʼ��
    //value initialization
    std::vector<std::string> v2(10);
    //����ʹ��ֱ�ӳ�ʼ������ʽ��ָ��vector��С

    //3.3.2 add elements to vector
    std::vector<int> v3;
    for(auto i=0;i!=100;++i)
    {
        v3.push_back(i);
    }

    //����Ԫ�ش�С��һ���������ڶ���vector�����ʱ���趨���Сû�б�Ҫ���������ܵ������ܸ���

    //3.3.3����vector����
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

    //�±�ֻ�ܷ����Ѵ��ڵ�Ԫ��

    return 0;
}