#include <iostream>
#include <ostream>
#include <istream>

int main()
{
	//Standard Error
	std::cerr << __ExceptionPtrAssign << std::endl;
	std::clog << "log" << std::endl;
	std::cout << "helloworld" << std::endl;
	/*
	 * <<左侧的对象必须是一个ostream对象，右侧的对象则是要打印的值，此运算符将给定的值写入到ostream对象即cout中
	 * 输出运算符的计算结果就是其左侧的运算对象，即计算结果就是我们写入给定值的那个ostream对象
	 */
	(std::cout << "hi") << " there" << std::endl;
	/*
	 *endl是一个被称为操纵符manipulator的特殊值。
	 *功能:换行并将buffer（缓冲区）的内容刷到设备中
	 *可以保证目前为止程序所产生的所有输出都真正写入输出流中而不是仅停留在内存中等待写入流
	 */
	std::cout << std::endl << std::endl;

	int v1 = 0, v2 = 0;
	/*
	 * >>接受一个istream作为其左侧的运算对象，接受一个对象作为其右侧的运算对象，他从给定的istream对象读取数据，并存入给定对象中。返回&istream
	 */
	std::cin >> v1 >> v2;
	(std::cin >> v1) >> v2;
}

