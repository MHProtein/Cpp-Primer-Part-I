#include <iostream>

int main()
{

	//2.3.1reference(left value reference)/左值引用
	int ival = 1024;
	int& refval = ival;
	//a reference must be initialized
	//a reference is NOT an object, instead, it's just another name of an existing object

	std::cout << ival << " " << refval << std::endl;//1024 1024
	refval = 10;
	std::cout << ival << " " << refval << std::endl; //10 10
	//为引用赋值，实际上是把值赋给了与引用绑定的对象。获取引用的值实际上是获取了与引用绑定对象的值。
	//同理 以引用最为初始值，实际上是以与引用绑定的对象作为初始值
	//因为引用本身不是一个对象，所以不能定义引用的引用


	//2.3.2 pointer
	//与引用的不同
	//1、指针本身就是一个对象，允许对指针赋值和拷贝，而且在指针的生命周期内它可以先后指向几个不同的对象
	//2、指针无需在定义时赋值 在块作用域定义的指针如果没有被初始化也将拥有一个不确定的值

	int val = 10;
	int* valPointer = &val;

	//指针值
	//指针的值应属下列状态之一
	//1、指向一个对象
	//2、指向紧邻对象所占空间的下一位置
	//3、空指针
	//4、无效指针，即上述情况之外其他值

	std::cout << *valPointer << std::endl;
	*valPointer = 0;
	std::cout << *valPointer << std::endl;
	//*解引用，为*valPointer赋值其实是为val赋值

	//null pointer不指向任何对象，在使用指针之前应该先检查它是否为空
	int* p1=nullptr;//==>int* p1 = 0;
	int* p2 = 0;		//直接将p2初始化为字面常量0  尽量避免使用
	int* p3 = NULL;//==>int* p3 = 0; 尽量避免使用
	//不能直接把int型变量赋值给指针

	if(!p1)
	{
		std::cout << p1 << std::endl;
	}

	double obj = 3.14;
	double* ptr = &obj;
	void* voidPtr = ptr;
	std::cout << voidPtr << std::endl;
	//void*不能直接操作指针所指向的对象，因为我们并不知道这个对象是什么类型，也无法确定能在这个对象上做哪些操作
	//从void*的视角来看，内存空间就仅仅是内存空间没办法访问内存空间所存的对象

	//2.3.3
	//指向指针的引用
	int x = 0;
	int* p = &x;
	int*& pp = p;

	return 0;
}