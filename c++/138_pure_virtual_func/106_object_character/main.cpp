#include "iostream"
#include "string"
using namespace std;
class Base
{
public:
	virtual void func() = 0;  // pure virtual function
	//ֻҪ��һ�����麯������ô�������ǳ�����
	//��������ص㣺
	//1. �޷�ʵ�������� Base b;
	//2. ����Ҫ��д�����еĴ��麯��������Ҳ���ڳ�����

	float m_Num1;
	float m_Num2;
};

class Son :public Base
{
public:
	virtual void func()
	{
		cout << "func is called" << endl;
	}
};

void test01()
{   
	//����̳�
	Son s;
	s.func();

	//��̬���
	//ͨ����ͬ�ĸ���ָ����ö��ֲ�ͬ�Ľӿڣ�����ӿ���ͨ����newһ����Ӧ�ļ̳��࣬Ȼ��
	//���ʶ�Ӧ�̳������µĺ���
	Base * base = new Son;
	base->func();
}


void test02()
{
}

int main()
{
	test01();
	//test02();
	system("pause");
	return 0;
}















































