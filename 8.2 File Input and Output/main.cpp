#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <ostream>
#include "D:\C++Primer\7.1 Defining Abstract Data Types\Sales_data.h"

int main(std::string argv[],size_t argc)
{
    std::fstream fstrm;
    std::fstream fstrm2("D:\\C++Primer\\8.2 File Input and Output\\Text1.txt");
    std::fstream fstrm3("D:\\C++Primer\\8.2 File Input and Output\\Text1.txt", std::fstream::binary);
    fstrm.open("D:\\C++Primer\\8.2 File Input and Output\\Text1.txt");
    fstrm.close();
    std::cout << fstrm.is_open() << std::endl;

    std::ifstream in("D:\\C++Primer\\8.2 File Input and Output\\Text1.txt");
    std::ofstream out("D:\C++Primer\\8.2 File Input and Output\\Text1.txt");

    for (auto p = argv + 1; p != argv + argc; ++p)
    {
        std::ifstream input(*p);
        if (input)
        {
            ;
        }
        else
            std::cerr << "error" << std::endl;
    }// input goes out of scope and is destroyed on each iteration
    //in the next iteration, input will be created again

    //when a n fstream object is destoryed, close is called automatically
}