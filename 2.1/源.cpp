#include <iostream>

int main()
{
	/*
	 *
	 *���ѡ�����
	 *
	 *1.����ȷ������Ϊ��ʱ��ѡ��unsigned����
	 *
	 *2.����ֵ����int���͵ı�ʾ��Χ��ѡ��long long
	 *
	 *3.���������ʽ�в�Ҫʹ��char��bool���ͣ�ֻ���ڴ���ַ��򲼶�ֵ��ʱ���ʹ�����ǡ���Ϊchar������һЩ���������з��ŵģ�������һЩ���������޷��ŵģ�����
	 *ʹ��char���ͽ��������ر����׳����⣬�������Ҫʹ��һ���������������Ҫָ������������signed char ����unsigned char
	 *
	 *4.ִ�и���������ʱѡ��double����Ϊfloatͨ�����Ȳ�������˫���ȸ���ֵ�����ٶȿ���>=����������
	 *
	 */



	//ǰ׺
	//u->Unicode16 character->char16_t
	std::cout << u'a' << std::endl;
	//U->Unicode32 character->char32_t
	std::cout << U'b' << std::endl;
	//L->wide character->wchar_t
	std::cout << L'c' << std::endl;
	//u8->UTF-8(Only used in string iteral(�������ͳ�����)->char
	std::cout << u8'd' << std::endl;
	//��׺
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