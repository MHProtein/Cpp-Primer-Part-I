#include <iostream>

int main()
{
    //��ʽ����ת�� implicit conversion
    int ival = 3.14 + 4;
    //3ת��Ϊdouble �ڽ��мӷ� �����ת��Ϊint
    //�Զ�ִ�У��������Ա����

    //��������ᷢ��implicit conversion
    //��int����С������ֵ��������Ϊ�ϴ����������
    //�������У���boolֵת��Ϊbool����
    //�ڳ�ʼ�������У���ʼֵת��Ϊ���������ͣ��ٸ�ֵ����У��Ҳ��������ת��Ϊ����������
    //�������������ϵ��������ж������ͣ���Ҫת����ͬһ����
    //��������ʱҲ�ᷢ������ת��

    //4.11.1����ת�� arithmetic conversion
    //��������������ת��Ϊ��������
    //���һ�����������long double ��ô��һ��������ʲô���Ͷ���ת��Ϊlong double
    //�������int ���и���������ô��ת��Ϊ������

    //�������� integer promotion
    //�ϴ��char���� wchar_t, char16_t,char32_t����Ϊint, unsigned int, long, unsigned long, long long, unsigned long long����С��һ�����ͣ��ڿ������ɵ�ǰ��

    //�޷��� 
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

    //������ʽ����ת��
    //array->pointer
    int ia[10] = { 0 };
    int* p = ia;

    //ָ���ת��
    //0��nullptr��ת��λ����ָ������
    //ָ������ǳ�����ָ����ת����void*
    //ָ����������ָ����ת����const void*

    //ת��Ϊbool����
    int* ptr = nullptr;
    if (!ptr);

    //������ת��
    //while (std::cin >> ia[0]);//cin����ת��Ϊbool

    //4.11.3��ʾת�� ��ǿ������ת����
    //static_cast
    //ֻҪ�������ײ�const������ʹ��static_cast �����߱��������ǲ����ں�Ǳ�ڵľ�����ʧ��//����Ҫ��һ���ϴ���������͸�ֵ����С������ʱ�ǳ�����

    int i = 10, j = 20;
    double slope = static_cast<double>(i) / j;

    //���ڱ������޷��Զ�ִ�е�����ת��Ҳ�ǳ����ã� ���ǿ��������һ�void*ָ���е�ֵ
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