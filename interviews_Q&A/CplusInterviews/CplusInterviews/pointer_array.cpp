#include <iostream>
#include <string>
using namespace std;

#define DebugQuestion48                     0
#define DebugQuestion49                     0
#define DebugQuestion50_pointer             0
#define DebugQuestion51_temperaryVariable   0
#define inputXwithOutputDecimal             0
#define lambdaTest_54                       0
#define structSizeWithdiffVarOrder          1
#if DebugQuestion51_temperaryVariable
void bar(const string& s); // bar(string &s)
#endif
class A
{
public:
	A() 
	{cout << "hello the world" << endl; }
	void B(void)
	{cout << "i love you" << endl;
	}
};
int main()
{   
#if DebugQuestion48
	char str1[] = "abc";
	char str2[] = "abc";
	const char str3[] = "abc";
	const char str4[] = "abc";
	const char * str5 = "abc";
	const char * str6 = "abc";//ָ����ֵָ�ǳ������������Ҫ����const
	//char* str7 = "abc"; //�ᷢ������ͨ��ָ��str7���޸�ָ������Ӧ�ĳ��������ǲ���������ۡ�
	//char* str8 = "abc";


	cout << (str1 == str2) << endl; // 0: �����ǲ���ͬ�ģ�ֻ��ָ����ָ��������һ����
	cout << (str3 == str4) << endl; // 0
	cout << (str5 == str6) << endl; // 1
	//cout << (str7 == str8) << endl; // 1
#elif DebugQuestion49  // conclustion: 
	A(); // ����������û�ж��󣬹��캯��ѹ������Ҫ��Ķ��������ã� �����ʽ������������Ķ���anonymity��
	A a = A();//define the object a and construct it
	//B(); //error
	a.B(); // then the function can be called

#elif DebugQuestion50_pointer
	void call_each(void (**a)(void), int size)
	{
		int n = size;
		while (--n >= 0)
		{
			void (*p)(void) = *a++;
			if (p)
			(*p)();
		}
	}
	//1) ��� **a = *a[] -> void (**a)(void) = void *a[](void) (a�����飬ÿ��Ԫ����ָ�����ͣ������е�ÿ��Ԫ��������void (*)(void), it is 
	//function pointer )
	// 2) *a++, ++ has higher poriority, normallt b =  a++, first b = a, then do a++, so void (*p)(void) = *a++; means assign function pointer
	// to function pointer p, then a function pointer adress adds, and assign again
	// the final aim is call the function pointer void (*a)(void) by checking if the function array is not empty 
#elif DebugQuestion51_temperaryVariable   
// question point:
// function initialized with string: hello the towrld is the temperary variable, which is a const value, while the fuction decalration is the 
// reference of the variable, which can change the variable, thisi is conflict with the const definition, so below is the error
// solution:
// change the reference of the variable in function with a const: void bar(const &s) or change the function to void(string && s)
	bar("hello the towrld");
#elif inputXwithOutputDecimal

#elif lambdaTest_54
	int a = 10;
	auto sum = [a](int b) {cout << a + b << endl;}; //transform a into the function
	auto sum1= [=](int b) {cout << a + b << endl;}; //get the copy from external value, transform according to value(only read)
	auto sum2= [a](int b) {cout << a + b << endl;}; //transform a into the function(reference, a is the local variable)
	sum(20);
	sum1(20);
	sum2(20);
#elif structSizeWithdiffVarOrder
	//the default assemblor byte is 8, then it will chose the minimal one of the variables and default one, find the smaller one's integal 
	//multiplesm for example: int a: 4 bytes, default:8, then: smaller one is 4, so the location of this a locates at 4 times multiple.
	//conclusion:
	//the variables with small space occupied, should better put in front
	// char a;   char a;   // ǰ����Ը��ã�ռ�ñȽ�С���ڴ棬�ڽṹ����
	// char b;   int  b;
	// int  c;   char b;

#endif
	return 0;
}

#if DebugQuestion51_temperaryVariable 
void bar(const string &s) // bar(string &s)
{
	cout << s << endl;
}
#endif
