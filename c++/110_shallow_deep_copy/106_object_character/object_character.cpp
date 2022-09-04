#include "iostream"
using namespace std;
#include "string"

class Person{

public:
	Person()  //unreferenced Constuctor: system offers
	{cout << "default constructor calling " << endl;}

	Person(int age, int height)  //parameter Constuctor. 
	{  
		M_age = age; 
		M_height = new int(height); // new ���ص���ָ�����ͣ� ������ĳ�����ָ�����ͣ������� * M_height

		cout << "parameter constructor " << endl;
    }

	Person(const Person & p)
	{
		cout << "copy constructor function is here " << endl;
		M_age = p.M_age;
		//M_height = p.M_height; �����ϵͳ�ṩ��ǳ��������
		M_height = new int(*p.M_height); // �Լ��������������
	}
    
	~Person()  //dedestructor
	{  
		// ��������������ݽ����ͷ�,�淶��
		if (M_height != NULL)
		{
			delete M_height;
			M_height = NULL;
		}
		cout << "destructor calling " << endl;
	}

	int M_age;
	int * M_height;
};

void test01()
{   
	Person p1(18, 170);
	cout << "constructor function age is : " << p1.M_age << " the height is: " << *p1.M_height<< endl;  // pointer should have *
	//�������캯��ֻ�Ǽ򵥵Ľ���Ӧ�Ķ�����и�ֵ����
	Person p2(p1);  // compiler supplies shallow copy in copy constructor function

	cout << "copy constructor function age is: " << p2.M_age << " the height is:" << *p2.M_height << endl;

}

//void test02()
//{
//	Person p(0);
//	//Person p2(p);
//	cout << "p2 age is: " << p.M_age << endl;
//}

int main()
{
	test01();
	//test02();
	/*test03();*/
	/*Person p;*/
	system("pause");
	return 0;
}















































