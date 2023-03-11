#include <iostream>
#include <cstddef>
#include <iterator>
#include <cstring>
#include <string>
#include <vector>

int main()
{
    //3.5.1

    //you cannot use an array to initialize another array
    int a[10] = { 0 };
    //int b[10] = a;

    //understand complex declarations of arrays
    int* prts[10] = { nullptr };
    //int& arrRef[10]   //error you cant declaration an array with references inside it
    int(*Parray)[10] = &a;//Parray points at an array with 10 integers inside it
    int(&ArrayRef)[10] = a;//ArrayRef is a reference to an array with 10 integers inside it
    int* (&PArrayRef)[10] = prts;

    //3.5.2

    for (size_t i = 0; i < 10; ++i)
    {
        a[i] = i;
    }
    //������±��������c++����ֱ�Ӷ����
    //��vector���±�������ǿ�ģ��vector����ģ�ֻ������vector���͵��������

    for(auto elem:a)
    {
        std::cout << elem << std::endl;
    }

    //����±꣡������������������������������������������������������������������������������������������������������
    //����������İ�ȫ���ⶼԴ�ڻ�����������󡣵�����������������ݽṹ���±�Խ�粢��ͼ���ʷǷ��ڴ�����ʱ���ͻ�����������

    //3.5.3
    std::string nums[] = { "one","two","three" };
    std::string* p = &nums[0];
    //equels to
    std::string* pp = nums;

    auto ia2(a); //ia2 is a pointer which points at the first element of the array

    decltype(a) c = { 0 };//this returns int[10] type

    //pointer is also an iterator
    int* ptr = a;
    ++ptr;//points at arr[1]

    

    for(auto it=std::begin(a);it!=std::end(a);++it) //auto returns int* type
    {
        std::cout << *it << std::endl;
    }
    //β��ָ�벻�ܽ��н����ú͵�������

    auto n = std::end(a) - std::begin(a);
    ptrdiff_t m = std::end(a) - std::begin(a);

    //��׼�������޶�ʹ�õ��±�������޷�������
    //�����õ��±������޴�Ҫ��

    //3.5.4
    char ca[] = { 'C', '+', '+' };
    char cb[] = { "abcd" };
    std::cout << strlen(ca) << std::endl;
    //strcmp() if two strings equal, strcmp() returns 0, if the first string is bigger, it returns a positive value, if else, it returns a negative value
    strcmp(ca, cb);

    //strcpy_s(ca, cb);
    //copy cb to ca
    //strcat(ca, cb); //a appends b
    //if you wanna use these two functions, make sure you already created an array which is large enough to contain the processed string and its '\0'
    //If we calculate the wrong size of ca, there's gonna be a huge error

    //3.5.5 interfaces to good old codes
    std::string s("Hello World");

    const char* str = s.c_str();

    //use arrays to initialize vectors

    int int_arr[] = { 1,2,3,4,5 };

    std::vector<int> v(std::begin(int_arr), std::end(int_arr));
    std::vector<int> ivec(int_arr + 1, int_arr + 4);
    std::cout << std::endl;
    for (auto elem : ivec)
    {
        std::cout << elem << std::endl;
    }

    //modern C++ should use vector and iterator as much as possible to avoid arrays and pointers, and you should use string rather than c-style-array-based string

    return 0; 
}