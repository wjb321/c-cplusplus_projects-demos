#include "iostream"
using namespace std;
#include "string"

class Person{

public:
	Person(int age)
	{
		this->m_age = age; // ����this ָ��֮�󣬻ᷢ������βκͳ�Ա��������ͬ�ı���ʱ��thisָ���µı���
		                   //��ͳ�Ա����ͬʱ����
	}

	Person& personAddperson(Person &p)  // return void�� �������÷�ʽ���շ���ֵ
	{
		this->m_age += p.m_age;
		return *this; // ����*this
	}
	//�����Ķ��ڳ�Ա�����ı���淶�ǣ����ڳ�Ա����Ӧ���ã�m_a, m_b... ��m_���������������βΣ����繹�캯���е��βΣ�
	int m_age;

	
	
};


void test01()
{   
	Person p(18);
	cout << "the age is" <<p.m_age<< endl;
}


void test02()
{
	Person p1(1);
	Person p2(3);
	/*
	������벻ͣ�ĵ��ú�����ʵ�ֲ�ͣ�ļӼӣ������ҵ����������У���ô��ʱ���Ҫ���Ա��������һ���ĵ�����
	1�� �����Ա������void���ͣ���ô�䲻���ڷ���ֵ����ô��Ȼ���ܽ��г����� . ���ʽ��в��ϵļӼ�
	2.  ���ظĳ�*this�����ʱ�򽫷������ʹ�void�ĳ� Person &(ֵ������)����ô���Ϳ��Բ��ϵļӼ�ͨ�� . ����ʽ,����
	    ����һֱ����p2
	3�� ��������++ �ķ�ʽ���ǽ�����ʽ����������׷�������� <<
	4.  ������������͸ĳ�ֵ����: ��void �ĳ� Person�� ��ÿ�λᴴ���µĶ���p2-> p1 ->....���ڵ��� . ��ʱ��
	*/
	p2.personAddperson(p1).personAddperson(p1);
	cout << "p2 age is:" << p2.m_age << endl;
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}















































