#include <functional>
#include <iostream>
#include <string>

class ErrCode
{
public:
    ErrCode(){};
    ErrCode(int err_num) :errNum(err_num){}
    int msg()
    {
        return this->errNum;
    }
private:
    int errNum;
};

void errorWarning(ErrCode err_code, const std::initializer_list<std::string>& error_list)
{
    std::cout << err_code.msg() << std::endl;
    for (const auto& error : error_list)
    {
        std::cout << error << std::endl;
    }
}

//main: 处理命令行选项
int main(int argc, std::string argv[])
{//argc表示数组中字符串数量，第二个形参argv是个数组
    //若在命令行输入 prog -d -o ofile data0
    //argv[0] = "prog";//或argv[0]可能指向一个空字符串
    //argv[1] = "-d";
    //argv[2] = "-o";
    //argv[3] = "ofile";
    //argv[4] = "data0";
    //当使用argv的实参时，可选的实参从argv[1]开始，argv[0]保存程序的名字，而非用户输入
    for (size_t i = 1; i != argc; ++i)
    {
        std::cout << argv[i] << std::endl;
    }

    //6.2.6 含有可变形参的函数
    //有时我们无法提前预知应该向函数传递几个实参，例如，我们想要编写代码输出程序输出程序产生的错误信息，此时最好用同一个函数实现该项功能，以便对所有错误的处理能够整齐划一
    //然而 错误信息的种类不同，调用错误输出函数时传递的实参也各不相同

    //initializer_list
    std::initializer_list<std::string> errorList;

    std::string expected("hello");
    std::string actual("world");



    if (expected != actual)
        errorWarning(ErrCode(42), { "hello"," and ","FUCK YOU" });
    else
        errorWarning(ErrCode(0), { "hello"," and ","LOVE YOU" });




    return 0;
}

