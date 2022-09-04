#include "iostream"
using namespace std;
#include "string"

class Person{

public:
	Person()  //unreferenced Constuctor: system offers
	{
		cout << "default constructor calling " << endl;

	}

	Person(int age )  //referenced Constuctor. 
	{  
		M_age = age;
		cout << "reference constructor " << endl;

	}

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

void test01()
{   
	//1. bracket
	//Person p;  // Ĭ�Ϲ��캯������
	Person P2(20); // reference constructor calling
	Person P3(P2); // copy constructor calling 

	cout << "p2 age is: " << P2.M_age << endl;
	//Person p1(); // test, default constructor with brackets around


	//2. explicit
	//Person p1;
	//Person p2 = Person(10); // reference constructor
	//Person p3 = Person(p2);
	//Person(10); //anonymous object, after this executation, system will recycle the anonymous object immediately when finish execuation
	//Person(p3); // Person(p3) === Person p3; this is an error: redefine error, complier will regard this as a object statement(��������)

	//3. implicit
	//Person p4 = 10;  // Person p4  = Person(10);
	//Person p5 = p4;  // copy constructor Person p5 = Person(p4)
}

//2. ֵ���ݵķ�ʽ������������ֵ: ��������ʱ�ĸ��������´������һ������
void doWork(Person p) // this p is not same as the p in doWork(p)
{

}
void test02()
{
	Person p;
	doWork(p);
}

//3. ֵ��ʽ���ؾֲ�����
Person doWork2()
{
	Person p1;
	cout << (int *)&p1 << endl;
	return p1;
}

void test03()
{
	Person  p = doWork2();
}
int main()
{
	//test01();
	//test02();
	test03();
	/*Person p;*/
	system("pause");
	return 0;
}















































