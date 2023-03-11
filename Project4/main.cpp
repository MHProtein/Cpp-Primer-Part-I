#include <iostream>

void print1(const int* arr)
{
    for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}

void print2(const int arr[])
{
    for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}

void print3(const int arr[10])
{
    for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}

void print4(const int (*arr)[])
{
    for(size_t i=0;i<sizeof(arr)/sizeof(&arr[0]);++i)
    {
    }
}