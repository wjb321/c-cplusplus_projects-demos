// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// ConsoleApplication1.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"
#include <stdio.h>
int main()
{
	int arr[5];
	arr[0] = 2;
	arr[1] = 3;
	arr[2] = 4;
	arr[3] = 5;
	arr[4] = 6;

	for (int i = 0; i < 5; i++)
	{
		printf("arr values are: %d /r/n", arr[i]);
	}

	return 0;
}
// TODO:  �� STDAFX.H ��
// �����κ�����ĸ���ͷ�ļ����������ڴ��ļ�������
