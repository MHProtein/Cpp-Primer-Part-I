#include <functional>
#include <iostream>
#include <string>

class ErrCode
{
public:
    ErrCode(){};
    ErrCode(int err_num) :errNum(err_num){}
    int msg()
    {
        return this->errNum;
    }
private:
    int errNum;
};

void errorWarning(ErrCode err_code, const std::initializer_list<std::string>& error_list)
{
    std::cout << err_code.msg() << std::endl;
    for (const auto& error : error_list)
    {
        std::cout << error << std::endl;
    }
}

//main: ����������ѡ��
int main(int argc, std::string argv[])
{//argc��ʾ�������ַ����������ڶ����β�argv�Ǹ�����
    //�������������� prog -d -o ofile data0
    //argv[0] = "prog";//��argv[0]����ָ��һ�����ַ���
    //argv[1] = "-d";
    //argv[2] = "-o";
    //argv[3] = "ofile";
    //argv[4] = "data0";
    //��ʹ��argv��ʵ��ʱ����ѡ��ʵ�δ�argv[1]��ʼ��argv[0]�����������֣������û�����
    for (size_t i = 1; i != argc; ++i)
    {
        std::cout << argv[i] << std::endl;
    }

    //6.2.6 ���пɱ��βεĺ���
    //��ʱ�����޷���ǰԤ֪Ӧ���������ݼ���ʵ�Σ����磬������Ҫ��д����������������������Ĵ�����Ϣ����ʱ�����ͬһ������ʵ�ָ���ܣ��Ա�����д���Ĵ����ܹ����뻮һ
    //Ȼ�� ������Ϣ�����಻ͬ�����ô����������ʱ���ݵ�ʵ��Ҳ������ͬ

    //initializer_list
    std::initializer_list<std::string> errorList;

    std::string expected("hello");
    std::string actual("world");



    if (expected != actual)
        errorWarning(ErrCode(42), { "hello"," and ","FUCK YOU" });
    else
        errorWarning(ErrCode(0), { "hello"," and ","LOVE YOU" });




    return 0;
}

