#include"iostream"
using namespace std;
const int MAX = 3;
int main()
{

	int a = 20;  // ����һ������
	int * p; // ����һ��ָ������
	p = &a;  // ָ�뱣������ĵ�ַ

	cout << "&a: " << &a << endl;
	cout << "p: " << p << endl;  // p == &a
	cout << "*p: " << *p << endl;  //ָ��ָ�򱣴��ַ������

	//1) null pointer
	int * ptr1 = NULL;  // ���������ϵͳ��������ʵ�ַ0���ڴ棬��Ϊ�ǲ���ϵͳ������
	cout << "ptr1 is " << ptr1 << endl;

	//2��
	int var[MAX] = {10, 100, 200};
	int *ptr;
    
	ptr = var;
	for (int i = 0; i < MAX;  i++)
	{
		cout << "address of var [" << i << "]";
		cout << ptr << endl;

		cout << "value of var[" << i << "] = ";
		cout << *ptr << endl;
		ptr++;
	}
	return 0;

}