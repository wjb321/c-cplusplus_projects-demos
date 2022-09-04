#include "iostream"
using namespace std;
#include "string"

class Person{

public:
	Person(){}
	static void func()
	{
		cout << "static void function" << endl;
		/*
		�Ǿ�̬��Ա������Ϊû�а취�������m_C ����˭�����Իᱨ��
		*/
		//m_C = 233;  // �Ǿ�̬��Ա����̬��Ա�����޷�����
		m_A = 170; // ��̬�������ľ�̬��Ա����
	}

	static int m_A;
	int m_C;
	//int m_B;
private:
	static int m_B;
	static void func2()
	{
		cout << "static void func2 calling" << endl;
	}


};

int Person::m_A = 0; //����������Ծ�̬��Ա�������г�ʼ��
int Person::m_B = 0; //����������Ծ�̬��Ա�������г�ʼ��


void test01()
{   
	Person p;
	cout << p.m_A << endl;
    p.func();

	Person p2;
	p2.m_A = 200;
	cout << p2.m_A << endl;

	Person::func(); // double colons calling function with class name
	//Person::func2();  // class person can not call private func2()
}


void test02()
{
	//ͨ��������з���
	Person p;
	cout << p.m_A << endl;
	// ͨ���������з���
	cout << Person::m_A << endl; // ��̬��Ա��������ͨ���������з���
	//cout << Person::m_B << endl; // ��̬��Ա��������ͨ���������з���

}

int main()
{
	test01();
	//test02();
	system("pause");
	return 0;
}















































