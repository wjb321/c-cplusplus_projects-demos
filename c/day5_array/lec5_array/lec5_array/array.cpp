// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// ConsoleApplication1.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
#if 0
	int arr[5];
	arr[0] = 2;
	arr[1] = 3;
	arr[2] = 4;
	arr[3] = 5;
	arr[4] = 6;
  for (int i = 0; i < 5; i++)
	{
		printf("arr values are: %d \r\n", arr[i]);
	}

#endif 
#if 0  // �����������
  //scanf ͨ�������ʽ��double����lf�� ����ӡ��ʱ�����ʽ���Ի��ɻ���1f����f�����ԡ�
 double arr[5];

 //�������ʱ�������ȽϷ�ʱ���˴����ñ�ķ��������бȽϺ��ʣ� ����֮���ǽ�����Ӧ�ĳ�ʼ��
  for (int i = 0; i < 5; i++){
	  printf("please input the score:", i + 1);
	  //getchar();
	  scanf("%lf", &arr[i]);
	  //getchar();
  }
  float score = 0.0;
  double max, min;
  max = min = arr[0];
  for (int i = 0; i < 5; i++)
  {
	  printf("%.3f", arr[i]);
	  printf("\n");
	  score += arr[i];
	  if (max < arr[i])
	  {
		  max = arr[i];
	  }
	  min = ((min > arr[i]) ? arr[i] : min); // a b ? a : n 
	  //if (min > arr[i])
	  //{
		 // min = arr[i];
	  //}
  }
  //for (int i = 0; i < 5; i++)
  //{
	 // score += arr[i];
  //}
  printf("the score and avarage is %.3f, %.3f, %g, %g \r\n", score, score/(sizeof(arr)/sizeof(arr[0])), max, min);

  while (1);
#endif

#if 0  // ����Խ�絼�±�ı���������ֵ, �˴�������Ĳ���������ǰ������ĸı�,��ΪԽ��Ĳ��ɼ�⣬�����Լ���д�����ʱ���ֹԽ�緢��
  int n = 666, arr[5] = { 1, 2, 3, 4, 5 };
  printf("%d, %d", &n, &arr);
  arr[7] = 999;
  printf("the n value is :%d", n); // n��ֵ�ᱻ����
#endif

  //vs �����������־��ʹ�����ģ� �ַ���
  //ͨ��ascii �Ϳ��Ա������Ӧ�Ĳ������������ĵĲ������Ƚ϶࣬����Ҫ������Ӧ����չ�����Զ���
  //256��ascii���ǲ����ģ�������Ҫ�����ַ�������һ���ַ������Դ˴���unicode,��֮Ϊ���ֽ��ַ���
#if 1 

  wchar_t t = '��';
  char c = '��';
  printf("%d%c\n", c, c);
  printf("%d%c\n", t, t); //54992 -> bin 1101 0110(214) 1101 0000(208) 
  printf("%c%c\n", 214, 208);//'��'

  //unsigned char str1[2] = "��";  // �˲��ֵı���������ʦ�ĵط�û���⣬�����ҵĵط����������
  //printf("%d,%d\n", str1[0], str1[1]);
#endif
 return 0;
}



