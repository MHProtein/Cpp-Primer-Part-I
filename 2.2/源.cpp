#include <iostream>

int peopleNumber = 100;

int main()
{
	//初始化不等于赋值
	int units_sold = 0;
	int units_sold2 = { 0 };
	int units_sold3(0);
	int units_sold4{ 0 };

	int i;//declaration
	i = 10;//definition

	//如果你想声明一个变量而并非定义它，在变量名前添加extern关键字，并不要显式初始化变量
	//在函数体内部如果试图初始化一个extern变量将引发错误
	//变量只能被定义此1次但可以被声明多次
	//如果要在多个文件中使用同一个变量就必须把declaration和definition分开
	extern int j;
	int peopleNumber = 10;
	if(1 or 0)
	{
		std::cout << "hi" << std::endl;
	}

	//显式访问全局变量
	//因为全局作用域没有名字，所以当作用域操作符左侧为空时，向全局作用域发出请求获取作用域操作符右侧名字对应的变量
	std::cout << ::peopleNumber << std::endl;
	//访问局部变量
	std::cout << peopleNumber << std::endl;

	return 0;
}