#include <iostream>
#include <typeinfo> //check the type of data
#include <string>
using namespace std;
char  buffer[33];  //���ڴ��ת���õ�ʮ�������ַ������ɸ�����Ҫ���峤��
char* inttohex(int  aa);

int main()
{
    char* hex1;
    uint32_t dec = 7777777;
    uint8_t can_data[8];
    hex1 = inttohex(dec);
    cout << "hex " << hex1 <<" " <<"hex to int "<< stoi(hex1, nullptr, 16) << " " << typeid(hex1).name() << endl;
	system("pause");
	return 0;
}


char* inttohex(int  aa)
{
    static  int  i = 0;
    if (aa < 16)             //�ݹ�������� 
    {
        if (aa < 10)         //��ǰ��ת�����ַ������ַ��� 
            buffer[i] = aa + '0';
        else
            buffer[i] = aa - 10 + 'A';
        buffer[i + 1] = '\0';  //�ַ���������־ 
    }
    else
    {
        inttohex(aa / 16);   //�ݹ���� 
        i++;                 //�ַ�������+1 
        aa %= 16;            //���㵱ǰֵ
        if (aa < 10)         //��ǰ��ת�����ַ������ַ��� 
            buffer[i] = aa + '0';
        else
            buffer[i] = aa - 10 + 'A';
    }
    return  (buffer);
}
