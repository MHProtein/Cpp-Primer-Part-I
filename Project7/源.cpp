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
	 * <<���Ķ��������һ��ostream�����Ҳ�Ķ�������Ҫ��ӡ��ֵ�����������������ֵд�뵽ostream����cout��
	 * ���������ļ���������������������󣬼���������������д�����ֵ���Ǹ�ostream����
	 */
	(std::cout << "hi") << " there" << std::endl;
	/*
	 *endl��һ������Ϊ���ݷ�manipulator������ֵ��
	 *����:���в���buffer����������������ˢ���豸��
	 *���Ա�֤ĿǰΪֹ�������������������������д��������ж����ǽ�ͣ�����ڴ��еȴ�д����
	 */
	std::cout << std::endl << std::endl;

	int v1 = 0, v2 = 0;
	/*
	 * >>����һ��istream��Ϊ������������󣬽���һ��������Ϊ���Ҳ������������Ӹ�����istream�����ȡ���ݣ���������������С�����&istream
	 */
	std::cin >> v1 >> v2;
	(std::cin >> v1) >> v2;
}

