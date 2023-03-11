#include <iostream>

int main()
{

	//2.3.1reference(left value reference)/��ֵ����
	int ival = 1024;
	int& refval = ival;
	//a reference must be initialized
	//a reference is NOT an object, instead, it's just another name of an existing object

	std::cout << ival << " " << refval << std::endl;//1024 1024
	refval = 10;
	std::cout << ival << " " << refval << std::endl; //10 10
	//Ϊ���ø�ֵ��ʵ�����ǰ�ֵ�����������ð󶨵Ķ��󡣻�ȡ���õ�ֵʵ�����ǻ�ȡ�������ð󶨶����ֵ��
	//ͬ�� ��������Ϊ��ʼֵ��ʵ�������������ð󶨵Ķ�����Ϊ��ʼֵ
	//��Ϊ���ñ�����һ���������Բ��ܶ������õ�����


	//2.3.2 pointer
	//�����õĲ�ͬ
	//1��ָ�뱾�����һ�����������ָ�븳ֵ�Ϳ�����������ָ��������������������Ⱥ�ָ�򼸸���ͬ�Ķ���
	//2��ָ�������ڶ���ʱ��ֵ �ڿ����������ָ�����û�б���ʼ��Ҳ��ӵ��һ����ȷ����ֵ

	int val = 10;
	int* valPointer = &val;

	//ָ��ֵ
	//ָ���ֵӦ������״̬֮һ
	//1��ָ��һ������
	//2��ָ����ڶ�����ռ�ռ����һλ��
	//3����ָ��
	//4����Чָ�룬���������֮������ֵ

	std::cout << *valPointer << std::endl;
	*valPointer = 0;
	std::cout << *valPointer << std::endl;
	//*�����ã�Ϊ*valPointer��ֵ��ʵ��Ϊval��ֵ

	//null pointer��ָ���κζ�����ʹ��ָ��֮ǰӦ���ȼ�����Ƿ�Ϊ��
	int* p1=nullptr;//==>int* p1 = 0;
	int* p2 = 0;		//ֱ�ӽ�p2��ʼ��Ϊ���泣��0  ��������ʹ��
	int* p3 = NULL;//==>int* p3 = 0; ��������ʹ��
	//����ֱ�Ӱ�int�ͱ�����ֵ��ָ��

	if(!p1)
	{
		std::cout << p1 << std::endl;
	}

	double obj = 3.14;
	double* ptr = &obj;
	void* voidPtr = ptr;
	std::cout << voidPtr << std::endl;
	//void*����ֱ�Ӳ���ָ����ָ��Ķ�����Ϊ���ǲ���֪�����������ʲô���ͣ�Ҳ�޷�ȷ�������������������Щ����
	//��void*���ӽ��������ڴ�ռ�ͽ������ڴ�ռ�û�취�����ڴ�ռ�����Ķ���

	//2.3.3
	//ָ��ָ�������
	int x = 0;
	int* p = &x;
	int*& pp = p;

	return 0;
}