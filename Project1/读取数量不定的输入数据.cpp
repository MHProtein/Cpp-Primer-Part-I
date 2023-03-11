#include <iostream>

int main1()
{
	//读取数量不定的输入数据

	int sum = 0, value = 0;
	//EOF即Ctrl+Z
//读取数值直到遇到文件结尾或读入错误->使条件变为false
	while (std::cin >> value)
	{
		sum += value;
	}
	std::cout << sum << std::endl;

	return 0;
}