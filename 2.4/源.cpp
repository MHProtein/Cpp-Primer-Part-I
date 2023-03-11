#include <iostream>
#include "myheader.h"

//��������������ļ���ÿ������const������ļ��������ܷ��ʵ����ĳ�ʼֵ���У�Ҫ������һ�㣬 ������ÿһ���õ��ñ������ļ��зֱ����˶����ı���
//��ʱ��������һ��const���������ĳ�ʼֵ����һ���������ʽ������ȷʵ�б�Ҫ���ļ��乲������������£����ǲ�ϣ��������Ϊÿһ���ļ��ֱ����ɶ����ı������෴��������������const�������������ǳ�����
//����һ��������Ҳ����˵��ֻ��һ���ļ��ж���const������������������ļ���������ʹ����,��������ǣ�
extern const int internalVal = 10;
//��ΪinternalVal��һ��������������extern�޶�ʹ�䱻�����ļ�ʹ��
//������ڶ���ļ�֮�乲��const���󣬱����ڱ����Ķ���֮ǰ���extern�ؼ���


int get_size()
{
    int x = 0;
    //std::cin >> x;
    return x;
}

int main()
{
	//2.4.1 reference to const
    const int ci = 1024;
    const int& ri = ci;

    int i = 42;
    const int& r1 = i;
    const int& r2 = 42;
    const int& r3 = r1 * 2;

    double dval = 3.14;
    //what the compiler does
    //const int temp = dval;
    //const int& rd = temp;
    const int& rd = dval;

    int j = 10;
    int& rr = j;
    const int& rrr = rr;
    rr = 1;
    std::cout << rr << " " << rrr << std::endl;
    //�������ý������ÿɲ���Ĳ����������޶����������õĶ������ǲ���һ������δ���޶�
    //��Ϊ��������Ǹ��ǳ�������������ͨ�������������ı�����ֵ


    //2.4.2 pointer to const
    const double pi = 3.14;
    const double* ppi = &pi;

    double doubleval = 3.111111111;
    const double* p1 = &doubleval;//they thought they are pointing at a const, so they won't change a "const" 's value
    //����ͨ�����������ı�doubleval��ֵ

    //cosnt pointer
    int errNum = 0;
    int* const pten = &errNum;
    const double pii = 3.14;
    const double* const pip = &pii;

    //2.4.3 top-level const
    //top-level const means the pointer itself is a const
    //����const���Ա�ʾ�κεĶ����ǳ�������һ����κ��������Ͷ�����
    //low-level const meas the value that the pointer points at is a const
    //�ײ�const����ָ������õȸ������͵Ļ������Ͳ����й�

    const int* const p = &errNum;
    //�ײ�const //����const
    //���п�������ʱ������const���Ժ��ԣ����ײ�const���뱣��һ��
    const int a = 0;

    //���õ�const���ǵײ�const

    //2.4.4 constexpr �ͳ������ʽ
    //�������ʽ��ֵָ����ı䲢���ڱ�������о��ܵõ��������ı��ʽ
    //����ֵ���ڳ������ʽ���ó������ʽ��ʼ����const������Ҳ�ǳ������ʽ

    const int sz = get_size();
    //sz�����Ǹ������������ľ���ֱֵ������ʱ���ܻ�ȡ�������Բ��ǳ������ʽ

    //constexpr���Ϳ����ñ���������֤����ֵ�Ƿ���һ���������ʽ������Ϊconstexpr�ı���һ����һ�����������ұ����ó������ʽ��ʼ��
    constexpr int a = 1;
    constexpr int aa = pii * 10;
    //constexpr int aaa = get_size();
    //����aaa������һ���������ʽ
    //������һ��constexpr�ĺ�������������

    ////һ����˵ ����϶�������һ���������ʽ���ǾͰ�������Ϊconstexpr����

    //���ʹ��cosntexpr������һ��ָ�� constexprֻ��ָ����Ч����ָ��Ķ����ֵ�޹�
    int integer = 10;
    constexpr int* q = &integer;
    integer = 1000;
    

    return 0;

}
