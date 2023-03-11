#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void GetLine(std::vector<std::string>& VECTOR, std::ifstream& in)
{
    while (in)
    {
        std::string temp;
        std::getline(in, temp);
        VECTOR.push_back(temp);
    }
}

void GetWord(std::vector<std::string>& VECTOR, std::ifstream& in)
{
    while (in)
    {
        std::string buf;
        in >> buf;
        VECTOR.push_back(buf);
    }
}

int main2()
{
    std::ifstream in("D:\\C++Primer\\8.2 File Input and Output\\Text1.txt", std::ifstream::in);
    std::vector<std::string> fileVector;
    std::string temp;
    std::string temp2;
    /*GetLine(fileVector, in);
    GetWord(fileVector, in);
    for (auto elem : fileVector)
    {
        std::cout << elem << std::endl;
    }*/

    //8.2.2 File Modes
    //in Open only for input
    //std::fstream::out Open only for output
    //std::fstream::app(append) Seek to the end before every write
    //std::fstream::ate(at the end) Seek to the end immediately after the open
    //std::fstream::trunc Truncate the file //if the file to open exists, it willclear all the content of the file
    //std::fstream::binary Do IO operations in binary mode
    //By default, a file opened in ofstream mode is truncated even if we do not specify trunc.
    //To preserve our contents of a file, either we must also specify app, in which case we can write only at the end of the file, or we must also specify in, in which case the file is open for both input and output
    //By default, files associated with an ifstream are opened in std::fstream::in mode; files associated with a ofstream are opened in std::fstream::out mode; files associated with a fstream are opened in both modes
    std::fstream fstrm("D:\\C++Primer\\8.2 File Input and Output\\Text1.txt", std::fstream::out | std::fstream::in);

    std::ofstream out("D:\\C++Primer\\8.2 File Input and Output\\Text1.txt", std::fstream::app);
    //out << "\nYeah Yeah";
    GetLine(fileVector, in);
    for (auto& elem : fileVector)
    {
        std::cout << elem << std::endl;
    }


}
