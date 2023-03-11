#include <iostream>

int main()
{
	/*
	 *
	 *如何选择变量
	 *
	 *1.当明确不可能为负时，选用unsigned类型
	 *
	 *2.若数值超过int类型的表示范围，选用long long
	 *
	 *3.在算数表达式中不要使用char和bool类型，只有在存放字符或布尔值的时候才使用它们。因为char类型在一些机器上是有符号的，而在另一些机器上是无符号的，所以
	 *使用char类型进行运算特别容易出问题，如果你需要使用一个不大的整数，需要指明它的类型是signed char 还是unsigned char
	 *
	 *4.执行浮点数运算时选用double，因为float通常精度不够而且双精度浮点值计算速度可能>=单浮点类型
	 *
	 */



	//前缀
	//u->Unicode16 character->char16_t
	std::cout << u'a' << std::endl;
	//U->Unicode32 character->char32_t
	std::cout << U'b' << std::endl;
	//L->wide character->wchar_t
	std::cout << L'c' << std::endl;
	//u8->UTF-8(Only used in string iteral(“字面型常量”)->char
	std::cout << u8'd' << std::endl;
	//后缀
	//u or U->unsigned
	std::cout << 123u << std::endl;
	//l or L->long
	std::cout << 1234L << std::endl;
	//ll or LL->long long
	std::cout << 123456LL << " " << 12345678ULL << std::endl;
	//f or F->float
	std::cout << 1.234567f << std::endl;
	
	return 0;
}