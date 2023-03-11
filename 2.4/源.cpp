#include <iostream>
#include "myheader.h"

//如果程序包含多个文件，每个用了const对象的文件都必须能访问到他的初始值才行，要做到这一点， 必须在每一个用到该变量的文件中分别定义了独立的变量
//有时候有这样一种const变量，他的初始值不是一个常量表达式，但又确实有必要在文件间共享。在这种情况下，我们不希望编译器为每一个文件分别生成独立的变量，相反，我们想让这类const对象像其他（非常量）
//对象一样工作，也就是说，只在一个文件中定义const变量，而在其他多个文件中声明并使用它,解决方法是：
extern const int internalVal = 10;
//因为internalVal是一个常量，必须用extern限定使其被其他文件使用
//如果想在多个文件之间共享const对象，必须在变量的定义之前添加extern关键字


int get_size()
{
    int x = 0;
    //std::cin >> x;
    return x;
}

int main()
{
	//2.4.1 reference to const
    const int ci = 1024;
    const int& ri = ci;

    int i = 42;
    const int& r1 = i;
    const int& r2 = 42;
    const int& r3 = r1 * 2;

    double dval = 3.14;
    //what the compiler does
    //const int temp = dval;
    //const int& rd = temp;
    const int& rd = dval;

    int j = 10;
    int& rr = j;
    const int& rrr = rr;
    rr = 1;
    std::cout << rr << " " << rrr << std::endl;
    //常量引用仅对引用可参与的操作做出了限定，对于引用的对象本身是不是一个常量未作限定
    //因为对象可能是个非常量，所以允许通过其他渠道来改变他的值


    //2.4.2 pointer to const
    const double pi = 3.14;
    const double* ppi = &pi;

    double doubleval = 3.111111111;
    const double* p1 = &doubleval;//they thought they are pointing at a const, so they won't change a "const" 's value
    //不能通过解引用来改变doubleval的值

    //cosnt pointer
    int errNum = 0;
    int* const pten = &errNum;
    const double pii = 3.14;
    const double* const pip = &pii;

    //2.4.3 top-level const
    //top-level const means the pointer itself is a const
    //顶层const可以表示任何的对象是常量，这一点对任何数据类型都适用
    //low-level const meas the value that the pointer points at is a const
    //底层const则与指针和引用等复合类型的基本类型部分有关

    const int* const p = &errNum;
    //底层const //顶层const
    //进行拷贝操作时，顶层const可以忽略，但底层const必须保持一致
    const int a = 0;

    //引用的const都是底层const

    //2.4.4 constexpr 和常量表达式
    //常量表达式是指值不会改变并且在编译过程中就能得到计算结果的表达式
    //字面值属于常量表达式，用常量表达式初始化的const对象是也是常量表达式

    const int sz = get_size();
    //sz本身是个常量，但它的具体值直到运行时才能获取到，所以不是常量表达式

    //constexpr类型可以让编译器来验证变量值是否是一个常量表达式，声明为constexpr的变量一定是一个常量，而且必须用常量表达式初始化
    constexpr int a = 1;
    constexpr int aa = pii * 10;
    //constexpr int aaa = get_size();
    //报错：aaa并不是一个常量表达式
    //允许定义一种constexpr的函数来满足条件

    ////一般来说 如果认定变量是一个常量表达式，那就把它声明为constexpr类型

    //如果使用cosntexpr定义了一个指针 constexpr只对指针有效，与指向的对象的值无关
    int integer = 10;
    constexpr int* q = &integer;
    integer = 1000;
    

    return 0;

}
