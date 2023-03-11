#include <iostream>
#include <iterator>

//ʹ�ñ��ָ�����鳤��
//for c-style string
void print1(const char* cp)
{
    if (cp)
        while (*cp)
            std::cout << *cp++ << std::endl;
}

//ʹ�ñ�׼��淶

void print2(const int* beg,const int* end)
{
    while(beg!=end)
    {
        std::cout << *beg++ << std::endl;
    }
}

//��ʽ����һ����ʾ�����С���β�

void print3(const int arr[],size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

//���������β�
void print4(const int (&arr)[10])
{
    for (int elem : arr)
    {
        std::cout << elem << std::endl;
    }
}

//���ݶ�ά����
void print5(int (*arr)[],size_t row_size)
{
   
}

void print6(const int arr[][10],size_t row_size)
{
    for (size_t i=0;i<row_size;++i)
    {
        for(size_t j=0;j<10;++j)
        {
            std::cout << arr[i][j] << std::endl;
        }
    }
}

int main()
{
    char arr[] = { "abcdefg"};
    int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
    print1(arr);
    print2(std::begin(a), std::end(a));
    print3(a, sizeof(a)/sizeof(a[0]));
    print4(a);
   

    return 0;
}