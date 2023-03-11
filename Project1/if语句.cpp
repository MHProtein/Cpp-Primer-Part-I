#include <iostream>

int main()
{
	//每个值“”连续“”输入了多少次
	//currVal是我们现在在统计的值，我们将读入的新值存入val
	int currVal = 0, val = 0;
	//读入第一个值 确保有数据可以处理
	if(std::cin>>currVal)
	{
		int cnt = 1;//保存我们正在处理的当前值的个数
		while(std::cin>>val)//读取剩余的数
		{
			if (val == currVal)
				++cnt;
			else
			{
				std::cout << currVal << " occurs " << cnt << " times" << std::endl;
				currVal = val;
				cnt = 1;
			}
		}
		std::cout << currVal << " occurs " << cnt << " times" << std::endl;
	}

	

	return 0;
}