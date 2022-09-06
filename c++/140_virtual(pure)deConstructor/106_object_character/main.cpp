#include "iostream"
#include "string"
using namespace std;
class Animal
{
public:
	Animal()
	{
		cout << " animal constructor " << endl;
	}
	virtual void speak() = 0;

	// 1. virtual destructor
	//virtual ~Animal()
	//{
	//	cout << " animal virtual destructor " << endl;
	//}
	
	//2. pure virtual deconstructor
	//it needs declaraion and impletement, impletement happend
	//cause it is a pure virtual decontructor, so it can not instantiate
	//destructor or pure virtual:����������е�����������ò��������⣬�������࿪���˶�����
	virtual ~Animal() = 0;
};

Animal::~Animal() 
{
	cout << " animal pure destructor " << endl;
}

class cat :public Animal
{
public:
	cat(string name)
	{   
		cout << " cat constructor " << endl;
		m_name = new string(name);  // heap new a attribute, how to free that 
	}
	virtual void speak()
	{
		cout << *m_name << " is miao miao miao" << endl;
	}
	~cat()
	{
		if (m_name != NULL)
		{  
			cout << " cat destructor " << endl;
			delete m_name;
			m_name = NULL;
		}
	}
	string *m_name; 
};

void React()
{
	Animal * ani = new cat("tom"); 
	ani->speak();
   // ����ָ��������ʱ�򲻻���������е�������������������������ж������ԣ��ͻᵼ���ڴ�й¶
	// ����취�����ڸ��������������virtual �ؼ���
	delete ani;
}
void test01()
{   
	React();
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















































