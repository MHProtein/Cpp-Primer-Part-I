#include <iostream>

int main1()
{
	//��ȡ������������������

	int sum = 0, value = 0;
	//EOF��Ctrl+Z
//��ȡ��ֱֵ�������ļ���β��������->ʹ������Ϊfalse
	while (std::cin >> value)
	{
		sum += value;
	}
	std::cout << sum << std::endl;

	return 0;
}