#include "GradesClassify.h"
#include <iostream>
#include <vector>

void GradesClassify::GradesClassification()
{
    std::vector<int> Statistics(11, 0);
    int grades = 0;
    while(std::cin>>grades)
    {
        ++Statistics[grades / 10];
    }
    for (auto elem : Statistics)
        std::cout << elem << " ";
}
