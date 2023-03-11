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
        //v.begin()����ָ���һ��Ԫ�صĵ�����
        //v.end()ָʾ����������һ���������ڵ�off the endԪ�أ����Ǹ���Ƕ��ѣ���ʾ�����Ѿ�
        //���������е�Ԫ��

        std::cout << *it << std::endl;
    }

    v.begin() != v.end();//���ǿ�

    //Ϊʲô�ǣ�=������<��
    //����stl�����ĵ�������������==�ͣ�=�������Ǵ������û�ж���<

    //iterator types
    std::vector<int>::iterator vit;//���Զ�дvector<int>��Ԫ��
    std::vector<int>::const_iterator vcit;//ֻ�ܶ�������д

    auto vit2 = v.cbegin(); //return const_iterator
    auto vit3 = v.cend();

    std::vector<std::string> vs{ "ss","fff" };
    auto its = vs.begin();
    (*its).empty();
    //equals to
    its->empty();

    //������ʹ���˵�������ѭ���壬����Ҫ��������������������Ԫ�� �����ʹ������ʧЧ

    //3.4.2������������

    auto mid = its + vs.size() / 2;//�õ���ӽ��м�Ԫ�ص�һ��������

    auto distance = mid - its;//distance's type is difference_type
    //difference is signed for the distance between two iterators could be negative or positive



}