#include "iostream"
#include "string"
using namespace std;
#include<fstream> // for reading and writing 

int arr[5] = { 10, 3, 5, 4, 1 };
int ArraySum(int *inputarray, int location)//��ͺ�������
{
	int sum = 0;//�ۻ�����ʼ��
	for (int i = 0; i < location; i++) //��ǰ��Ϣ��λ��֮ǰ����ֵ���
	{
		sum += *inputarray;
		inputarray++;
	}
	return sum;
}
int main()
{  
	int tempVal = 0;
	tempVal = ArraySum(arr, 5);
	cout << tempVal << endl;
	system("pause");
	return 0;
}















































