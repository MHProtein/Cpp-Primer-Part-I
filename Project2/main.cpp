#include <iostream>
#include <iterator>
#include <cstddef>

int main()
{
    int a[3][4] = { 0 };//x,y
    int b[10][20][30] = { 0 };//z=10,x=20,y=30;

    int(&row)[4] = a[1];//attach row to a's second line with four elements

    constexpr size_t rowCount = 10, colCount = 20;//column
    int array[rowCount][colCount] = { 0 };
    for (size_t i = 0; i != rowCount; ++i)
        for (size_t j = 0; j != colCount; ++j)
            array[i][j] = i * colCount + j;

    for (const auto& row : array)  //to avoid the array be automatically transformed to a pointer
    {
        for (auto column : row)
        {
            std::cout << column << " ";
        }
        std::cout << std::endl;
    }

    for(auto it=std::begin(array);it!=std::end(array);++it)
    { 
        for(int* it2=std::begin(*it);it2!=std::end(*it);++it2)
        {
            std::cout << *it2 << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}