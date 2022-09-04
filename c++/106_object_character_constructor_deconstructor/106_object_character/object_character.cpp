#include "iostream"
using namespace std;
#include "string"

class Person{

public:
	Person()  //unreferenced Constuctor: system offers
	{
		cout << "default constructor calling " << endl;
     }
    Person(int a )  //referenced Constuctor. 
	{  
		age = a;
		cout << "reference constructor " << endl;
    }

    Person(const Person &p) // const ��֤�������ı��������ı䣬 &����������ÿ���
	{   
		cout << "copy constructor " << endl;
		age = p.age;  // �����������ȫ�����Ƶ��˶�Ӧ��������
	}

	~Person()  //dedestructor
	{
		cout << "destructor calling " << endl;
	}

	int age;
};

void test01()
{   
	//1. bracket
	//Person p;  // Ĭ�Ϲ��캯������
	//Person P2(10); // reference constructor calling
	//Person P3(P2); // copy constructor calling 

	//cout << "p2's age is: " << P2.age << endl;
	//Person p1(); // test, default constructor with brackets around


	//2. explicit
	//Person p1;
	//Person p2 = Person(10); // reference constructor
	//Person p3 = Person(p2);
	//Person(10); //anonymous object, after this executation, system will recycle the anonymous object immediately when finish execuation
	//Person(p3); // Person(p3) === Person p3; this is an error: redefine error, complier will regard this as a object statement(��������)

	//3. implicit
	Person p4 = 10;  // Person p4  = Person(10);
	Person p5 = p4;  // copy constructor Person p5 = Person(p4)
}

int main()
{
	test01();
	/*Person p;*/
	system("pause");
	return 0;
}















































