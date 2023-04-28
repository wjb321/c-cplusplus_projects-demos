#include <iostream>
#include <typeinfo> //check the type of data
#include <string>
using namespace std;


int hexCharToInt1(char c) {
    if (c >= '0' && c <= '9') {
        std::cout << "return " << std::hex << typeid(c - '0').name() << " Value " << c - '0' << std::endl;
        return c - '0';
    }
    else if (c >= 'A' && c <= 'F') {
        std::cout << "return " << std::hex << typeid(c - 'A' + 10).name() << " Value " << c - 'A' + 10 << std::endl;
        return c - 'A' + 10;
    }
    else if (c >= 'a' && c <= 'f') {
        std::cout << "return " << std::hex << typeid(c - 'a' + 10).name() << " Value " << c - 'a' + 10 << std::endl;
        return c - 'a' + 10;
    }
    else {
        return 0; // �Ƿ��ַ�������0
    }
}

// ��һ������Ϊ6��16�����ַ�����ת��Ϊ��Ӧ��32λ16������
uint32_t hexArrayToUInt321(char hexArray[]) {
    uint32_t result = 0;
    for (int i = 0; i < 6; i++) {
        int hexValue = hexCharToInt1(hexArray[i]);
        result |= (hexValue << ((5 - i) * 4)); // ��ÿ��16�����ַ�ת��Ϊ4λ����������Ȼ�����ƶ�Ӧ��λ��
    }
    return result;
}
int main1()
{
    char hexArray[6] = { 'A', '6', '3', 'E', 'F', 'D' };
    uint32_t value = hexArrayToUInt321(hexArray);
    std::cout << "format of the data " << std::hex << typeid(value).name() << "Value in hex: 0x " <<value << std::endl;

    return 0;
}