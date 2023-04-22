#include <iostream>
using namespace std;

#define basicClass  0
#define classAccessModifier  0
#define inheritAndProtect    0
#define constructorAnddecon  0
#define copyconstructor      0
#define friendFunction       0
#define inlinefunction       0
#define overloading          0
#define polymorphism         0
#define Abstructofdata         0
#define encapulationofdata         0
#define interfaceofabstructclass         1
class printData
{
public:
	void print(int i) {
		cout << "����Ϊ: " << i << endl;
	}

	void print(double  f) {
		cout << "������Ϊ: " << f << endl;
	}

	void print(char c[]) {
		cout << "�ַ���Ϊ: " << c << endl;
	}
};
class Line
{
public:
	int getLength(void);
	Line(int len);             // �򵥵Ĺ��캯��
	Line(const Line& obj);      // �������캯��
	~Line();                     // ��������

private:
	int* ptr;
};

// ��Ա�������壬�������캯��
Line::Line(int len)
{
	cout << "���ù��캯��" << endl;
	// Ϊָ������ڴ�
	ptr = new int;
	*ptr = len;
}

Line::Line(const Line& obj)
{
	cout << "���ÿ������캯����Ϊָ�� ptr �����ڴ�" << endl;
	ptr = new int;
	*ptr = *obj.ptr; // ����ֵ
}

Line::~Line(void)
{
	cout << "�ͷ��ڴ�" << endl;
	delete ptr;
}
int Line::getLength(void)
{
	return *ptr;
}

void display(Line obj)
{
	cout << "line ��С : " << obj.getLength() << endl;
}


class Line1
{
public:
	void setLength(double len);
	double getLength(void);
	Line1();  // constructor
private:
	double length;
};

Line1::Line1(void)
{
	cout << "Object is being created" << endl;
}

void Line1::setLength(double len)
{
	length = len;
}

double Line1::getLength(void)
{
	return length;
}


class Box2
{
protected:
	double width2;
};

class SmallBox :Box2 // SmallBox ��������
{
public:
	void setSmallWidth(double wid);
	double getSmallWidth(void);
};

// ����ĳ�Ա����
double SmallBox::getSmallWidth(void)
{
	return width2;
}

void SmallBox::setSmallWidth(double wid)
{
	width2 = wid;
}

class Box1
{
public:
	double length2;
	void setWidth(double wid);
	double getWidth(void);

private:
	double width2;
};

// ��Ա��������
double Box1::getWidth(void)
{
	return width2;
}

void Box1::setWidth(double wid)
{
	width2 = wid;
}

class Box
{
public:
	double l;
	double b;
	double h;
	double get(void);
	void set(double len, double bre, double hei);
};

double Box::get(void)
{
	return l * b * h;
}

void Box::set(double len, double bre, double hei)
{
	l = len;
	b = bre;
	h = hei;
}


int main()
{
#if  basicClass
	Box box1;
	Box box2;
	Box box3;
	double volume = 0.0;
	box1.h = 5.0;
	box1.b = 5.0;
	box1.l = 3.2;

	box2.h = 5.0;
	box2.b = 9.0;
	box2.l = 9.2;

	volume = box1.h * box1.b * box1.l;
	cout << "the volume is" << volume << endl;

	volume = box2.h * box2.b * box2.l;
	cout << "the volume is" << volume << endl;

	box3.set(22.0, 3.0, 12.4);
	volume = box3.get();
	cout << "the box3 volume is " << volume << endl;
#elif classAccessModifier
	Box1 box;
	box.setWidth(10.3);
	box.length = 20;
	cout << "width of box " << box.getWidth() << endl;
#elif inheritAndProtect
//protected���ܱ�������Ա����������˽�г�Աʮ�����ƣ�����һ�㲻ͬ��protected���ܱ�������Ա�������ࣨ�����ࣩ���ǿɷ��ʵġ�
	SmallBox box;
	box.setSmallWidth(5.0);
	cout << "Width of box : " << box.getSmallWidth() << endl;
#elif constructorAnddecon  
	Line1 line;
	line1.setLength(6.0);
	cout << "Length of line : " << line1.getLength() << endl;
#elif copyconstructor
	Line line1(10);

	Line line2 = line1; // ����Ҳ�����˿������캯��

	display(line1);
	display(line2);
#elif  inlinefunction
//��������inline����������������Ŀ����Ϊ�˽�������к������õ�Ч�����⣬��ô˵�ɣ������ڱ����������ʱ�򣬱������������г��ֵ����������ĵ��ñ��ʽ�����������ĺ���������滻�������������ĺ���������������ʱ��ű����������ʵ���Ǹ��ռ���ۻ�ʱ���i��ʡ��������������һ�㶼��1 - 5�е�С��������ʹ����������ʱҪ����
//1.�����������ڲ�����ʹ��ѭ�����Ϳ�����䣻
//2.���������Ķ���������������������һ�ε���֮ǰ��
//3.��ṹ�����ڵ���˵���ڲ�����ĺ���������������

#elif overloading 
	printData pd;

	// �������
	pd.print(5);
	// ���������
	pd.print(500.263);
	// ����ַ���
	char c[] = "Hello C++";
	pd.print(c);
#endif
	return 0;
}