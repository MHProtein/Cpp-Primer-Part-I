#include <iostream>

int peopleNumber = 100;

int main()
{
	//��ʼ�������ڸ�ֵ
	int units_sold = 0;
	int units_sold2 = { 0 };
	int units_sold3(0);
	int units_sold4{ 0 };

	int i;//declaration
	i = 10;//definition

	//�����������һ�����������Ƕ��������ڱ�����ǰ���extern�ؼ��֣�����Ҫ��ʽ��ʼ������
	//�ں������ڲ������ͼ��ʼ��һ��extern��������������
	//����ֻ�ܱ������1�ε����Ա��������
	//���Ҫ�ڶ���ļ���ʹ��ͬһ�������ͱ����declaration��definition�ֿ�
	extern int j;
	int peopleNumber = 10;
	if(1 or 0)
	{
		std::cout << "hi" << std::endl;
	}

	//��ʽ����ȫ�ֱ���
	//��Ϊȫ��������û�����֣����Ե���������������Ϊ��ʱ����ȫ�������򷢳������ȡ������������Ҳ����ֶ�Ӧ�ı���
	std::cout << ::peopleNumber << std::endl;
	//���ʾֲ�����
	std::cout << peopleNumber << std::endl;

	return 0;
}