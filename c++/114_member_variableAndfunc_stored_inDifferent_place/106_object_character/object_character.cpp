#include "iostream"
using namespace std;
#include "string"

class Person{

	int m_a;
	static int m_b; // ��������Ķ����ϣ���Ϊ��������̬������������Ĵ�С
	//�ǲ���ģ����ǵ���ӱ�����ͱ������� int m_c, �����Ĵ�С�ͻ��ټ�4
	void func(){}//�Ǿ�̬��Ա��������������Ķ�����
	static void func1(){} // ��̬��Ա��������������Ķ�����
};


void test01()
{   
	Person p;
	cout << "size of p = " << sizeof(p) << endl;
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















































