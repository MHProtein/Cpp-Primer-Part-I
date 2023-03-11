#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <graphics.h>
#include <cassert>


//6.5.1 Default Arguments
//we want a default size of screen if our user don't customize it
std::string screen(std::string::size_type width=1920,std::string::size_type height=1080,COLOR16 color=0)
{
    return "fdf";
}

//Default Argument Initializers
//Local variables can not be used as default argument. Excepting that restriction, as long as a expression can be converted to the type of the parameter it could be used as a default argument
int wd = 80;
char def = ' ';
int ht() { return 1; }
std::string screen2(int = ht(),int =wd,char=def)
{
    
}
//and these default arguments can be changed
void f2()
{
    ::wd = 10;
    ::def = 'a';
    std::string window = screen2();
}

//6.5.2 Inline and constexpr Functions
//calling a function is apt to//normally be slower than evaluating the equivalent expression.
//On most machines, a function call does a lot of work: Registers are saved before the call and restored after the return;
//arguments may be copied; and the program branches to a new location

//inline Functions Avoid Function Call Overhead//避免函数调用的开销

inline const std::string& shorterString(const std::string& s1,const std::string& s2)
{
    return (s1.size() > s2.size()) ? s2 : s1;
}

//this is how the compiler will do when calling an inline function
//std::cout<<shorterString(s1, s2)<<std::endl;
//std::cout<<  (s1.size() > s2.size()) ? s2 : s1 <<std::endl;

//The inline specification is only a request to the compiler. The compiler may choose to ignore it.

//In general the inline mechanism is meant to optimize small, straight-line functions that are called frequently
//And most compilers will not inline a recursive function//递归函数

//constexpr function
//To define a constexpr function, follow the rule below:
//Make sure the return type and the type of each parameter in a must be a literal type, and the function body must contain exactly one return statement

constexpr int new_sz() { return 42; }
constexpr int foo = new_sz();

//In order to be able to expand the function immediately, constexpr functions are implicitly inline

constexpr size_t scale(size_t cnt) { return cnt * new_sz(); }
int i = 10;
//size_t s[scale(i)]; //error: scale(i) is not a constant expression
//constexpr function is not required to return a constant expression

//Put inline and constexpr functions In Header Files
//Their multiple definitions must be same

//6.5.3 Aids for Debugging

//The assert Preprocessor Macro
//assert(expr)
//if expr==false, the assert macro will write a message and terminate the program.Else it does nothing

//The NDEBUG Preprocessor Macro



int main()
{
    screen();
    screen(3840);
    screen(2560, 1440);
    //screen(, , 12); You can only omit//忽略 trailing arguments

}