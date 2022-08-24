#include <iostream>
using namespace std;

#if 0  // example 1
class Shape {
protected:
	int width, height;
public:
	Shape(int a, int b)
	{

		width = a;
		height = b;
	}
	virtual int area() //virtual�� �˴����Զ���Ϊ�麯�����Ӷ������������ܹ����ж�̬���ӣ����ߺ�󶨡�����֮��
		               //          ���ڴ����ǻ��࣬�����������ʱ����Ϊ���Ѿ�������غ��������Ի��Զ���̬���ӵ�
					   //          ������ຯ�����Ӷ���ӡ���󡣵��ǵ����� virtual �ؼ���֮�󣬾Ϳ���ʹ���ˡ�
	{
		cout << "This is parent class area: " << endl;
		return 0;
	}
};

class Rectangle : public Shape{
public:
	Rectangle(int a = 0, int b = 0) :Shape(a, b) {}
	int area()
	{
		cout << "rectangle area is:" << endl;
		return (width * height);
	}

};

class Triangle : public Shape{
public:
	Triangle(int a = 0, int b = 0) : Shape(a, b){}
	int area()
	{
		cout << "circle area is:" << endl;
		return (width * height / 2);
	}
};

int main()
{
	Shape *shape;  //����ָ����
	Rectangle rec(10, 7);  // ���еĺ�����rectangle
	Triangle tri(4, 7);  //triangle ��ʼ��

	shape = &rec; //����rec�ĵ�ַ��ָ���У�Ȼ��ָ��ָ�������ַ��ֵ
	shape->area(); //���ʶ�Ӧ���еĺ�����->

	shape = &tri;
	shape->area();

	return 0;
}

#endif
/*
�����к��� shape() �� area()���������ǵ����м̳е�ʱ��
����������з��ʣ����ڹ��õĺ��� int area() �ǹ��õĺ���
����û���ڻ�������麯���������� virtual int area() �ں���������������������᲻һ����
�˴�
1. virtual function: �������������¶�������ж�����麯��ʱ�򣬻���߱�������Ҫ��̬���ӵ��ú�����
                     ���ῼ���ǲ��������������Ƿ������ͬ����������̬�ԣ�Ӧ�÷���������ĺ�����
2. pure virtual function: ��ʱ����Ҫ�ڻ����ж����麯����Ȼ�󷽱��������������¶���ú����Ӷ����õ���Ӧ���󣬵���
                          �ڸû����ֲ��ܶ��麯�������������ʵ�֣����ʱ�����Ҫʹ�ô��麯��.
						  virtual int area() = 0; ���麯��һ��û�ж��壬���麯�������淶���������Ϊ�����ӿڡ�
						  �������麯�������ǳ����࣬�����಻�ܶ������㣬����������ָ��ʵ�ָó�����ľ������ָ������á�
*/

# if 0 // example 2
class B {
public:
	void b1() // b1 calls b2 function 
	{
		b2();
	}
	virtual void b2()   // virtual function
		{
		cout << "this is b2 in B" << endl;
	}
};

class A : public B
{
public:
	virtual void b2()  // rewrite virtual function again
	{
		cout << "this is b2 from the derived class" << endl;
	}
};

int main()
{
	A *pA = new A;  // here new a class A 
	pA->b1();   // then call this function which derives from class B 
	return 0;
}

# endif 
/*
�麯�����Բ�ʵ�֡���ʵ�ֵĺ����������麯����
��һ�������������δ������麯������ô����ֱ��ʹ�ø����ʵ����������Ϊ��
��Ϊ����δ�����virtual���������ǳ���ģ��޷�ʵ������

������麯�����ߴ��麯��������뱻�̳�ʱ����д����c++11֮�󣬿����ùؼ���
final ������ú����ٴα���д��
���һ���಻ϣ�����̳У���ôҲ��������Ϊ final 

*/

#if 1
class Base{
public:
	virtual void func()
	{
		cout << "base function" << endl;
	}

};

class _base : public Base{
public:
	virtual void func() final
	{
		cout << "this is the first time derived class" << endl;
	}
};

class __base : public _base
{
//public:    // ���ܽ�����д����Ϊ�ڸ������Ѿ�������������� final ����Ĳ����Ա��̳С�������д��
//	virtual void func()  
//	{
//		cout << "this the 2nd derived class" << endl;
//	}
};

int main()
{
	_base a;
	__base b;
	Base* ptr = &a;
	ptr->func();
	ptr = &b;

	_base * ptr2 = &b;
	ptr->func();
	ptr2->func();
}
#endif