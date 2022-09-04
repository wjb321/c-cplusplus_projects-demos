#include "iostream"
using namespace std;
#include "string"

class Person{

public:
	Person()  //unreferenced Constuctor: system offers
	{cout << "default constructor calling " << endl;}

	Person(int age )  //parameter Constuctor. 
	{  
		M_age = age;
		cout << "reference constructor " << endl;
    }
    
	// �������캯��
    Person(const Person &p) // const ��֤�������ı��������ı䣬 &����������ÿ���
	{   
		cout << "copy constructor " << endl;
		M_age = p.M_age;  // �����������ȫ�����Ƶ��˶�Ӧ��������
	}

	~Person()  //dedestructor
	{
		cout << "destructor calling " << endl;
	}

	int M_age;
};

//void test01()
//{   
//	//1. bracket
//	Person p;  // Ĭ�Ϲ��캯������
//	p.M_age = 18;
//	Person P2(p); // reference constructor calling
//	cout << "p2 age is: " << P2.M_age << endl;
//
//}

void test02()
{
	Person p(0);
	//Person p2(p);
	cout << "p2 age is: " << p.M_age << endl;
}

int main()
{
	//test01();
	test02();
	/*test03();*/
	/*Person p;*/
	system("pause");
	return 0;
}















































