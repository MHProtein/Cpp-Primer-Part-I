#include <iostream>
#include <string>
#include <cctype>

int main()
{
    //3.2.1
    //several ways to initialize string
    std::string s1= "hi";
    std::string s2(s1);
    std::string s3 = s1;
    std::string s4("value");
    std::string s5(10, 'c');

    //copy initialization and direct initialization
    //���ʹ�õȺų�ʼ��һ��������ʵ����ִ�е���copy initialization���������ѵȺ��ұߵĳ�ʼֵ�������´����Ķ�����ȥ
    //�����ʹ�õȺţ���ִ�е���ֱ�ӳ�ʼ��

    std::string s6 = "hiya";//copy initialization
    std::string s7("hiya");//direct initialization

    //3.3.2
    //��дstring����
    std::string s;
    //std::cin >> s;
    //��ȡδ֪������string����
    std::string word;
    while (std::cin >> word)
        std::cout << word << std::endl;
    //use getline to read a whole line
    getline(std::cin, s);

    //std::string::size_type
    decltype(s.size()) sz = 10;//s.size() returns the std::string::size_type type
    std::string::size_type szz = 100;
    auto szzz = s.size();
    //����һ���޷������͵�ֵ�������ܴ�����κ�string����Ĵ�С�����ڴ��string��size�����ķ���ֵ���������������͵�
    //���һ�����ʽ���Ѿ�����size���������Ͳ�Ҫ��ʹ��int�ˣ��������Ա���int��unsigned���ÿ��ܴ���������
    //unsigned �� int�Ƚ�ʱ��int��ת��Ϊunsigned���бȽ�

    //����ֵ��string�������
    //��Ϊ�ַ�������ֵ����string���ͣ����������ַ�������ֵ�������
    //string s8="hello"+" "+s7;����
    std::string s0 = "Hello" + (" " + s7);

    //3.2.3 ����string�����е��ַ�
    isalnum(s[0]);//Ϊ��ĸ�������Ƿ���true
    isalpha(s[0]);//Ϊ��ĸ�Ƿ���true
    iscntrl(s[0]);//Ϊ�����ַ��Ƿ���true
    isdigit(s[0]);//Ϊ������Ϊtrue
    isgraph(s[0]);//���ǿո񵫿ɴ�ӡ��Ϊtrue
    islower(s[0]);
    isupper(s[0]);
    isprint(s[0]);//Ϊ�ɴ�ӡ�ַ�ʱΪ�棨��c�ǿո��c���п�����ʽ��
    ispunct(s[0]);//Ϊ��������Ϊ��
    isspace(s[0]);//�հ�ʱΪ�棨��c�ǿո�\t��\v��enter��\n����ֽ���е�һ�֣�
    isxdigit(s[0]);//Ϊ16����ʱΪ��
    tolower(s[0]);
    toupper(s[0]);

    for(auto& elem:s)
    {
        elem = toupper(elem);
    }

    //ʹ���±�ִ�е���
    for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
    {
        //���±�����Ϊstd::string::size_type�������±��ֵС��0��ֻ�豣֤�±��ֵ<s.size������ֵ����
    }

    for(std::string::iterator it=s.begin();it!=s.end();++it)
    {
        //forѭ���У�i++�ȷ���i��ֵ������i��������ÿ��forѭ���ж��Ứ�Ѷ�����ڴ��ʱ��ȥ�����µ���ʱ�����ռ���ת�棬Ч�ʸ���
        //++i��ֱ�ӽ�i�������ٷ��أ�ʡȥ�˿����µ���ʱ�����Ķ������ģ�����Ч�ʱ�i++��
    }

    return 0;
}