#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>

//6.3.1 û�з���ֵ�����
void swap(int& a, int& b)
{
    if (a == b)
        return;
    else
    {
        int temp = a;
        a = b;
        b = temp;
    }
    //�˴�������ʽ��return��䣬�Զ�ִ��
}

//6.3.2�з���ֵ�ĺ���
int WillReturnOne()
{
    return 1;
}
//if there is a loop remember to add a return statement behind it
//How values are returned
//The return value is used to initialize a temporary at the call site(���õ�), and the temporary is the result of the function

std::string make_plural(size_t cnt, std::string& word,const std::string& ending)
{
    return (cnt > 1) ? word : word + ending;
}
//�ú����ķ���������string����ζ�ŷ���ֵ�������������õ㡣��ˣ��ú���������word�ĸ�������һ��δ��������ʱstring���󣬸ö����������word+ending

//const std::string& manip()//���ݸ�
//{
//    std::string ret;
//    if (!ret.empty())
//        return ret;
//    else
//        return "Empty";
//}
//���ϵ�����return��������δ�����ֵ��Ҳ����˵��ͼʹ��manip�����ķ���ֵ������δ�������Ϊ��
//���ڵ�һ�����return�����˵����Ȼ�����ص��Ǿֲ����������
//�ڶ���return����У��ַ�������ֵת����һ���ֲ���ʱstring���󣬶���manip��˵���ö����retһ�����Ǿֲ��ġ�
//����������ʱ��ʱ����ռ�õĿռ�Ҳ����֮�ͷ��ˣ���������return��䶼ָ����һ�������ڵĶ���
//��Ϊ���ص����������ͣ���������������������������������������������������������������������������������������������

//Ϊ��ȷ������ֵ�İ�ȫ,�ʣ��������������ں���֮ǰ�Ѿ����ڵ��ĸ�����

//���ؾֲ������ָ��Ҳ�Ǵ���ģ�һ��������ɣ��ֲ������ͷţ�ָ�뽫ָ��һ�������ڵĶ���

//Reference Returns Are Lvalues
//A call to a function that returns a reference can be used in the same ways as any other lvalue.
//In particular, we can assign(��ֵ) to the result of a function that returns a reference to nonconst

char& get_val(std::string& str, std::string::size_type ix)
{
    return str[ix];
}

//List Initializing the Return Value

//the list is used to initialize the temporary that represents the function's return.
//If the value is empty, that temporary is value initialized. Otherwise, the value of the return depends on the function's return type.

std::vector<std::string> process(const std::string& expected,const std::string& actual)
{
    if (expected.empty())
        return {};
    if (expected == actual)
        return {};
    else
        return{ "FunctionX",expected,actual };
}

//Recursion//�ݹ�
int factorial(unsigned int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

//6.3.3 Returning a Pointer to an Array

using arrT = std::string[10];

arrT& strFunc2(std::string(&arr)[10])
{

}

int arr[10];
int* p1[10];
int(*p2)[10];//it points to an array of ten ints
//The form of a function that returns a pointer to an array is:
//Type (*function(parameter_list))[dimension]
int (*func(int (&arr)[10]))[10]
{
    arr[2] = 12;
    return &arr;
}
//You can also use a trailing return type.
auto function(int (&arr)[]) -> int(*)[]
{

    return &arr;
}
//and of course decltype
int odd[] = { 1,3,5,7,9 };
int even[] = { 2,4,6,8,10 };

decltype(odd)* arrPtr(int i)
{
    return (i % 2 == 0) ? &odd : &even;
}

//the return type for arrPtr uses decltype to say that the function returns a pointer to whatever type odd has. That object is an array,
//so arrPtr returns a pointer to an array of five ints. The only tricky part is that we must remember that decltype does not automatically
//convert an array to its corresponding pointer type. The type returned by decltype is an array type, to which we must add a * to indicate
//that addPtr returns a pointer

int(*funct(int (&arr)[10][]))[10][]
{
    arr[1][9] = 10;

    return &arr;
}

//Calling an Overload Function

int main()
{
    std::string s("Hello");
    get_val(s, 2) = 'B';
    std::cout << s << std::endl;

    std::string expectSituation = "Hello";
    std::string actualSituation = "Hell";
    std::vector<std::string> ExceptionList = process(expectSituation, actualSituation);
    std::cout << factorial(5) << std::endl;

    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    func(arr);
    for (auto elem: arr)
    {
        std::cout << elem << std::endl;
    }

    //Return from main
    //The main func allowed to terminate without a return. If control reaches the end of main and no return detected, the compiler will implicitly inserts a return of 0;

    bool isError = 0;
    if(isError)
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}