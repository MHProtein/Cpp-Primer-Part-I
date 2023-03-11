#include <iostream>
#include <string>

bool lengthCompare(const std::string& s1, const std::string& s2)
{
    return (s1.size() > s2.size()) ? true : false;
}

//Functions Pointers parameters
void useBigger(const std::string& s1,const std::string& s2,bool (*pf)(const std::string& , const std::string&))
{
    
}

void useSmaller(const std::string& s1, const std::string& s2, bool pf(const std::string&, const std::string&));
//though without a * sign it will be treated as a pointer

//maybe you can try to use typedef and decltype
typedef decltype(lengthCompare) Func;
void useBigger2(const std::string& s1, const std::string& s2, Func)
{

}

//Returning a Pointer to Function
using F = int(int*, int); //Function type
using PF = int(*)(int*, int); //Pointer type
F* f1(int i);
PF f2(int i);
int (*f3(int i))(int*, int);
auto f4(int i) -> int(*)(int*, int);

//if we know which function we wanna return, we can use decltype to simplify writing a function pointer return type
std::string::size_type sumLength(const std::string& s1, const std::string& s2);
std::string::size_type largerLength(const std::string& s1, const std::string& s2);
decltype(sumLength)* getFunc(const std::string& s);

std::string::size_type (*getFunction(const std::string& s))(const std::string& s1, const std::string& s2);


int main() {
    bool (*pf)(const std::string & s1, const std::string & s2);//It's actually a pointer
    pf = lengthCompare;
    pf = &lengthCompare;//same as the upper statement
    //You can use the name of a function as a value, the function is automatically converted to a pointer

    //You can use a pointer to a function to which the pointer points and you don't have to dereference it
    bool b1 = pf("hello", "goodbye");
    bool b2=(*pf)("hello", "goodbye");
    bool b3 = lengthCompare("hello", "goodbye");

    //When we pass a function as an argument, we can do so directly. it will be automatically converted to a pointer
    useBigger("hello", "goodbye", lengthCompare);

}