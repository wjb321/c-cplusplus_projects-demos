#include "iostream"
#include "string"
using namespace std;
class Building
{
public:

// 1.ͨ����Ա�����������������
 //  Building operator+(Building &p)
	//{
	//	Building temp;
	//	temp.m_A = this->m_A + p.m_B;
	//	temp.m_B = this->m_B + p.m_B;
	//	return temp;
	//}
   Building(){}

   int m_A;
   int m_B;
};


//2.ͨ��ȫ�����������
Building operator+(Building &bui_1, Building &bui_2)
{
	Building temp;
	temp.m_A = bui_1.m_A + bui_2.m_B;
	temp.m_B = bui_1.m_B + bui_2.m_B;
	return temp;
}
void test01()
{  
	Building bui;
	bui.m_A = 10;
	bui.m_B = 10;

	Building bui_1;
	bui_1.m_A = 12;
	bui_1.m_B = 13;

	//1.��Ա��������
	//��Ա���������ر���
	//Building bui_2 = bui_1.operator+(bui_2);
	//��Ա�����ļ򻯺�����
	//Building bui_2 = bui + bui_1;

	//2.ȫ�ֺ�������
	//Building bui_2 = operator+(bui_1, bui);
	Building bui_2 = bui + bui_1;
	cout << "bui_2.m_a = " << bui_2.m_A << endl;
	cout << "bui_2.m_b = " << bui_2.m_B << endl;

}

int main()
{
	//test01();
	test01();
	system("pause");
	return 0;
}















































